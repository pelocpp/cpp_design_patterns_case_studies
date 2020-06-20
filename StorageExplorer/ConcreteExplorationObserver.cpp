// ===========================================================================
// ConcreteExplorationObserver.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>

#include "IExplorationObserver.h"
#include "IExplorationStrategy.h"
#include "ConcreteExplorationObserver.h"

#include "ExplorationStrategy.h"
#include "FileTypeStrategy.h"
#include "FolderStrategy.h"

// ===========================================================================

void ConcreteExplorationObserver::onFinish(const std::string&) {
    std::cout << "DoneDoneDone." << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
