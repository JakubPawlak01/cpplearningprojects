#pragma once
#include <string>

class Furniture
{
public:
    int id;
    int price;
    std::string model;
    std::string color;
    std::string type;
public:
    Furniture(int id, int price, std::string type, std::string model, std::string color);
    Furniture(std::string type, std::string model, std::string color);

    void setPrice(int price);
    void setId(int id);
};