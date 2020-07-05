namespace TrafficLight02
{
    class TrafficLight
    {
    private:
        std::shared_ptr<ITrafficLight> m_state;

    public:
        void setState(std::shared_ptr<ITrafficLight> state);
        std::shared_ptr<ITrafficLight> getState();

        void change();
        void reportState();
    };
}
