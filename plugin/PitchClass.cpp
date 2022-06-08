#include "PitchClass.h"
#include <libmus/libmus.h>
#include <cstdlib>
#include <cstdio>

namespace PitchClass
{
    static t_class *Class;

    void Setup()
    {
        Class = class_new(
            gensym("PitchClass"),
            (t_newmethod)New,
            0, sizeof(Object),
            CLASS_DEFAULT, A_NULL);

        class_addbang(Class, Bang);
    }

    void *New(void)
    {
        auto *self = (Object *)pd_new(Class);
        self->number = rand();
        return (void *)self;
    }

    void Bang(Object *self)
    {
        char buffer [50];
        sprintf(buffer, "Hello from PitchClass %d!", self->number);
        post(buffer);
    }
}
