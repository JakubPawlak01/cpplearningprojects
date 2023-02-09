#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal
{
    private:
        int age;
        int length_life;
        double weight_kg;
        std::string food;

    public:
        Animal() = default;
        Animal(int, int, double, std::string);

        inline virtual void give_sound(){std::cout << "I am not a specific animal!" << std::endl;};

        inline int get_age() const {return age;};
        inline int get_length_life() const {return length_life;};
        inline double get_weight_kg() const {return weight_kg;};
        inline std::string get_food() const {return food;};

        inline void set_age(int age) {this->age = age;};
        inline void set_length_life(int length_life) {this->length_life = length_life;};
        inline void set_weight_kg(double weight_kg) {this->weight_kg = weight_kg;};
        inline void set_food(std::string food) {this->food = food;};

        ~Animal() = default;
};

#endif