#include "SolutionThree.hpp"

#include <tuple>
#include <cstring>
#include <stdexcept>

SolutionThree::SolutionThree(const std::string &file_path) : SolutionBase(file_path) {};

SolutionThree::~SolutionThree()
{
    printf("SolutionThree was destructed...\n");
};

int SolutionThree::part_01()
{
    std::vector<std::vector<int>> grid(1000, std::vector<int>(1000, 0));
    int result = 0;
    for (std::string line : buffer_)
    {
        printf("line: %s\n", line.c_str());
        if (auto parsed_line = parse_line(line))
        {
            auto [id, coordinates, dimensions] = parsed_line.value();
            int row_start = coordinates[0];
            int col_start = coordinates[1];

            int row_range = dimensions[0];
            int col_range = dimensions[1];

            int row_end = row_start + row_range;
            int col_end = col_start + col_range;

            // printf("id: %d\n", id);
            // printf("row_start: %d\n", row_start);
            // printf("col_start: %d\n", col_start);
            // printf("row_range: %d\n", row_range);
            // printf("col_range: %d\n", col_range);
            // printf("row_end: %d\n", row_end);
            // printf("col_end: %d\n", col_end);
            // int patch_size = 0;
            for (int x = row_start; x < row_end; x++)
            {
                for (int y = col_start; y < col_end; y++)
                {
                    // patch_size += 1;
                    if (grid.size() <= x)
                    {
                        std::vector<int> row(1000);
                        grid.push_back(row);
                    }
                    if (grid.at(x).size() <= y)
                    {
                        for (int x = 0; x < 1000; x += 1)
                        {
                            grid.at(x).emplace_back(0);
                        }
                    }
                    grid.at(x).at(y)++;
                    if (grid.at(x).at(y) == 2)
                    {
                        result++;
                    }
                }
            }
            // printf("patch_size: %d\n", patch_size);
            // patch_size = 0;
        }
    }
    return result;
}

int SolutionThree::part_02()
{
    std::vector<std::vector<int>> grid(1000, std::vector<int>(1000, 0));
    int result = 0;
    for (std::string line : buffer_)
    {
        printf("line: %s\n", line.c_str());
        if (auto parsed_line = parse_line(line))
        {
            auto [id, coordinates, dimensions] = parsed_line.value();
            int row_start = coordinates[0];
            int col_start = coordinates[1];

            int row_range = dimensions[0];
            int col_range = dimensions[1];

            int row_end = row_start + row_range;
            int col_end = col_start + col_range;

            for (int x = row_start; x < row_end; x++)
            {
                for (int y = col_start; y < col_end; y++)
                {
                    if (grid.size() <= x)
                    {
                        std::vector<int> row(1000);
                        grid.push_back(row);
                    }
                    if (grid.at(x).size() <= y)
                    {
                        for (int x = 0; x < 1000; x += 1)
                        {
                            grid.at(x).emplace_back(0);
                        }
                    }
                    grid.at(x).at(y)++;
                }
            }
        }
    }
    for (std::string line : buffer_)
    {
        if (auto parsed_line = parse_line(line))
        {
            auto [id, coordinates, dimensions] = parsed_line.value();
            int row_start = coordinates[0];
            int col_start = coordinates[1];

            int row_range = dimensions[0];
            int col_range = dimensions[1];

            int row_end = row_start + row_range;
            int col_end = col_start + col_range;
            int flag = 0;
            for (int x = row_start; x < row_end; x++)
            {
                for (int y = col_start; y < col_end; y++)
                {
                    if (grid.at(x).at(y) > 1) {
                        flag = 1;
                    } 
                }
            }
            if (flag == 0) {
                result = id;
                break;
            }
        }
    }
    return result;
}

void SolutionThree::Run()
{
    int part_01_result = part_01();
    printf("day_03 part one: %d\n", part_01_result);
    int part_02_result = part_02();
    printf("day_03 part two: %d\n", part_02_result);
}

std::vector<std::string> SolutionThree::tokenize(const std::string &input, std::string del)
{
    std::vector<std::string> split_input;
    int start, idx = 0, end = -1 * del.size();
    do
    {
        start = end + del.size();
        end = input.find(del, start);
        split_input.push_back(input.substr(start, end - start));
        idx++;
    } while (end != std::string::npos);
    return split_input;
}

std::optional<std::tuple<int, std::vector<int>, std::vector<int>>> SolutionThree::parse_line(std::string raw_input)
{
    std::vector<std::string> split_input = tokenize(raw_input);
    int id = std::stoi(split_input[0].substr(1));
    std::vector<std::string> coordinates = tokenize(split_input[2], ",");
    std::vector<std::string> dimensions = tokenize(split_input[3], "x");

    return std::make_tuple(
        id,
        std::vector<int>{
            std::stoi(coordinates[1], nullptr, 10),  // distance from top (row)
            std::stoi(coordinates[0], nullptr, 10)}, // distance from left (col)
        // flip dimensions to match coordinates
        std::vector<int>{
            std::stoi(dimensions[1], nullptr, 10),
            std::stoi(dimensions[0], nullptr, 10)});
}