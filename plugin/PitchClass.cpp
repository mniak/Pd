#include "PitchClass.h"
#include <libmus/libmus.h>
#include <cstdlib>
#include <cstdio>

namespace PitchClass
{
    static t_class *Class;
    typedef struct
    {
        t_object internal;
        t_outlet *outlet1;
        libmus::PitchClass *pc;
    } Object;

    void *New(void)
    {
        auto *self = (Object *)pd_new(Class);
        self->outlet1 = outlet_new(&self->internal, &s_bang);
        self->pc = new libmus::PitchClass();
        return (void *)self;
    }

    void Free(Object *self)
    {
        delete (self->pc);
    }

    void Bang(Object *self)
    {
        char buffer[50];
        sprintf(buffer, "PitchClass %d %d!", self->pc->GetStep(), self->pc->GetAlteration());
        post(buffer);
        outlet_bang(self->outlet1);
    }

    void Setup()
    {
        Class = class_new(
            gensym("PitchClass"),
            (t_newmethod)New,
            (t_method)Free,
            sizeof(Object),
            CLASS_DEFAULT, A_NULL);

        class_addbang(Class, Bang);
    }
}
