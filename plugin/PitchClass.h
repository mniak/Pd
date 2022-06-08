#pragma once

#include <m_pd.h>

namespace PitchClass
{
  static t_class *Class;
  typedef struct
  {
    t_object x_obj;
  } Object;
  void Bang(Object *self);
  void *New(void);

}
