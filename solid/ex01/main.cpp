#include <iostream>
#include "Command.hpp"
int main() {
    std::vector<std::pair<double, int> > articles1;
    articles1.push_back(std::make_pair(25.0, 2));
    articles1.push_back(std::make_pair(50.0, 3));
    
    // std::vector<std::pair<double, int> > articles2;
    // articles2.push_back(std::make_pair(80.0, 3));

    Command order("001","2023-10-10", "001", articles1);
    TuesdayDiscount tuesday_order("001","2023-10-10", "001", articles1);
    PackageDiscount package_order("002","2023-10-11", "001", articles1);

    std::cout << "total: €" << order.calculate_total() << std::endl;
    std::cout << "Tuesday total: €" << tuesday_order.calculate_total() << std::endl;
    std::cout << "Package total: €" << package_order.calculate_total() << std::endl;

    return 0;
}

