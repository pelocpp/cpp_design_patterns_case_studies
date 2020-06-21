// ===========================================================================
// ListViewAdapter.h
// ===========================================================================

class ListViewAdapter : public IExplorationObserver
{
private:
    std::shared_ptr<ListView> m_listView;

public:
    ListViewAdapter();
    ~ListViewAdapter();

    void update(const std::string&) override;

private:
};

// ===========================================================================
// End-of-File
// ===========================================================================
