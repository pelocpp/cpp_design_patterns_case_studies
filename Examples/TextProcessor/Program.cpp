// ===========================================================================
// Program.cpp
// ===========================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

#include "RenderListStrategy.h"
#include "RenderHtmlListStrategy.h"
#include "RenderMarkdownListStrategy.h"
#include "RenderTextProcessor.h"

int main ()
{
    RenderTextProcessor processor;

    // 'markdown' strategy (should be created externally to client)
    processor.setOutputFormat(std::make_unique<RenderMarkdownListStrategy>());
    processor.appendList({ "foo", "bar", "baz" });
    std::cout << processor.toString() << std::endl;

    // 'html' strategy (should be created externally to client)
    processor.clear();
    processor.setOutputFormat(std::make_unique<RenderHtmlListStrategy>());
    processor.appendList({ "FOO", "BAR", "BAZ" });
    std::cout << processor.toString() << std::endl;

    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
