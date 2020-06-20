// ===========================================================================
// ListView.h
// ===========================================================================

/* 
 * Simple console based ListView control
 */
class ListView
{
private:
    int m_cols;
    std::vector<std::string> m_titles;

public:
    // c'tor
    ListView();

    void setColumns(int);
    void setColumnHeader(int, std::string);
    void setData();

    void show();
};

// ===========================================================================
// End-of-File
// ===========================================================================
