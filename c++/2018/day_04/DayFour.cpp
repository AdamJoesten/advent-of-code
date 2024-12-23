#include "DayFour.hpp"
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <stdexcept>

static bool sort_function(const std::tuple<long long, std::string> &a, const std::tuple<long long, std::string> &b)
{
    return (std::get<0>(a) < std::get<0>(b));
}

DayFour::DayFour(const std::string &file_path) : SolutionBase(file_path) {};

DayFour::~DayFour()
{
    printf("DayFour was destructed...\n");
};

int DayFour::part_01()
{
    for (std::string &line : buffer_)
    {
        parse_line(line);
    }

    return 0;
};
int DayFour::part_02()
{
    return 0;
};
void DayFour::Run()
{
    part_01();
    part_02();
};

void DayFour::parse_line(const std::string &line)
{
    parse_date_time(line);
}

void DayFour::parse_date_time(const std::string &line)
{
    try
    {
        std::string::size_type start = line.find("[");
        std::string::size_type end = line.find("]");
        if (start != std::string::npos && end != std::string::npos && start < end)
        {
            std::istringstream iss(line.substr(start, end - start));
            std::tm tm = {};
            iss >> std::get_time(&tm, "%Y-%m-%d %T");
            if (ss)
        }
    }
    catch (const std::invalid_argument &e)
    {
        throw std::runtime_error("Error: invalid argument when converting to integer");
    }
    catch (const std::out_of_range &e)
    {
        throw std::runtime_error("Error: out of range when converting to integer");
    }
    catch (...)
    {
        throw std::runtime_error("Error: unexpected exception");
    }
}

std::string DayFour::parse_action(const std::string &line)
{
    std::string::size_type start = line.find("]");
    std::string::size_type end = line.size();
    return line.substr(start + 1, end);
}

void DayFour::process_action(const std::string &line, std::map<int, Guard> &guard_map)
{
    try
    {
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(e.what());
    }
}