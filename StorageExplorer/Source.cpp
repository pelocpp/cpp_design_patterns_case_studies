#include <iostream>
#include <string>

class ExplorationStrategy {
   // public virtual void Explore(...) {}
    virtual ~ExplorationStrategy() {}
    virtual void explore() const = 0;
};

