#include <m_pd.h>
#include "PitchClass.h"


extern "C" void libmus_setup(void)
{
    PitchClass::Setup();
}