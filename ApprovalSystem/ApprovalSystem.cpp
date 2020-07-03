// ===========================================================================
// ApprovalSystem.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <string_view>

class Role
{
public:
    virtual double getApprovalLimit() const noexcept = 0;
    virtual ~Role() {}
};

class EmployeeRole : public Role
{
public:
    virtual double getApprovalLimit() const noexcept override
    {
        return 1000;
    }
};

class TeamManagerRole : public Role
{
public:
    virtual double getApprovalLimit() const noexcept override
    {
        return 10000;
    }
};

class DepartmentManagerRole : public Role
{
public:
    virtual double getApprovalLimit() const noexcept override
    {
        return 100000;
    }
};

class PresidentRole : public Role
{
public:
    virtual double getApprovalLimit() const noexcept override
    {
        return std::numeric_limits<double>::max();
    }
};

class Expense
{
private:
    double m_amount;
    std::string m_description;

public:
    Expense(double const amount, std::string_view desc)
        : m_amount(amount), m_description(desc) {}

    double getAmount() const noexcept { return m_amount; }
    std::string getDescription() const noexcept { return m_description; }
};

class Employee
{
private:
    std::string m_name;
    std::unique_ptr<Role> m_ownRole;
    std::shared_ptr<Employee> m_directManager;

public:
    explicit Employee(std::string_view name, std::unique_ptr<Role> ownrole)
        : m_name(name), m_ownRole(std::move(ownrole)) {}

    void setDirectManager(std::shared_ptr<Employee> manager)
    {
        m_directManager = manager;
    }

    void approve(const Expense& e)
    {
        if (e.getAmount() <= m_ownRole->getApprovalLimit()) {
            std::cout 
                << m_name << " approved expense '" << e.getDescription()
                << "', cost=" << e.getAmount() << std::endl;
        }
        else if (m_directManager != nullptr) {
            m_directManager->approve(e);
        }
    }
};

void approval_system() 
{
    auto john = std::make_shared<Employee>("john smith",
        std::make_unique<EmployeeRole>());

    auto robert = std::make_shared<Employee>("robert booth",
        std::make_unique<TeamManagerRole>());

    auto david = std::make_shared<Employee>("david jones",
        std::make_unique<DepartmentManagerRole>());

    auto cecil = std::make_shared<Employee>("cecil williamson",
        std::make_unique<PresidentRole>());

    john->setDirectManager(robert);
    robert->setDirectManager(david);
    david->setDirectManager(cecil);

    john->approve(Expense{ 500, "magazins" });
    john->approve(Expense{ 5000, "hotel accomodation" });
    john->approve(Expense{ 50000, "conference costs" });
    john->approve(Expense{ 200000, "new lorry" });
}

// ===========================================================================
// End-of-File
// ===========================================================================
