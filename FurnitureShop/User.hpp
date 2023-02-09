#pragma once
#include "Printer.hpp"
#include "FileManager.hpp"

class User
{
public:

    virtual int showMainMenu() = 0;
    virtual void callMenu1() = 0;
    virtual void callMenu2() = 0;
    virtual void callMenu3() = 0;
    virtual void callMenu4() = 0;
    virtual void callMenu5() = 0;
    virtual void callWrong() = 0;
    
};

class Admin : public User
{
public:
    Admin(Printer* printer, FileManager* fileManager);

    int showMainMenu();
    void callMenu1();
    void callMenu2();
    void callMenu3();
    void callMenu4();
    void callMenu5();
    void callWrong();

protected:
    Printer* printer;
    FileManager* fileManager;
};

class Client : public User
{
public:
    Client(Printer* printer, FileManager* fileManager);

    int showMainMenu();
    void callMenu1();
    void callMenu2();
    void callMenu3();
    void callMenu4();
    void callMenu5();
    void callWrong();

protected:
    Printer* printer;
    FileManager* fileManager;
};