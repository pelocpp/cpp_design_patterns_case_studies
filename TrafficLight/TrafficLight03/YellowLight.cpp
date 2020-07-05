﻿#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "RedLight.h"
#include "YellowLight.h"

namespace TrafficLight03
{
    std::shared_ptr<YellowLight> YellowLight::m_instance{ nullptr };

    std::shared_ptr<YellowLight> YellowLight::getInstance() {
        if (m_instance == nullptr) {
            m_instance = std::shared_ptr<YellowLight>(new YellowLight{  });
        }

        return m_instance;
    }

    void YellowLight::change(TrafficLight& light)
    {
        light.setState(RedLight::getInstance());
    }

    void YellowLight::reportState() const
    {
        std::cout << "Yellow Light" << std::endl;
    }
}
