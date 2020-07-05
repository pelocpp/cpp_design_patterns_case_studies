namespace TrafficLight01
{
    class TrafficLight
    {
    private:
        ITrafficLight* m_state;

    public:
        void setState(ITrafficLight* state);
        ITrafficLight* getState();

        void change();
        void reportState() const;
    };
}
