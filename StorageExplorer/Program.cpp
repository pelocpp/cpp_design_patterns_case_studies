// ===========================================================================
// Program.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <filesystem>

#include "ExplorationObserver.h"
#include "ExplorationStrategy.h"

// TODO: Hmm, verwenden wir da shared oder unique ptr ?!?!?!?

// ===========================================================================

void testStategyPattern() {

    // initialization section: setup strategy
    std::unique_ptr<IExplorationStrategy> explorer;
    std::unique_ptr<IExplorationStrategy> folderStrategy = std::make_unique<FolderStrategy>();
    std::unique_ptr<IExplorationStrategy> fileTypeStrategy = std::make_unique<FileTypeStrategy>();


    // initialization section: setup observer
    std::shared_ptr<IExplorationObserver> concreteObserver = std::make_shared<ConcreteExplorationObserver>();

    folderStrategy->attach(concreteObserver);

    // choose strategy
    int input = 0;
    switch (input)
    {
    case 0:
        explorer = std::move(folderStrategy);
        break;

    case 1:
        explorer = std::move(fileTypeStrategy);
        break;

    default:
        break;
        // more strategies ....
    }

    // execute the algorithm
    constexpr const char* path =
        R"(C:\Development\GitRepositoryCPlusPlus\Cpp_DesignPatterns)";

    explorer->explore(path);
    explorer->printResults();
}


int main() {
    std::cout << "Cpp Design Patterns Case Studies: Storage Explorer" << std::endl;

    testStategyPattern();
    return 0; 
}

// ===========================================================================
// End-of-File
// ===========================================================================
