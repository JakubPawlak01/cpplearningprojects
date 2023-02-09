#include <iostream>
#include "head/animal.hpp"
#include "head/mammal.hpp"
#include "head/cat.hpp"
#include "head/dog.hpp"
#include <memory>

int Cat::countC = 0;
int Dog::countD = 0;

int main()
{
    
    //auto mary = std::make_unique<Cat>(4, 15, 2.5, "meet", 1, "none", "multi", "Maria", 10, "miauuuu");
    //mary->give_sound();
    
    auto Jan = std::make_unique<Dog>(3, 10, 25, "everything", 1, "owczar", "white", "Jan", -1, 1, "Hoouuuu");
    auto mary = std::make_unique<Cat>(4, 15, 2.5, "meet", 1, "none", "multi", "Maria", 10, "miauuuu");
    std::cout<< "Number of dogs before range: "<< Dog::get_count()<<std::endl;

    {
        auto Jan2 = std::make_unique<Dog>(3, 10, 25, "everything", 1, "owczar", "white", "Jan", -1, 1, "Hoouuuu");
        std::cout<< "Number of dogs in range: "<< Dog::get_count()<<std::endl;
    }
    std::cout<< "Number of dogs out of the range: "<< Dog::get_count()<<std::endl;
    return 0;
}
