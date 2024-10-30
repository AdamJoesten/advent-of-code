#include "DayFour.hpp"
#include <string>
#include <tuple>
#include <stdexcept>
#include <map>

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
    std::vector<std::tuple<long long, std::string>> parsed;
    for (std::string &line : buffer_)
    {
        parsed.push_back(parse_line(line));
    }
    std::sort(parsed.begin(), parsed.end(), sort_function);
    std::map<int, Guard> guard_map;
    for (std::tuple<long long, std::string> data : parsed)
    {
        printf("ll: %lld\n", std::get<0>(data));
        printf("action: %s\n", std::get<1>(data).c_str());
        process_action(std::get<1>(data), guard_map);
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

std::tuple<long long, std::string> DayFour::parse_line(const std::string &line)
{
    std::tuple<long long, std::string> result;
    long long sort_number = parse_date_time(line);
    std::string action = parse_action(line);
    std::get<0>(result) = sort_number;
    std::get<1>(result) = action;
    return result;
}

long long DayFour::parse_date_time(const std::string &line)
{
    try
    {
        std::string::size_type start = line.find("[") + 1;
        std::string::size_type end = line.find("]");
        std::string substr = line.substr(start, end - start);
        std::string stripped_str;

        printf("substr: %s\n", substr.c_str());
        for (int x = 0; x < substr.size(); x += 1)
        {
            if ((std::isdigit(substr[x])))
            {
                stripped_str.push_back(substr[x]);
            }
        }
        printf("stripped_str: %s\n", stripped_str.c_str());
        return std::stoll(stripped_str);
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
        if (line.find("Guard") != std::string::npos)
        {
            
        }
        else if (line.find("wakes") != std::string::npos)
        {
        }
        else if (line.find("falls") != std::string::npos)
        {
        }
        else
        {
            throw std::runtime_error("Error: unexpected action type");
        }
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(e.what());
    }
}

// std::vector<std::string> DayFour::split(const std::string &line, std::string del)
// {
//     std::vector<std::string> result;
//     size_t start = 0;
//     size_t end = 0;

//     while ((end = line.find(del, start)) != std::string::npos)
//     {
//         result.push_back(line.substr(start, end - start));
//         start = end + del.size();
//     }
//     result.push_back(line.substr(start));
//     return result;
// }