namespace TrafficLight02
{
    class YellowLight : public ITrafficLight
    {
    public:
        void change(TrafficLight& light) override;
        void reportState() const override;
    };
}
