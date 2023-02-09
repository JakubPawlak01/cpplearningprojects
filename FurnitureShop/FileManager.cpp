#include "FileManager.hpp"
#include <fstream>
#include "Furniture.hpp"
#include <string>
#include <vector>
#include <sstream>

void FileManager::addFurniture(Furniture* furniture)
{
    std::fstream file;

    file.open("database.csv", std::ios::out | std::ios::app);

    file << furniture->id << ";"
         << furniture->type << ";"     
         << furniture->model << ";"
         << furniture->color << ";"
         << furniture->price << std::endl;
    file.close();
}

std::vector<std::string> FileManager::split(const std::string& data)
{
        std::vector<std::string> vector;

        std::istringstream const_string_data(data);

        std::string word;
        while (getline(const_string_data,word,';'))
        {
                        vector.push_back(word);
        }
        return vector;

}

std::string FileManager::join(const std::vector<std::string>& data)
{
        std::string return_string = "";

        for (uint8_t i = 0; i < data.size(); i++)
        {
                return_string += data[i];
                return_string += i == data.size() - 1 ? "" : ";";
        }

        return return_string;
}

std::vector<std::string> FileManager::csv_read(std::string filePath)
{
	std::ifstream file;
	file.open(filePath);
	std::string textFromFile;
	std::vector<std::string> vectorOfLines;
	while(getline(file, textFromFile))
		vectorOfLines.push_back(textFromFile);
	file.close();
	return vectorOfLines;
}

bool FileManager::findId(int id, std::vector<std::string> stringFromFile)
{
    int idFromString = std::stoi(stringFromFile[0]);
    return idFromString == id;
}

void FileManager::deleteFurniture(int id)
{
    std::ifstream readFile;
    readFile.open("database.csv");
    std::string rowFromFile;
    std::fstream writeFile;
    writeFile.open("database2.csv", std::ios::out | std::ios::app);
    while(getline(readFile, rowFromFile))
    {
        if(findId(id, this->split(rowFromFile)))
        {
            continue;
        }
        else
        {
            writeFile << rowFromFile << std::endl;
        }
    } 
    readFile.close();
    writeFile.close();
    std::remove("database.csv");
    std::rename("database2.csv", "database.csv");              
}

int FileManager::getIdFromFile(Furniture* furniture)
{
    std::ifstream readFile;
    readFile.open("database.csv");
    std::string rowFromFile;
    while(getline(readFile, rowFromFile))
    {
        std::vector<std::string> vector = this->split(rowFromFile);
        if(vector[1] == furniture->type && vector[2] == furniture->model && vector[3] == furniture->color)
        {
            int id = std::stoi(vector[0]);
            readFile.close();
            return id;
        }
    } 
    readFile.close();
    return -1;
}

int FileManager::getPriceFromFile(int id)
{
    std::ifstream readFile;
    readFile.open("database.csv");
    std::string rowFromFile;
    while(getline(readFile, rowFromFile))
    {
        std::vector<std::string> vector = this->split(rowFromFile);
        if(this->findId(id, vector))
        {
            int price = std::stoi(vector[4]);
            readFile.close();
            return price;
        }
    } 
    readFile.close();
    return -1;
}
    

    



