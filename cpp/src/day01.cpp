#include <chrono>
#include <cstdio>
#include <fstream>
#include <sstream>

namespace
{
constexpr auto input_file_path = "../data/day01.txt";
} // namespace

std::int32_t part_1(const std::string &buffer)
{
    auto count = 0;
    for (size_t i = 0; i < buffer.size(); ++i)
    {
        if (buffer[i] == '(')
            count++;
        if (buffer[i] == ')')
            count--;
    }

    return count;
}

std::int32_t part_2(const std::string &buffer)
{
    auto count = 0;
    for (size_t i = 0; i < buffer.size(); ++i)
    {
        if (buffer[i] == '(')
            count++;
        if (buffer[i] == ')')
            count--;
        if (count < 0)
            return i + 1;
    }

    return count;
}

int main()
{
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;

    std::ifstream f(input_file_path);
    std::stringstream buffer;

    buffer << f.rdbuf();

    const auto str_buff = buffer.str();

    printf("2015d1\n");

    // Part 1
    {
        auto t1 = high_resolution_clock::now();
        auto result = part_1(str_buff);
        auto t2 = high_resolution_clock::now();

        auto total_time = duration_cast<milliseconds>(t2 - t1);
        printf("part 1: %d [%lldms]\n", result, total_time.count());
    }

    // Part 2
    {
        auto t1 = high_resolution_clock::now();
        auto result = part_2(str_buff);
        auto t2 = high_resolution_clock::now();

        auto total_time = duration_cast<milliseconds>(t2 - t1);
        printf("part 2: %d [%lldms]\n", result, total_time.count());
    }

    return 0;
}
