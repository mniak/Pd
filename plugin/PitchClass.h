#pragma once

#include <m_pd.h>

namespace PitchClass
{
    typedef struct
    {
        t_object x_obj;
    } Object;

    void *New(void);
    void Bang(Object *self);
    void Setup();
}
