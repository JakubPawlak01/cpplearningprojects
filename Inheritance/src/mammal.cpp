#include "../head/mammal.hpp"

Mammal::Mammal(int age, int length_life, double weight_kg, std::string food, bool pet, std::string breed, std::string color) : Animal(age, length_life, weight_kg, food), pet(pet), breed(breed), color(color) {}
