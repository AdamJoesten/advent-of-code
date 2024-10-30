/**
 * Advent of Code 2018
 * Day 01 - Chronal Calibration
 */

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>

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

        std::string line;
        while (getline(fileHandler, line))
        {
            std::map<std::string, int> dict;
            for (std::string::size_type x = 0; x < line.size(); x += 1)
            {
                std::string temp = line;
                std::string substring = temp.erase(x, 1);
                if (dict.find(substring) == dict.end())
                {
                    dict.insert(std::pair(substring, static_cast<int>(x)));
                }
                else
                {
                    if (dict.find(substring) != dict.end())
                    {
                        int match_index = dict[substring];
                        printf("x: %d, match_index: %d\n", (int)x, match_index);
                        if (match_index == x)
                        {
                            printf("result: %s\n", substring.c_str());
                        }
                    }
                }
            }
        }
        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}