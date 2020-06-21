// ===========================================================================
// ExplorationObserver.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>

#include "IExplorationObserver.h"
#include "IExplorationStrategy.h"
#include "ExplorationObserver.h"

#include "ExplorationStrategy.h"
#include "FileTypeStrategy.h"
#include "FolderStrategy.h"

// ===========================================================================

void ExplorationObserver::update(const std::string&) {
    std::cout << "DoneDoneDone." << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
