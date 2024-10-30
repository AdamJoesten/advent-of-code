#include <string>
#include <vector>

class SolutionBase
{
public:
    SolutionBase(const std::string &file_path);
    ~SolutionBase();
    void virtual Run() = 0;

protected:
    std::vector<std::string> buffer_;

private:
};