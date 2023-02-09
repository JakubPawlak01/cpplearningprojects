#include "Furniture.hpp"


Furniture::Furniture(int id, int price, std::string type, std::string model, std::string color) : id(id), price(price), type(type), model(model), color(color) {}

Furniture::Furniture(std::string type, std::string model, std::string color) : type(type), model(model), color(color) {}

void Furniture::setPrice(int price)
{
    this->price = price;
}

void Furniture::setId(int id)
{
    this->id = id;
}


