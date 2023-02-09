#include "Printer.hpp"

void Printer::printVector(std::vector<std::string> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << i+1 << "." << vector[i] << "." << std::endl;
    }
}

void Printer::printHelloLogin()
{
    std::cout << "Etap logowania" << std::endl << std::endl;
}

int Printer::printSelectUser()
{
    std::cout << "Wybor uzytkownika" << std::endl << std::endl;
    std::cout << "Admin - 1" << std::endl;
    std::cout << "Klient -2" << std::endl << std::endl;
    int user;
    std::cin >> user;
    return user;
}

void Printer::printCreateAdmin()
{
    std::cout << "Zalogowano jako administrator" << std::endl << std::endl;
}

void Printer::printCreateClient()
{
    std::cout << "Zalogowano jako klient" << std::endl << std::endl;
}

int Printer::printMenuAdmin()
{
    std::vector<std::string> adminMenu = 
    {
        "Utworz mebel",
        "Usun mebel",
        "3", 
        "4", 
        "Wyjscie"
    };
    this->printVector(adminMenu);
    std::cout << std::endl;
    int menuNr;
    std::cin >> menuNr;
    return menuNr; 
}

int Printer::printMenuClient()
{
    std::vector<std::string> clientMenu =
    {
        "Kup mebel",
        "Zwroc mebel",
        "3",
        "4",
        "Wyjscie"
    };
    this->printVector(clientMenu);
    std::cout << std::endl;
    int menuNr;
    std::cin >> menuNr;
    return menuNr;
}

void Printer::printCallMenu1()
{
    std::cout << "Witaj w menu 1" << std::endl << std::endl;
}

void Printer::printCallMenu2()
{
    std::cout << "Witaj w menu2" << std::endl;
}

void Printer::printCallMenu3()
{
    std::cout << "Witaj w menu3" << std::endl;
}

void Printer::printCallMenu4()
{
    std::cout << "Witaj w menu4" << std::endl;
}

void Printer::printCallMenu5()
{
    std::cout << "Zapraszamy ponownie!" << std::endl;
}

void Printer::printCallWrong()
{
    std::cout << "Witaj w callWrong" << std::endl;
}

void Printer::printAdminConstructor()
{
    std::cout << "Witaj w AdminConstructor" << std::endl;
}

void Printer::printClientConstructor()
{
    std::cout << "Witaj w ClientConstructor" << std::endl;
}

int Printer::getIdFromUser()
{
    std::cout << "Podaj id" << std::endl;
    int id;
    std::cin >> id;
    return id;
}

int Printer::getPriceFromUser()
{
    std::cout << "Podaj cene" << std::endl;
    int price;
    std::cin >> price;
    return price;
}

std::string Printer::getColorFromUser()
{
    std::cout << "Podaj kolor" << std::endl;
    std::string color;
    std::cin >> color;
    return color;
}

std::string Printer::getModelFromUser()
{
    std::cout << "Podaj model" << std::endl;
    std::string model;
    std::cin >> model;
    return model;
}

std::string Printer::getTypeFromUser()
{
    std::cout << "Podaj rodzaj mebla" << std::endl;
    std::string type;
    std::cin >> type;
    return type;
}

void Printer::printFurniture(Furniture* furniture)
{
    std::cout << "Twoj mebel to: " << std::endl << std::endl;
    std::cout << "Rodzaj: " << furniture->type << std::endl;
    std::cout << "Model: " << furniture->model << std::endl;
    std::cout << "Kolor: " << furniture->color << std::endl;
    std::cout << "Cena: " << furniture->price << std::endl;
    std::cout << "ID: " << furniture->id << std::endl << std::endl;
}

bool Printer::printFurniturePrice(Furniture* furniture)
{
    std::cout << "Cena twojego mebla to: " << furniture->price << std::endl;
    std::cout << "Wpisz tak jesli chcesz kupic mebel " << std::endl;
    std::string input;
    std::cin >> input;
    return input == "tak" ? true : false; 
}

void Printer::printFurnitureId(Furniture* furniture)
{
    std::cout << "Dziekujemy za zakup!" << std::endl << std::endl;
    std::cout << "ID mebla potrzebne do zwrotu to: " << furniture->id << std::endl << std::endl;
}

void Printer::printFurnitureNotFound()
{
    std::cout << "Nie znaleziono takiego mebla" << std::endl;
}