#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    int surface = 0;
    int ribbon = 0;

    printf("2015d2_short\n");
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

    printf("part 1: %d\n", surface);
    printf("part 2: %d\n", ribbon);

    return 0;
}
