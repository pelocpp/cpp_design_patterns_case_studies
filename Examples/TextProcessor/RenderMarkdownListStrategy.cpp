// ===========================================================================
// RenderMarkdownListStrategy.cpp
// ===========================================================================

#include <iostream>
#include <sstream>
#include <string>

#include "RenderListStrategy.h"
#include "RenderMarkdownListStrategy.h"

void RenderMarkdownListStrategy::add(std::ostringstream& oss, const std::string& item) {
    oss << "  * " << item << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
