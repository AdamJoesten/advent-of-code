/**
 * Advent of Code 2018
 * Day 03 - No Matter How You Slice It
 */

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iostream>
#include <optional>
#include <cstring>
#include "DayFour.hpp"

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

        DayFour day_four(file_path);
        day_four.Run();

        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}