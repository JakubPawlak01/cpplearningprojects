#include "../head/dog.hpp"

Dog::Dog(int age, int length_life, double weight_kg, std::string food, bool pet, std::string breed, std::string color, std::string name, int aggressive, int vulnerability_to_training, std::string sound) : Mammal(age, length_life, weight_kg, food, pet, breed, color), name(name), aggressive(aggressive), vulnerability_to_training(vulnerability_to_training), sound(sound) {
    if(aggressive < 0) this->aggressive = 0;
    else if(aggressive > 10) this->aggressive = 10;
    if(vulnerability_to_training < 0) this->vulnerability_to_training = 0;
    else if(vulnerability_to_training > 10) this->vulnerability_to_training = 10;
    ++countD;
}

Dog::~Dog(){
    --countD;
}

std::ostream& operator<<(std::ostream& out, const Dog& d)
{
    out<<"Name: " << d.get_name() << std::endl;
    out<<"Age: " << d.get_age() << std::endl;
    out<<"Length: " << d.get_length_life() << std::endl;
    out<<"Weight: " << d.get_weight_kg() << std::endl;
    out<<"Food: " << d.get_food() << std::endl;
    out<<"Pet: " << d.is_pet() << std::endl;
    out<<"Breed: " << d.get_breed() << std::endl;
    out<<"Color: " << d.get_color() << std::endl;
    out<<"Sound: " << d.get_sound() << std::endl;
    out<<"Aggressiveness: " << d.get_aggressive() << std::endl;
    out<<"Vulnerability to training: " << d.get_vulnerability_to_training() << std::endl;
    return out;
}