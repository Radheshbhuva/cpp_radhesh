#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class FileManager
{
public:
    void readData(const std::string &filename)
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            throw std::runtime_error("Error opening file: " + filename);
        }

        std::string line;

        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }

        file.close();
    }
};

int main()
{
    FileManager fileManager;

    std::string filename;
    std::cout << "Enter the filename to read data from: ";
    std::cin >> filename;

    try
    {
        fileManager.readData(filename);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
