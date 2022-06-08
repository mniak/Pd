#include <m_pd.h>
#include "PitchClass.h"

namespace PitchClass
{
    void Bang(Object *self)
    {
        post("Hello from PitchClass!");
    }
    void *New(void)
    {
        post("New class PitchClass");
        Object *self = (Object *)pd_new(Class);
        return (void *)self;
    }
}

extern "C" void libmus_setup(void)
{
    PitchClass::Class = class_new(
        gensym("PitchClass"),
        (t_newmethod)PitchClass::New,
        0, sizeof(PitchClass::Object),
        CLASS_DEFAULT, A_NULL);

    class_addbang(PitchClass::Class, PitchClass::Bang);
}