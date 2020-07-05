namespace TrafficLight03
{
    class TrafficLight;

    class ITrafficLight
    {
    public:
        virtual void change(TrafficLight& light) = 0;
        virtual void reportState() const = 0;
    };
}
