#include <iostream>
#include <string>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "GreenLight.h"
#include "RedLight.h"

namespace TrafficLight01
{
    void RedLight::change(TrafficLight* light)
    {
        light->setState(new GreenLight());
    }

    void RedLight::reportState() const 
    {
        std::cout << "Red Light" << std::endl;
    }
}
