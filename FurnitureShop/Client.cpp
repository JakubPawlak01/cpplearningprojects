#include "User.hpp"
#include "Printer.hpp"
#include "Furniture.hpp"

Client::Client(Printer* printer, FileManager* fileManager) : printer(printer), fileManager(fileManager){}

int Client::showMainMenu()
{
    return printer->printMenuClient();
}

void Client::callMenu1()
{
    std::string type = printer->getTypeFromUser();
    std::string model = printer->getModelFromUser();
    std::string color = printer->getColorFromUser();
    Furniture* furniture = new Furniture(type, model, color);
    int id = fileManager->getIdFromFile(furniture);
    if(id == -1)
    {
        printer->printFurnitureNotFound();
        delete furniture;
        return;
    }
    int price = fileManager->getPriceFromFile(id);
    furniture->setPrice(price);
    furniture->setId(id);
    if (printer->printFurniturePrice(furniture))
    {
        printer->printFurnitureId(furniture);
        fileManager->deleteFurniture(id);
    }
    delete furniture;
}
void Client::callMenu2()
{
    std::string type = printer->getTypeFromUser();
    std::string model = printer->getModelFromUser();
    std::string color = printer->getColorFromUser();
    int price = printer->getPriceFromUser();
    int id = printer->getIdFromUser();
    Furniture* furniture = new Furniture(id, price, type, model, color);
    printer->printFurniture(furniture);
    fileManager->addFurniture(furniture);
    delete furniture;
}

void Client::callMenu3()
{
    printer->printCallMenu3();
}

void Client::callMenu4()
{
    printer->printCallMenu4();
}

void Client::callMenu5()
{
    printer->printCallMenu5();
}

void Client::callWrong()
{
    printer->printCallWrong();
}