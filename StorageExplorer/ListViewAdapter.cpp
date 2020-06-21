// ===========================================================================
// ListViewAdapter.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iterator>
#include <filesystem>
#include <memory>

#include "IExplorationObserver.h"
#include "IExplorationStrategy.h"
#include "ExplorationObserver.h"

#include "ExplorationStrategy.h"

#include "ListView.h"
#include "ListViewAdapter.h"

// ===========================================================================

// function prototypes

// ===========================================================================

ListViewAdapter::ListViewAdapter() 
{
    m_listView = std::make_shared<ListView>();
}

ListViewAdapter::~ListViewAdapter()
{
}

void ListViewAdapter::update(const std::string&)
{
    std::cout << "Yeahhhhhhhhhhhhhhhh" << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
