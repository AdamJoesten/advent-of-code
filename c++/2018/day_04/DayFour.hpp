#include "../SolutionBase.hpp"

#include <vector>
#include <string>
#include <optional>
#include <map>

struct Guard
{
    int total_slept;
    std::map<int, int> sleep_map;
};

class DayFour : public SolutionBase
{
public:
    DayFour(const std::string &file_path);
    ~DayFour();
    int part_01();
    int part_02();
    void Run();

private:
    void parse_line(const std::string &line);
    void parse_date_time(const std::string &line);
    std::string parse_action(const std::string &line);
    void process_action(const std::string &line, std::map<int, Guard> &guard_map);
};
