// ===========================================================================
// FileTypeStrategy.h
// ===========================================================================

#pragma once

/* This class retrieves total file size under a given path then fill
 * ExplorationResult hash table containing file type and the total size
 * of each file type.
 */
class FileTypeStrategy : public ExplorationStrategy
{
public:
    FileTypeStrategy() = default;
    ~FileTypeStrategy() = default;

    void explore(const std::string& path) override;
    void printResults() override;
};

// ===========================================================================
// End-of-File
// ===========================================================================
