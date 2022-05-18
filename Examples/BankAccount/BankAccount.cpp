// ===========================================================================
// BankAccount.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <vector>

class BankAccount
{
private:
    int m_balance;

public:
    BankAccount() : BankAccount{ 0 } {}
    BankAccount(int balance) : m_balance{ balance } {}

    void deposit(int amount) { m_balance += amount; }
    void withdraw(int amount) { m_balance -= amount; }
    int geBalance() const { return m_balance; }
};

class Command
{
protected:
    BankAccount& m_account;

public:
    Command(BankAccount& account) : m_account{ account } {}
    virtual void execute() const = 0;
};

class BankAccountCommand : public Command
{
public:
    enum class Action { deposit, withdraw };

private:
    Action       m_action;
    int          m_amount;

public:
    BankAccountCommand(BankAccount& account, Action action, int amount)
        : Command{ account }, m_action{ action }, m_amount{ amount } {}

    virtual void execute() const override
    {
        if (m_action == Action::deposit) {
            m_account.deposit(m_amount);
        }
        else if (m_action == Action::withdraw) {
            m_account.withdraw(m_amount);
        }
    }
};

class Transactions
{
private:
    std::vector<BankAccountCommand> m_transactions;

public:
    Transactions (std::initializer_list<BankAccountCommand> transactions)
        : m_transactions { transactions } {}

    void execute() 
    {
        for (const auto& transaction : m_transactions) {
            transaction.execute();
        }
    }
};

void testBankAccounts()
{
    BankAccount ba1{ 1000 };
    BankAccount ba2{ 1000 };

    Transactions transactions {
        BankAccountCommand{ba1, BankAccountCommand::Action::withdraw, 300},
        BankAccountCommand{ba2, BankAccountCommand::Action::deposit, 300} 
    };

    transactions.execute();

    std::cout << ba1.geBalance() << std::endl;
    std::cout << ba2.geBalance() << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
