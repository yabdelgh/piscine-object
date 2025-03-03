#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== COMPOSITION TEST ===\n";
    {
        Worker worker1;
    }

    std::cout << "\n=== AGGREGATION TEST ===\n";
    {
        Shovel* shovel = new Shovel();
        {
            Worker worker2;
            worker2.addTool(shovel);  
            shovel->use();            
        }  
        shovel->use();  
        delete shovel;  
    }

    std::cout << "\n=== INHERITANCE & TOOL MANAGEMENT ===\n";
    {
        Worker worker3;
        Hammer* hammer = new Hammer();
        Shovel* shovel2 = new Shovel();

        // worker3.addTool(hammer);
        // worker3.addTool(shovel2);
        shovel2->setOwner(&worker3);
        hammer->setOwner(&worker3);
        std::cout << "\nWorker3's tools:\n";
        worker3.work();

        Worker worker4;
        std::cout << "\nTransferring shovel to worker4\n";
        shovel2->setOwner(&worker4);
        worker4.work();
        // worker4.addTool(shovel2);
        
        std::cout << "\nWorker3's tools after transfer:\n";
        worker3.work();  
    }

    std::cout << "\n=== ASSOCIATION & WORKSHOPS ===\n";
    {
        Workshop workshop1;
        Workshop workshop2;
        
        Worker* worker5 = new Worker();
        Shovel* shovel3 = new Shovel();
        worker5->addTool(shovel3);

        worker5->registerWorkshop(&workshop1);
        worker5->registerWorkshop(&workshop2);

        std::cout << "\nWorkday in both workshops:\n";
        workshop1.executeWorkDay();
        workshop2.executeWorkDay();

        std::cout << "\nWorker5 leaves workshop1\n";
        worker5->leaveWorkshop(&workshop1);
        workshop1.executeWorkDay();  // Shouldn't execute for worker5

        delete worker5;  // Should automatically leave remaining workshops
        delete shovel3;
    }

    // std::cout << "\n=== TOOL GETTER TEMPLATE ===\n";
    // {
    //     Worker worker6;
    //     Hammer* hammer2 = new Hammer();
    //     worker6.addTool(hammer2);

    //     // Using template getTool
    //     Hammer* retrievedHammer = worker6.getTool<Hammer>();
    //     if (retrievedHammer) {
    //         std::cout << "Found hammer!\n";
    //         retrievedHammer->use();
    //     }

    //     Shovel* retrievedShovel = worker6.getTool<Shovel>();
    //     if (!retrievedShovel) {
    //         std::cout << "No shovel found (correct)\n";
    //     }
        
    //     delete hammer2;
    // }

    return 0;
}