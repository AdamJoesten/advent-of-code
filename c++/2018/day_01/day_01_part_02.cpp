
/**
 * Advent of Code 2018
 * Day 01 - Chronal Calibration
 */

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            throw std::invalid_argument("Usage: <program> <file_path>");
        }
        std::vector<std::string> args(argv, argv + argc);
        std::string file_path = args.at(1);

        std::filesystem::path path(file_path);
        std::ifstream fileHandler(path);

        if (!fileHandler)
        {
            throw std::runtime_error("Could not open file at " + path.string());
        }
        int frequency = 0;
        std::set<int> set{frequency};
        std::string line;
        bool flag = true;
        while (flag)
        {
            while (getline(fileHandler, line))
            {
                if (line[0] == '+')
                {
                    line = line.substr(1);
                }
                frequency += stoi(line);
                if (set.find(frequency) != set.end())
                {
                    flag = false;
                    break;
                }
                else
                {
                    set.insert(frequency);
                }
            }
            fileHandler.clear();
            fileHandler.seekg(0, std::ios_base::beg);
        }
        std::cout << "frequency: " << frequency << std::endl;
        fileHandler.close();
        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}