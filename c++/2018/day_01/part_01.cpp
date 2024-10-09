/**
 * Advent of Code 2018
 * Day 01 - Chronal Calibration
 */

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            throw std::invalid_argument("Usage: <program> <file_path>");
        }
        std::vector<std::string> args(argv, argv + argc); // Pointer arithemetic
        std::string file_path = args.at(1);

        std::filesystem::path path(file_path);
        std::ifstream fileHandler(path);

        if (!fileHandler)
        {
            throw std::runtime_error("Could not open file at " + path.string());
        }

        int total = 0;
        std::string line;
        while (getline(fileHandler, line))
        {
            if (line[0] == '+')
            {
                line = line.substr(1);
            }
            total += stoi(line);
        }
        std::cout << "total: " << total << std::endl;
        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}