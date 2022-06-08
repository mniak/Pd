#include <m_pd.h>
#include "PitchClass.h"

static t_class *PitchClass_class;

typedef struct _PitchClass {
  t_object  x_obj;
} t_PitchClass;


void PitchClass_bang(t_PitchClass *x)
{
  post("Hello world !!");
}

void *PitchClass_new(void)
{
  t_PitchClass *x = (t_PitchClass *)pd_new(PitchClass_class);

  return (void *)x;
}


extern "C" void libmus_setup(void)
{
    post("libmus initialized");

    // PitchClass::Class = class_new(
    //     gensym("PitchClass"),
    //     (t_newmethod)PitchClass::New,
    //     NULL,
    //     sizeof(PitchClass::Object),
    //     CLASS_DEFAULT,
    //     A_NULL);
    // class_addbang(PitchClass::Class, PitchClass::Bang);

    PitchClass_class = class_new(gensym("PitchClass"),
                                 (t_newmethod)PitchClass_new,
                                 0, sizeof(t_PitchClass),
                                 CLASS_DEFAULT, A_NULL);

    class_addbang(PitchClass_class, PitchClass_bang);

    post("PitchClass initialized");
}