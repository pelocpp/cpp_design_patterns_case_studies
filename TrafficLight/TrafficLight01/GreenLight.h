﻿namespace TrafficLight01
{
    class GreenLight : public ITrafficLight
    {
    public:
        void change(TrafficLight* light) override;
        void reportState() const override;
    };
}
