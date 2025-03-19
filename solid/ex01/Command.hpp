#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Command {
protected:
    std::string id;
    std::string date;
    std::string client;
    std::vector<std::pair<double, int> > articles; // price + quantity
    
public:
    Command(const std::string& id, 
            const std::string& date,
            const std::string& client,
            const std::vector<std::pair<double, int> >& articles 
           ) : id(id), date(date), client(client), articles(articles) {}

    virtual double calculate_total() const {
        double total = 0;
        for (std::vector<std::pair<double, int> >::const_iterator it = articles.begin(); 
             it != articles.end(); ++it) {
            total += it->first * it->second;
        }
        return total;
    }

    virtual ~Command() {}
};

class TuesdayDiscount : public Command {
public:
    TuesdayDiscount(const std::string& id, 
            const std::string& date,
            const std::string& client,
            const std::vector<std::pair<double, int> >& articles
           ) : Command(id, date, client, articles) {}

    double calculate_total() const {
        double total = Command::calculate_total();
        return total * 0.9;
    }
};

class PackageDiscount : public Command {
public:
    PackageDiscount(const std::string& id, 
                    const std::string& date,
                    const std::string& client,
                    const std::vector<std::pair<double, int> >& articles
    ) : Command(id, date, client, articles) {}

    double calculate_total() const {
        double total = Command::calculate_total();
        return (total > 150) ? total - 10 : total;
    }
};

#endif