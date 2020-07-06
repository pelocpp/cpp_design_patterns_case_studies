// ===========================================================================
// ObservableVectorContainer.cpp
// ===========================================================================

#include <iostream>
#include <string>

#include <vector>

#include <cassert>

enum class CollectionAction
{
    add,
    remove,
    clear,
    assign
};

std::string to_string(CollectionAction const action)
{
    switch (action)
    {
    case CollectionAction::add: return "add";
    case CollectionAction::remove: return "remove";
    case CollectionAction::clear: return "clear";
    case CollectionAction::assign: return "assign";
    default:
        return "";
    }
}

class CollectionChangeNotification
{
public:
    CollectionAction m_action;
    std::vector<size_t> m_indexes;
};

class CollectionObserver {
public:
    virtual void collectionChanged(CollectionChangeNotification notification) = 0;
    virtual ~CollectionObserver() {}
};

template <typename T, class Allocator = std::allocator<T>>
class ObservableVector final
{
    typedef typename std::vector<T, Allocator>::size_type size_type;

public:
    ObservableVector() noexcept(noexcept(Allocator()))
        : ObservableVector(Allocator()) {}

    explicit ObservableVector(const Allocator& alloc) noexcept
        : m_data(alloc) {}

    ObservableVector(size_type count, const T& value, const Allocator& alloc = Allocator())
        : m_data(count, value, alloc) {}

    explicit ObservableVector(size_type count, const Allocator& alloc = Allocator())
        : m_data(count, alloc) {}

    ObservableVector(ObservableVector&& other) noexcept
        : m_data(other.data) {}

    ObservableVector(ObservableVector&& other, const Allocator& alloc)
        : m_data(other.data, alloc) {}

    ObservableVector(std::initializer_list<T> init, const Allocator& alloc = Allocator())
        : m_data(init, alloc) {}

    template<class InputIt>
    ObservableVector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
        : m_data(first, last, alloc) {}

    ObservableVector& operator=(ObservableVector const& other)
    {
        if (this != &other)
        {
            m_data = other.m_data;
            for (auto o : observers) {
                if (o != nullptr) {
                    o->collectionChanged({
                        CollectionAction::assign,
                        std::vector<size_t> {}
                        });
                }
            }
        }
        return *this;
    }

    ObservableVector& operator=(ObservableVector&& other) noexcept
    {
        if (this != &other)
        {
            m_data = std::move(other.m_data);
            for (auto o : observers)
            {
                if (o != nullptr)
                {
                    o->collectionChanged({
                        CollectionAction::assign,
                        std::vector<size_t> {}
                        });
                }
            }
        }
        return *this;
    }

    void push_back(T&& value)
    {
        m_data.push_back(value);
        for (auto o : observers)
        {
            if (o != nullptr)
            {
                o->collectionChanged({
                    CollectionAction::add,
                    std::vector<size_t> {m_data.size() - 1}
                    });
            }
        }
    }

    void pop_back()
    {
        m_data.pop_back();
        for (auto o : observers)
        {
            if (o != nullptr)
            {
                o->collectionChanged({
                    CollectionAction::remove,
                    std::vector<size_t> {m_data.size() + 1}
                    });
            }
        }
    }

    void clear() noexcept
    {
        m_data.clear();
        for (auto o : observers)
        {
            if (o != nullptr)
            {
                o->collectionChanged({
                    CollectionAction::clear, 
                    std::vector<size_t> {}
                    });
            }
        }
    }

    size_type size() const noexcept
    {
        return m_data.size();
    }

    bool empty() const noexcept
    {
        return m_data.empty();
    }

    void add_observer(CollectionObserver* const o)
    {
        observers.push_back(o);
    }

    void remove_observer(CollectionObserver const* const o)
    {
        observers.erase(
            std::remove(std::begin(observers),
            std::end(observers), o),
            std::end(observers)
        );
    }

private:
    std::vector<T, Allocator> m_data;
    std::vector<CollectionObserver*> observers;
};

class observer : public CollectionObserver
{
public:
    virtual void collectionChanged(CollectionChangeNotification notification) override
    {
        std::cout << "action: " << to_string(notification.m_action);
        if (!notification.m_indexes.empty()) {
            std::cout << ", indexes: ";
            for (auto i : notification.m_indexes)
                std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
};

void observableVectorContainer() {
    ObservableVector<int> v;
    observer o;
    v.add_observer(&o);
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    v.clear();
    v.remove_observer(&o);
    v.push_back(3);
    v.push_back(4);
    v.add_observer(&o);
    ObservableVector<int> v2{ 1,2,3 };
    v = v2;
    v = ObservableVector<int>{ 7,8,9 };
}

// ===========================================================================
// End-of-File
// ===========================================================================
