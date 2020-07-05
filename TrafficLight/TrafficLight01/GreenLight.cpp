#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "GreenLight.h"
#include "YellowLight.h"

namespace TrafficLight01
{
    void GreenLight::change(TrafficLight* light)
    {
        light->setState(new YellowLight());
    }

    void GreenLight::reportState() const
    {
        std::cout << "Green Light" << std::endl;
    }
}
