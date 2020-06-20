// ===========================================================================
// ListView.h
// ===========================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "ListView.h"

ListView::ListView() {}

void ListView::setColumns(int cols) {
    m_cols = cols;
    m_titles.resize(m_cols, std::string(""));
}

void ListView::setColumnHeader(int col, std::string title) {
    if (col >= m_cols) {
        std::ostringstream oss;
        oss << "Invalid title column: " << col << "!";
        throw std::out_of_range(oss.str());
    }

    m_titles.at(col) = title;
}

// ===========================================================================
// End-of-File
// ===========================================================================
