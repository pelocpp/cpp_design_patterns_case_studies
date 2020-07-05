namespace TrafficLight01
{
    class RedLight : public ITrafficLight
    {
    public:
        void change(TrafficLight* light) override;
        void reportState() const override;
    };
}
