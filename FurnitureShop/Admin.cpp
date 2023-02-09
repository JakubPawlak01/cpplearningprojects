#include "User.hpp"
#include "Printer.hpp"
#include "Furniture.hpp"

Admin::Admin(Printer* printer, FileManager* fileManager) : printer(printer), fileManager(fileManager){}

int Admin::showMainMenu()
{
    return printer->printMenuAdmin();
}

void Admin::callMenu1()
{
    std::string type = printer->getTypeFromUser();
    int id = printer->getIdFromUser();
    int price = printer->getPriceFromUser();
    std::string model = printer->getModelFromUser();
    std::string color = printer->getColorFromUser();
    Furniture* furniture = new Furniture(id, price, type, model, color);
    printer->printFurniture(furniture);
    fileManager->addFurniture(furniture);
    delete furniture;
}

void Admin::callMenu2()
{
    int id = printer->getIdFromUser();
    fileManager->deleteFurniture(id);
}

void Admin::callMenu3()
{
    printer->printCallMenu3();
}

void Admin::callMenu4()
{
    printer->printCallMenu4();
}

void Admin::callMenu5()
{
    printer->printCallMenu5();
}

void Admin::callWrong()
{
    printer->printCallWrong();
}