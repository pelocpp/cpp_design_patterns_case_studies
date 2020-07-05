namespace TrafficLight03
{
    class RedLight : public ITrafficLight
    {
    private:
        RedLight() noexcept {};

        static std::shared_ptr<RedLight> m_instance;

    public:
        static std::shared_ptr<RedLight> getInstance();

    public:
        void change(TrafficLight& light) override;
        void reportState() const override;
    };
}
