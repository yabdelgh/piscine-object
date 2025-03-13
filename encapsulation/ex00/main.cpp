#include "DivideAndRule.hpp"
#include <stdlib.h>
#include <cstdlib>
// #include <>
void cleanup() {
	system();
    // std::cout << "Performing cleanup at program exit." << std::endl;
    // You could also call _CrtDumpMemoryLeaks() here if using MSVC to detect leaks
}

int main()
{
	std::atexit(cleanup);

	Bank bank = Bank();
	bank.setLiquidity(1000);
	const Account * accountA = bank.createAccount(100);
	const Account * accountC = bank.createAccount(300);
	bank.createAccount(200);
	std::cout << bank << std::endl;
 
    std::cout << "delete account" << std::endl;
    bank.deleteAccount(accountC);
    std::cout << bank << std::endl;
    
    std::cout << "deposit:" << std::endl;
    bank.deposit(accountA->getId(), 100);
	std::cout << bank << std::endl;
    
	std::cout << "withdrawal:" << std::endl;
    bank.withdrawal(accountA->getId(), 100);
	std::cout << bank << std::endl;
	
	std::cout << "loan:" << std::endl;
    bank.loan(accountA->getId(), 200);
	std::cout << bank << std::endl;
    std::exit(0);  // Or use exit(0);

	// std::cout << accountA->getValue() << std::endl;	
	return (0);
}