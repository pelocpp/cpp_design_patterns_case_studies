// ===========================================================================
// RenderTextProcessor.cpp
// ===========================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

#include "RenderListStrategy.h"
#include "RenderMarkdownListStrategy.h"
#include "RenderHtmlListStrategy.h"
#include "RenderTextProcessor.h"

void RenderTextProcessor::setOutputFormat(std::unique_ptr<RenderListStrategy>&& format) {
    m_format = std::move(format);
}

void RenderTextProcessor::appendList(const std::vector<std::string>& items) {
    m_format->start(m_oss);

    for (const auto& item : items)
        m_format->add(m_oss, item);

    m_format->end(m_oss);
}

std::string RenderTextProcessor::toString() const {
    return m_oss.str();
}

void RenderTextProcessor::clear() {
    m_oss.str("");
    m_oss.clear();
}

// ===========================================================================
// End-of-File
// ===========================================================================
