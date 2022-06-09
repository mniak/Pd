#include <m_pd.h>
#include "PitchClass.h"

extern "C" void g_toggle_setup(void);

extern "C" void libmus_setup(void)
{
    PitchClass::Setup();
    g_toggle_setup();
}