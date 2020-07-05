#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

namespace TrafficLight01
{
    void TrafficLight::setState(ITrafficLight* state)
    {
        m_state = state; 
    }

    ITrafficLight* TrafficLight::getState()
    {
        return m_state; 
    }

    void TrafficLight::change()
    {
        m_state->change(this);
    }

    void TrafficLight::reportState() const
    {
        m_state->reportState();
    }
}
