#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "GreenLight.h"
#include "RedLight.h"

namespace TrafficLight03
{
    std::shared_ptr<RedLight> RedLight::m_instance{ nullptr };

    std::shared_ptr<RedLight> RedLight::getInstance() {
        if (m_instance == nullptr) {
            m_instance = std::shared_ptr<RedLight>(new RedLight{  });
        }

        return m_instance;
    }

    void RedLight::change(TrafficLight& light)
    {
        light.setState(GreenLight::getInstance());
    }

    void RedLight::reportState() const
    {
        std::cout << "Red Light" << std::endl;
    }
}
