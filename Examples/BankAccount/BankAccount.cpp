// ===========================================================================
// BankAccount.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BankAccount
{
private:
    int m_balance;

public:
    BankAccount() : BankAccount{ 0 } {}
    BankAccount(int balance) : m_balance{ balance } {}

    void deposit(int amount) { m_balance += amount; }
    void withdraw(int amount) { m_balance -= amount; }
    int getBalance() const { return m_balance; }
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
    Action  m_action;
    int     m_amount;

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
    std::vector<std::shared_ptr<Command>> m_transactions;

public:
    Transactions (std::initializer_list<std::shared_ptr<Command>> transactions)
        : m_transactions { transactions } {}

    void execute() 
    {
        for (const auto& transaction : m_transactions) {
            transaction->execute();
        }
    }
};

void testBankAccounts_01()
{
    BankAccount ba1{ 1000 };
    BankAccount ba2{ 1000 };

    Transactions transactions {
        std::make_shared<BankAccountCommand>(ba1, BankAccountCommand::Action::withdraw, 300),
        std::make_shared<BankAccountCommand>(ba1, BankAccountCommand::Action::withdraw, 300)
    };

    transactions.execute();

    std::cout << ba1.getBalance() << std::endl;
    std::cout << ba2.getBalance() << std::endl;
}

// or without class 'Transactions' a.k.a. 'Invoker'

void testBankAccounts_02()
{
    BankAccount ba1{ 1000 };
    BankAccount ba2{ 1000 };

    std::vector<BankAccountCommand> transactions
    {
        BankAccountCommand{ba1, BankAccountCommand::Action::withdraw, 300},
        BankAccountCommand{ba2, BankAccountCommand::Action::deposit, 300}
    };

    for (const auto& transaction : transactions) {
        transaction.execute();
    }

    std::cout << ba1.getBalance() << std::endl;
    std::cout << ba2.getBalance() << std::endl;
}

void testBankAccounts()
{
    testBankAccounts_01();
    testBankAccounts_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
