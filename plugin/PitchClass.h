#pragma once

#include <m_pd.h>

namespace PitchClass
{
    typedef struct
    {
        t_object internal;
        int number;
    } Object;

    void *New(void);
    void Bang(Object *self);
    void Setup();
}
