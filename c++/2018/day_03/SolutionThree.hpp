#include "../SolutionBase.hpp"

#include <vector>
#include <string>
#include <optional>

class SolutionThree : public SolutionBase
{
public:
    SolutionThree(const std::string &file_path);
    ~SolutionThree();
    std::vector<std::string> tokenize(const std::string &input, std::string del = " ");
    std::optional<std::tuple<int, std::vector<int>, std::vector<int>>> parse_line(std::string raw_input);
    int part_01();
    int part_02();
    void Run();
};
