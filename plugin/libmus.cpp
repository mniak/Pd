#include <m_pd.h>
#include "PitchClass.h"

extern "C" {
    void libmus_setup(void);
}

#define REGISTER_PATCH(name) auto name##_class = class_new(gensym(#name), (t_newmethod)name##_new, NULL, sizeof(t_##name), CLASS_DEFAULT, (t_atomtype)0)


void libmus_setup(void){
    PitchClass::Class = class_new(
        gensym("PitchClass"),
        (t_newmethod)PitchClass::New,
        NULL,
        sizeof(PitchClass::Object),
        CLASS_DEFAULT,
        A_NULL);
    class_addbang(PitchClass::Class, PitchClass::Bang);
}

