// ===========================================================================
// ExplorationStrategy.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <map>
#include <list>
//#include <iterator>
//#include <filesystem>
#include <memory>

#include "IExplorationObserver.h"
#include "IExplorationStrategy.h"
#include "ConcreteExplorationObserver.h"

#include "ExplorationStrategy.h"
//#include "FileTypeStrategy.h"
//#include "FolderStrategy.h"

/**
* observer management methods
*/
void ExplorationStrategy::attach(std::shared_ptr<IExplorationObserver> observer) {
    m_list_observers.push_back(observer);
}

void ExplorationStrategy::detach(std::shared_ptr<IExplorationObserver> observer) {
    m_list_observers.remove(observer);
}

void ExplorationStrategy::onFinish() {
    std::cout << "got onFinish" << std::endl;
    std::list<std::shared_ptr<IExplorationObserver>>::iterator iterator = m_list_observers.begin();
   // howManyObserver();
    while (iterator != m_list_observers.end()) {
        std::shared_ptr<IExplorationObserver> ptr = *iterator;
        ptr->onFinish("On Finished");
        ++iterator;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
