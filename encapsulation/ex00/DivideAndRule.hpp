#ifndef DEVIDEANDRULE_HPP
#define DEVIDEANDRULE_HPP

#include <iostream>
#include <vector>

class Account
{
private:
    int id;
    int value;

    int generateUniqueID();

public:
    Account(const int value);

    friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);

    const int &setValue(int val);
    const int &getValue() const;
    const int &getId() const;
};

class Bank
{
private:
    int liquidity;
    std::vector<Account *> clientAccounts;

public:
    Bank(const int liquidity = 0);

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);

    const Account *createAccount(int value);
    void deleteAccount(const Account *a);
    const int &getLiquidity() const;
    const int &setLiquidity(int value);
    const int &withdrawal(const int &accountId, const int &value);
    const int &deposit(const int &accountId, const int &value);
    const int &loan(const int &accountId, const int &value);
};

#endif // TEST_HPP
