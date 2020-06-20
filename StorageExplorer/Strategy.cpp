// ===========================================================================
// Strategy.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <filesystem>
#include <memory>

#include "ExplorationObserver.h"
#include "ExplorationStrategy.h"

// ===========================================================================

void FileTypeStrategy::explore(const std::string& path) 
{
    std::filesystem::path p(path);
    std::filesystem::directory_iterator start(p);
    std::filesystem::directory_iterator end;

    auto entriesLambda = [this](const std::filesystem::directory_entry& entry) mutable {

        const std::filesystem::path file = entry.path().filename();
        const std::string name{ file.string() };
        const std::string ext{ file.extension().string() };
      
        //std::cout << "Entry: " << " = " << name << '\n';
        //std::cout << "Extension: [" << ext << "]" << '\n';

        if (std::filesystem::is_regular_file(entry)) {

            if (ext.empty()) {
                // to be done - no extension !!!
                return;
            }

            uintmax_t size = 0;
            try
            {
                size = file_size(entry);
            }
            catch (std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            }

            if (m_explorationResult.count(ext) > 0) {
                m_explorationResult[ext] = m_explorationResult[ext] + size;
            }
            else {
                m_explorationResult[ext] = size;
            }
        }
        else if (std::filesystem::is_directory(entry)) {

            // do the same process to the subdirectories

            //  std::filesystem::directory_entry subEntry { entry };
            std::string s = entry.path().string();

            // skip - at least for the moment - .git sub directory
            if (s == std::string(".git") or s == std::string(".git")) {
                return;
            }

            explore(s);
        }
    };

    std::for_each(start, end, entriesLambda);
}

void FileTypeStrategy::printResults() {

    std::for_each(
        std::begin(m_explorationResult), 
        std::end(m_explorationResult),
        [](const std::pair<std::string, uintmax_t>& entry){
            std::cout << "Ext: " << entry.first << " - Total Sizes: " << entry.second << '\n';
        }
    );
}

// ===========================================================================

inline bool endsWith(std::string const& value, std::string const& ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

uintmax_t getFolderSize(std::string path)
{
    uintmax_t r = 0;
    try {
        if (!std::filesystem::is_directory(path))
        {
            r += std::filesystem::file_size(path);
        }
        else
        {
            for (auto entry : std::filesystem::directory_iterator(path))
                r += getFolderSize(entry.path().string());
        }
    }
    catch (std::filesystem::filesystem_error& e)
    {
        std::cout << e.what() << '\n';
    }
    return r;
}

/* This class retrieves folders size under a given path;
 * then sizes are placed in a hashtable containing folder names
 * and the size of the folders
 */
void FolderStrategy::explore(const std::string& path)
{
    std::filesystem::path p(path);
    std::filesystem::directory_iterator start(p);
    std::filesystem::directory_iterator end;

    auto entriesLambda = [this](const std::filesystem::directory_entry& entry) mutable {

        if (std::filesystem::is_directory(entry)) {

            // skip - at least for the moment - .git and .vs sub directories
            // const std::filesystem::path ext = entry.path().extension();
            std::string s = entry.path().string();
            if (endsWith(s, ".git") or endsWith(s, ".vs")) {
                return;
            }

            // retrieve size of bytes of this folder
            uintmax_t size = 0;
            try
            {
               // size = file_size(entry);  // FALSCHER WERT ?????????????????
                size = getFolderSize(entry.path().string());
            }
            catch (std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            }

            // add size to the map
            m_explorationResult[s] = size;

            explore(s);
        }
    };

    std::for_each(start, end, entriesLambda);
}

void FolderStrategy::printResults() {
    std::for_each(
        std::begin(m_explorationResult),
        std::end(m_explorationResult),
        [](const std::pair<std::string, uintmax_t>& entry) {
            std::cout << "Folder: " << entry.first << " - Size: " << entry.second << '\n';
        }
    );
}

// ===========================================================================
// End-of-File
// ===========================================================================
