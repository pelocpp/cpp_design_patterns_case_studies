// ===========================================================================
// IExplorationStrategy.h
// ===========================================================================

#pragma once

class IExplorationStrategy {
public:
    virtual void explore(const std::string& path) = 0;
    virtual void printResults() = 0;

    virtual void attach(std::shared_ptr<IExplorationObserver>) = 0;
    virtual void detach(std::shared_ptr<IExplorationObserver>) = 0;
    virtual void onFinish() = 0;
};

// ===========================================================================
// End-of-File
// ===========================================================================
