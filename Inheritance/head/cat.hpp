#ifndef CAT_HPP
#define CAT_HPP
#include "mammal.hpp"
#include <string>
#include <iostream>

class Cat : public Mammal
{
    private:
        std::string name;
        int hunting_skills;
        std::string sound;
        static int countC;

    public:
        Cat() = default;
        Cat(int, int, double, std::string, bool, std::string, std::string, std::string, int, std::string);

        inline virtual void give_sound(){std::cout << this->sound << std::endl;};

        inline std::string get_name() const {return name;};
        inline int get_hunting_skills() const {return hunting_skills;};
        inline std::string get_sound() const {return sound;};
        inline static int get_count() {return countC;};

        inline void set_name(std::string name) {this->name = name;};
        inline void set_hunting_skills(int hunting_skills) {this->hunting_skills = hunting_skills;};
        inline void set_sound(std::string sound) {this->sound = sound;};

        friend std::ostream& operator<<(std::ostream& os, const Cat& c);

        ~Cat ();

};

#endif