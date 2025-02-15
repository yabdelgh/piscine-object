#include "DivideAndRule.hpp"

Account::Account(const int value) : id(generateUniqueID()), value(value) {}

int Account::generateUniqueID()
{
    static int id = 0;
    return id++;
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return p_os;
}

const int &Account::setValue(int val)
{
    value += val;
    return value;
}

const int &Account::getValue() const
{
    return value;
}

const int &Account::getId() const
{
    return id;
}

Bank::Bank(const int liquidity) : liquidity(liquidity) {}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
    p_os << std::endl << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
    for (std::vector<Account*>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
        p_os << **it << std::endl;

    return p_os;
}

const Account *Bank::createAccount(int value)
{
    setLiquidity(value * 5 / 100);
    Account *a = new Account(value * 95 / 100);
    clientAccounts.push_back(a);
    return a;
}

void Bank::deleteAccount(const Account *a)
{
    for (std::vector<Account*>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); )
{
    if (*it == a)
    {
        delete *it;
        it = clientAccounts.erase(it);
    }
    else
    {
        ++it;
    }
}
}

const int &Bank::getLiquidity() const
{
    return liquidity;
}

const int &Bank::setLiquidity(int value)
{
    if (value > 0 || liquidity >= value)
        liquidity += value;
    return liquidity;
}

const int &Bank::withdrawal(const int &accountId, const int &value)
{
    clientAccounts[accountId]->setValue(-value);
    return clientAccounts[accountId]->getValue();
}

const int &Bank::deposit(const int &accountId, const int &value)
{
    setLiquidity(value * 5 / 100);
    clientAccounts[accountId]->setValue(value * 95 / 100);
    return clientAccounts[accountId]->getValue();
}

const int &Bank::loan(const int &accountId, const int &value)
{
    if (liquidity >= value)
    {
        liquidity -= value;
        clientAccounts[accountId]->setValue(value);
    }
    return clientAccounts[accountId]->getValue();
}
