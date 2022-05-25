lib.name = externals/mniak
class.sources = lib/mniak.cpp
# ldflags = lib.o

DESTDIR=externals/
cflags = -std=c++20 -fmodules-ts

include pd-lib-builder/Makefile.pdlibbuilder

pre:
	g++ -std=c++20 -fmodules-ts -x c++-system-header string
	
post: pre $(executables)
	mv mniak.pd_linux externals/


test-pd: all test-hello.pd
	pd test-hello.pd