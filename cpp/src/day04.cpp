#include "md5.h"

namespace
{
const std::string input = "bgvyzdsv";
} // namespace

std::tuple<std::int32_t, std::int32_t> part_1_2()
{
    auto p1 = 0;
    auto p2 = 0;
    bool p1_done = false;
    bool p2_done = false;

    for (std::int32_t i = 100000; i <= 9999999; ++i)
    {
        const std::string x = md5(input + std::to_string(i));

        if (!p1_done)
        {
            if (x.substr(0, 5) == "00000")
            {
                p1 = i;
                p1_done = true;
            }
        }

        if (!p2_done)
        {
            if (x.substr(0, 6) == "000000")
            {
                p2 = i;
                p2_done = true;
            }
        }

        if (p1_done && p2_done)
            break;
    }

    return std::make_tuple(p1, p2);
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

    printf("2015d4short\n");

    auto total_time = duration_cast<milliseconds>(t2 - t1);
    printf("part 1: %d [%lldms]\n", std::get<0>(result), total_time.count());
    printf("part 2: %d [%lldms]\n", std::get<1>(result), total_time.count());

    return 0;
}
