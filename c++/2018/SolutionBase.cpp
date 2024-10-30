#include "SolutionBase.hpp"

#include <filesystem>
#include <fstream>

SolutionBase::SolutionBase(const std::string &file_path) : buffer_()
{
    std::filesystem::path path(file_path);
    std::ifstream fileHandle(path);

    if (!fileHandle)
    {
        throw std::runtime_error("Could not open file at " + path.string());
    }

    std::string line;
    while (getline(fileHandle, line))
    {
        buffer_.push_back(line);
    }

    fileHandle.close();
}

SolutionBase::~SolutionBase()
{
    printf("SolutionBase was destructed...\n");
}
