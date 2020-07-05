namespace TrafficLight02
{
    class RedLight : public ITrafficLight
    {
    public:
        void change(TrafficLight& light) override;
        void reportState() const override;
    };
}
