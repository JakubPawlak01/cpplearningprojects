#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Furniture.hpp"

class Printer
{
public:
    void printHelloLogin();
    int printSelectUser();
    void printCreateAdmin();
    void printCreateClient();
    int printMenuAdmin();
    int printMenuClient();

    void printCallMenu1();
    void printCallMenu2();
    void printCallMenu3();
    void printCallMenu4();
    void printCallMenu5();
    void printCallWrong();

    void printAdminConstructor();
    void printClientConstructor();
    void printVector(std::vector<std::string> vector);

    int getIdFromUser();
    int getPriceFromUser();
    std::string getColorFromUser();
    std::string getModelFromUser();
    std::string getTypeFromUser();

    void printFurniture(Furniture* furniture);

    bool printFurniturePrice(Furniture* furniture);
    void printFurnitureId(Furniture* furniture);
    void printFurnitureNotFound();
};