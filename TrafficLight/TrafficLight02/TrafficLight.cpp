#include <iostream>
#include <string>
#include <memory>

#include "ITrafficLight.h"
#include "TrafficLight.h"

namespace TrafficLight02
{
    void TrafficLight::setState(std::shared_ptr<ITrafficLight> state)
    {
        m_state = state; 
    }

    std::shared_ptr<ITrafficLight> TrafficLight::getState()
    {
        return m_state; 
    }

    void TrafficLight::change()
    {
        m_state->change(*this);
    }

    void TrafficLight::reportState()
    {
        m_state->reportState();
    }
}
