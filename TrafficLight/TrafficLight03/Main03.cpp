﻿#include <iostream>
#include <string>
#include <memory>
#include <thread> 
#include <chrono>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "RedLight.h"

void test_trafficlight_03()
{
    using namespace TrafficLight03;

    std::cout << "TrafficLight: Variant 02 (Shared-Pointer & Singleton)" << std::endl;

    TrafficLight trafficLight;
    trafficLight.setState(RedLight::getInstance());
    trafficLight.reportState();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (true)
    {
        trafficLight.change();
        trafficLight.reportState();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
