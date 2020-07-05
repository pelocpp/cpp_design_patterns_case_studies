#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "GreenLight.h"
#include "YellowLight.h"

namespace TrafficLight02
{
    void GreenLight::change(TrafficLight& light)
    {
        light.setState(std::make_shared<YellowLight>());
    }

    void GreenLight::reportState() const
    {
        std::cout << "Green Light" << std::endl;
    }
}
