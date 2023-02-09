#include "../head/cat.hpp"

Cat::Cat(int age, int length_life, double weight_kg, std::string food, bool pet, std::string breed, std::string color, std::string name, int hunting_skills, std::string sound) : Mammal(age, length_life, weight_kg, food, pet, breed, color), name(name), hunting_skills(hunting_skills), sound(sound){
    if(hunting_skills < 0) this->hunting_skills = 0;
    else if(hunting_skills > 10) this->hunting_skills = 10;
    ++countC;
}

Cat::~Cat(){
    --countC;
}

std::ostream& operator<<(std::ostream& out, const Cat& c)
{
    out<<"Name: " << c.get_name() << std::endl;
    out<<"Age: " << c.get_age() << std::endl;
    out<<"Length: " << c.get_length_life() << std::endl;
    out<<"Weight: " << c.get_weight_kg() << std::endl;
    out<<"Food: " << c.get_food() << std::endl;
    out<<"Pet: " << c.is_pet() << std::endl;
    out<<"Breed: " << c.get_breed() << std::endl;
    out<<"Color: " << c.get_color() << std::endl;
    out<<"Hunting skills: " << c.get_hunting_skills() << std::endl;
    out<<"Sound: " << c.get_sound() << std::endl;
    return out;
}