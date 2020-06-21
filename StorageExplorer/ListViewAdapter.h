// ===========================================================================
// ListViewAdapter.h
// ===========================================================================

class ListViewAdapter : public ExplorationStrategy
{
private:
    std::shared_ptr<ListView> m_listView;

public:
    ListViewAdapter();
    ~ListViewAdapter();

    void explore(const std::string& path) override;
    void printResults() override;

private:

};

// ===========================================================================
// End-of-File
// ===========================================================================
