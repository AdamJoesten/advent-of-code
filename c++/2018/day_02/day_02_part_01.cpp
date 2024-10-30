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
        int two_count = 0;
        int three_count = 0;
        while (getline(fileHandler, line))
        {
            std::map<char, int> dict;
            bool two_flag = false;
            bool three_flag = false;
            for (const char &c : line)
            {
                dict[c]++;
            }
            for (const auto &[k, v] : dict)
            {
                std::cout << k << " " << v << std::endl;
                if (v == 2)
                {
                    two_flag = true;
                }
                if (v == 3)
                {
                    three_flag = true;
                }
            }
            if (two_flag) {
                two_count++;
            }
            if (three_flag) {
                three_count++;
            }
        }
        std::cout << two_count * three_count << std::endl;
        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}