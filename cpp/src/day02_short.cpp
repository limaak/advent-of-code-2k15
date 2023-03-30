#include <algorithm>
#include <iostream>
#include <string>

std::tuple<std::int32_t, std::int32_t> part_1_2()
{
    auto surface = 0;
    auto ribbon = 0;

    for (std::string line; std::getline(std::cin, line);)
    {
        std::size_t pos = 0;
        auto x = std::stoi(line, &pos, 10);
        auto s2 = line.substr(pos + 1);
        auto y = std::stoi(s2, &pos, 10);
        s2 = s2.substr(pos + 1);
        auto z = std::stoi(s2, &pos, 10);
        if (x > y)
            std::swap(x, y);
        if (y > z)
            std::swap(y, z);
        if (x > y)
            std::swap(x, y);
        surface += 2 * (x * y + y * z + x * z) + x * y;
        ribbon += 2 * (x + y) + x * y * z;
    }

    return std::make_tuple(surface, ribbon);
}

int main()
{
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    auto result = part_1_2();
    auto t2 = high_resolution_clock::now();

    printf("2015d2short\n");

    auto total_time = duration_cast<milliseconds>(t2 - t1);
    printf("part 1: %d [%lldms]\n", std::get<0>(result), total_time.count());
    printf("part 2: %d [%lldms]\n", std::get<1>(result), total_time.count());

    return 0;
}
