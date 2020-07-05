namespace TrafficLight03
{
    class YellowLight : public ITrafficLight
    {
    private:
        YellowLight() noexcept {};

        static std::shared_ptr<YellowLight> m_instance;

    public:
        static std::shared_ptr<YellowLight> getInstance();

    public:
        void change(TrafficLight& light) override;
        void reportState() const override;
    };
}
