#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "RedLight.h"
#include "YellowLight.h"

namespace TrafficLight02
{
    void YellowLight::change(TrafficLight& light)
    {
        light.setState(std::make_shared<RedLight>());
    }

    void YellowLight::reportState() const
    {
        std::cout << "Yellow Light" << std::endl;
    }
}
