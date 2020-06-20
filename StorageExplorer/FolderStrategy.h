// ===========================================================================
// FolderStrategy.h
// ===========================================================================

#pragma once

class FolderStrategy : public ExplorationStrategy
{
public:
    FolderStrategy() = default;
    ~FolderStrategy() = default;

    void explore(const std::string& path) override;
    void printResults() override;
};

// ===========================================================================
// End-of-File
// ===========================================================================
