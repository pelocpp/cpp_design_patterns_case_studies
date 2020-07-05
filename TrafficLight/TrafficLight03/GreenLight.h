namespace TrafficLight03
{
    class GreenLight : public ITrafficLight
    {
    private:
        GreenLight() noexcept {};

        static std::shared_ptr<GreenLight> m_instance;

    public:
        static std::shared_ptr<GreenLight> getInstance();

        void change(TrafficLight& light) override;
        void reportState() const override;
    };
}
