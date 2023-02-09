#pragma once
#include <fstream>
#include "Furniture.hpp"
#include <string>
#include <vector>
#include <sstream>

class FileManager
{
    public:
        void addFurniture(Furniture* furniture);
        std::vector<std::string> split(const std::string& data);
        std::string join(const std::vector<std::string>& data);
        std::vector<std::string> csv_read(std::string filePath);
        bool findId(int id, std::vector<std::string>);
        void deleteFurniture(int id);
        int getIdFromFile(Furniture* furniture);
        int getPriceFromFile(int id);

};