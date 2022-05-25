lib.name = mniak
class.sources = lib/mniak.c
# datafiles = myclass1-help.pd myclass2-help.pd README.txt LICENSE.txt
ldflags = lib/mniak_cpp.o

PDLIBDIR=externals/

all: externals/mniak.pd_linux

include pd-lib-builder/Makefile.pdlibbuilder

# mniak.pd_linux: lib/mniak_cpp.o post
mniak.pd_linux: post
externals/mniak.pd_linux: mniak.pd_linux
	mv mniak.pd_linux externals/mniak.pd_linux


# lib/mniak_cpp.h: lib/mniak_cpp.o
lib/mniak_cpp.o: lib/mniak.cpp
	g++ -c -std=c2x -o lib/mniak_cpp.o lib/mniak.cpp

test-on-pd: lib/mniak.pd_linux test-hello.pd
	pd test-hello.pd

test-c: lib/test_c.exe
	lib/test_c.exe

lib/test_c.exe: lib/test.c lib/mniak_cpp.o lib/mniak.h
	gcc lib/test.c -o lib/test_c.exe lib/mniak_cpp.o 

	