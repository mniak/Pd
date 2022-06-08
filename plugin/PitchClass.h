#pragma once

#include <m_pd.h>

namespace PitchClass
{
  static t_class *Class;
  typedef struct _Object
  {
  } Object;

  void *New(void);
  void Bang(Object *self);
}