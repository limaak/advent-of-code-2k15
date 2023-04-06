#include <cstdio>
#include <iostream>
#include <regex>
#include <string>
#include <tuple>

enum class Type
{
    TurnOn,
    TurnOff,
    Toggle,
    None,
};

Type str_to_enum(const std::string &str)
{
    if (str == "turn on")
        return Type::TurnOn;
    if (str == "turn off")
        return Type::TurnOff;
    if (str == "toggle")
        return Type::Toggle;
    return Type::None;
}

struct light
{
    bool is_turned_on = false;
    int brightness = 0;
};

template <size_t row, size_t column>
void handle_turn_on(std::pair<int, int> from, std::pair<int, int> through, struct light (&matrix)[row][column])
{
    for (auto i = from.first; i <= through.first; ++i)
    {
        for (auto j = from.second; j <= through.second; ++j)
        {
            matrix[i][j].is_turned_on = true;
            matrix[i][j].brightness += 1;
        }
    }
}

template <size_t row, size_t column>
void handle_turn_off(std::pair<int, int> from, std::pair<int, int> through, struct light (&matrix)[row][column])
{
    for (auto i = from.first; i <= through.first; ++i)
    {
        for (auto j = from.second; j <= through.second; ++j)
        {
            matrix[i][j].is_turned_on = false;
            matrix[i][j].brightness -= matrix[i][j].brightness == 0 ? 0 : 1;
        }
    }
}

template <size_t row, size_t column>
void handle_toggle(std::pair<int, int> from, std::pair<int, int> through, struct light (&matrix)[row][column])
{
    for (auto i = from.first; i <= through.first; ++i)
    {
        for (auto j = from.second; j <= through.second; ++j)
        {
            matrix[i][j].is_turned_on = matrix[i][j].is_turned_on ? false : true;
            matrix[i][j].brightness += 2;
        }
    }
}

template <size_t row, size_t column> std::pair<int, int> count(struct light (&matrix)[row][column])
{
    int total_lit = 0;
    int total_brightness = 0;

    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            if (matrix[i][j].is_turned_on)
                total_lit += 1;

            total_brightness += matrix[i][j].brightness;
        }
    }

    return {total_lit, total_brightness};
}

int main()
{
    struct light matrix[1000][1000];

    // TODO: simplify me please.
    const std::regex regexp("(turn on|turn off|toggle|) (\\d+),(\\d+) through (\\d+),(\\d+)");

    for (std::string line; std::getline(std::cin, line);)
    {
        std::smatch matches;

        std::regex_search(line, matches, regexp);

        const auto type = str_to_enum(matches[1]);
        const auto from = std::make_pair(std::stoi(matches[2]), std::stoi(matches[3]));
        const auto through = std::make_pair(std::stoi(matches[4]), std::stoi(matches[5]));

        switch (type)
        {
        case Type::TurnOn:
            handle_turn_on(from, through, matrix);
            break;
        case Type::TurnOff:
            handle_turn_off(from, through, matrix);
            break;
        case Type::Toggle:
            handle_toggle(from, through, matrix);
            break;
        default:
            break;
        }
    }

    const auto total_count = count(matrix);

    printf("part 1: %d\n", total_count.first);
    printf("part 2: %d\n", total_count.second);

    return 0;
}
