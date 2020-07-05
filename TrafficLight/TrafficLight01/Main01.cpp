#include <iostream>
#include <string>
#include <thread> 
#include <chrono>

#include "ITrafficLight.h"
#include "TrafficLight.h"

#include "RedLight.h"

void test_trafficlight_01()
{
    using namespace TrafficLight01;

    std::cout << "TrafficLight: Variant 01 (Raw-Pointer)" << std::endl;

    TrafficLight trafficLight;
    trafficLight.setState(new RedLight());
    trafficLight.reportState();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (true)
    {
        trafficLight.change();
        trafficLight.reportState();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}