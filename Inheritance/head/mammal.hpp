#ifndef MAMMAL_HPP
#define MAMMAL_HPP
#include "animal.hpp"
#include <string>
#include <iostream>

class Mammal : public Animal
{
    private:
        bool pet;
        std::string breed;
        std::string color;

    public:
        Mammal() = default;
        Mammal(int, int, double, std::string, bool, std::string, std::string);

        inline virtual void give_sound(){std::cout << "I am a mammal but still not specific type of animal!" << std::endl;};

        inline bool is_pet() const {return pet;};
        inline std::string get_breed() const {return breed;};
        inline std::string get_color() const {return color;};

        inline void set_pet(bool pet) {this->pet = pet;};
        inline void set_breed(std::string breed) {this->breed = breed;};
        inline void set_color(std::string color) {this->color = color;};

        ~Mammal() = default;
};

#endif