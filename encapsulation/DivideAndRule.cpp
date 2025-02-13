#include <iostream>
#include <vector>
#include <set>

class Account
{
	private:

	int id;
	int value;

	int generateUniqueID()
	{
		static int id = 0;
		return id++;
	}

	public:

	Account(const int value) : id(generateUniqueID()), value(value) {}
	

	friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
	{
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
		return (p_os);
	}

	const int &setValue(int val)
	{
		value += val;
		return value;
	}

	const int &getValue() const
	{
		return value;
	}
	
    const int &getId () const
	{
		return id;
	}
};

class Bank
{
	private:
	
	int liquidity;
	std::vector<Account *> clientAccounts;

	public:
	
	Bank(const int liquidity = 0) : liquidity(liquidity) {}

	friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
	{
		p_os << std::endl << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (auto &clientAccount : p_bank.clientAccounts)
			p_os << *clientAccount << std::endl;
		return (p_os);
	}

	const Account *createAccount(int value)
	{
		setLiquidity(value * 5 / 100);
		Account *a = new Account(value * 95 / 100);
		clientAccounts.push_back(a);
		return (a);
	}
	
    void deleteAccount(const Account * a)
	{
        for (auto it = clientAccounts.begin(); it != clientAccounts.end(); ) {
            if ((* it) == a) {
                delete *it;
                it = clientAccounts.erase(it);
            } 
            else
                ++it;
        }
    }

	const int &getLiquidity()
	{
		return liquidity;
	}
	
	const int &setLiquidity(int value)
	{
        if (value > 0 || liquidity >= value)
		    liquidity += value;
		return liquidity;
	}


	const int &withdrawal(const int &accountId, const int &value)
	{
		clientAccounts[accountId]->setValue(-value);
		return clientAccounts[accountId]->getValue();
	}
	
    const int &deposit(const int &accountId, const int &value)
	{
		setLiquidity(value * 5 / 100);
		clientAccounts[accountId]->setValue(value * 95 / 100);
		return clientAccounts[accountId]->getValue();
	}
};