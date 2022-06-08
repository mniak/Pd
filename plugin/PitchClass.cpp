#include "PitchClass.h"
#include <libmus/libmus.h>

namespace PitchClass
{
    static t_class *Class;

    void Setup()
    {
        post("libmus_setup");
        Class = class_new(
            gensym("PitchClass"),
            (t_newmethod)New,
            0, sizeof(Object),
            CLASS_DEFAULT, A_NULL);

        class_addbang(Class, Bang);
    }

    void *New(void)
    {
        post("New");
        auto *self = (Object *)pd_new(Class);
        return (void *)self;
    }

    void Bang(Object *self)
    {
        post("Hello from PitchClass 7!");
    }
}
