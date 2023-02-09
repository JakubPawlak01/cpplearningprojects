#ifndef DOG_HPP
#define DOG_HPP
#include "mammal.hpp"
#include <string>
#include <iostream>

class Dog : public Mammal
{
    private:
        std::string name;
        int aggressive;
        int vulnerability_to_training;
        std::string sound;
        static int countD;

    public:
        Dog() = default;
        Dog(int, int, double, std::string, bool, std::string, std::string, std::string, int, int, std::string);

        inline virtual void give_sound(){std::cout << this->sound << std::endl;};

        inline std::string get_name() const {return name;};
        inline int get_aggressive() const {return aggressive;};
        inline int get_vulnerability_to_training() const {return vulnerability_to_training;};
        inline std::string get_sound() const {return sound;};
        inline static int get_count() {return countD;};

        inline void set_name(std::string name) {this->name = name;};
        inline void set_aggressive(int aggressive) {this->aggressive = aggressive;};
        inline void set_vulnerability_to_training(int vulnerability_to_training) {this->vulnerability_to_training = vulnerability_to_training;};
        inline void set_sound(std::string sound) {this->sound = sound;};

        friend std::ostream& operator<<(std::ostream& os, const Dog& d);

        ~Dog();

};

#endif