// ===========================================================================
// ExplorationStrategy.h
// ===========================================================================

class IExplorationStrategy {
public:
    virtual void explore(const std::string& path) = 0;
    virtual void printResults() = 0;

    virtual void attach(std::shared_ptr<IExplorationObserver>) = 0;
    virtual void detach(std::shared_ptr<IExplorationObserver>) = 0;
    virtual void onFinish() = 0;
};

// ===========================================================================

/* This class is the base class for the concrete strategy classes:
 * 1. FolderStrategy (obtain file size grouped by folder)
 * 2. FileTypeStrategy (obtain file size grouped by file type)
 */
class ExplorationStrategy : public IExplorationStrategy
{
    // For holding the exploration result. The key-value pair 
    // can contain information: FolderName-Size or FileType-Size
protected:
    std::map<std::string, uintmax_t> m_explorationResult;

public:
    ExplorationStrategy() = default;
    ~ExplorationStrategy() = default;

    /**
    * observer management methods
    */
    void attach(std::shared_ptr<IExplorationObserver> observer) override {
    //    m_list_observers.push_back(observer);
    }

    void detach(std::shared_ptr<IExplorationObserver> observer) override {
     //   m_list_observers.remove(observer);
    }

    void onFinish() override {
        //std::list<std::shared_ptr<IObserver>>::iterator iterator = m_list_observers.begin();
        //howManyObserver();
        //while (iterator != m_list_observers.end()) {
        //    std::shared_ptr<IObserver> ptr = *iterator;
        //    ptr->update(m_message);
        //    ++iterator;
        //}
    }

};

// ===========================================================================

class FolderStrategy : public ExplorationStrategy
{
public:
    FolderStrategy() = default;
    ~FolderStrategy() = default;

    void explore(const std::string& path) override;
    void printResults() override;
};

// ===========================================================================

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
