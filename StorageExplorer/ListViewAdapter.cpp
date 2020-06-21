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
#include "ConcreteExplorationObserver.h"

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


void ListViewAdapter::explore(const std::string& path)
{

}

void ListViewAdapter::printResults()
{

}

// ===========================================================================
// End-of-File
// ===========================================================================
