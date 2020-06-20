// ===========================================================================
// ExplorationStrategy.h
// ===========================================================================

class IExplorationObserver {
public:
    virtual ~IExplorationObserver() {};
    virtual void onFinish(const std::string&) = 0;
};

class ConcreteExplorationObserver : public IExplorationObserver {
public:
    void onFinish(const std::string&) override;
};

// ===========================================================================
// End-of-File
// ===========================================================================
