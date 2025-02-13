#include "DivideAndRule.cpp"
#include <stdlib.h>

int main()
{

	Bank bank = Bank();
	bank.setLiquidity(1000);
	const Account * accountA = bank.createAccount(100);
	const Account * accountB = bank.createAccount(200);
	const Account * accountC = bank.createAccount(300);
	std::cout << bank << std::endl;
 
    std::cout << "delete account" << std::endl;
    bank.deleteAccount(accountC);
    std::cout << bank << std::endl;
    
    std::cout << "depot account" << std::endl;
    bank.deposit(accountA->getId(), 100);
	std::cout << bank << std::endl;
    
	std::cout << "withdrawal account" << std::endl;
    bank.withdrawal(accountA->getId(), 100);
	std::cout << bank << std::endl;
	

	return (0);
}