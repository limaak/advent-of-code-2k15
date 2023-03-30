#include "md5.h"

int main()
{
    const std::string input = "bgvyzdsv";
    bool p1_done = false;
    bool p2_done = false;

    for (int i = 100000; i <= 9999999; ++i)
    {
        const std::string x = md5(input + std::to_string(i));

        if (!p1_done)
        {
            if (x.substr(0, 5) == "00000")
            {
                printf("p1: %d\n", i);
                p1_done = true;
            }
        }

        if (!p2_done)
        {
            if (x.substr(0, 6) == "000000")
            {
                printf("p2: %d", i);
                p2_done = true;
            }
        }

        if (p1_done && p2_done)
            break;
    }

    return 0;
}
