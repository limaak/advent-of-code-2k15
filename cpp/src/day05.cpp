#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>

// TODO:
// - part 2
// - try to rewrite day 5 using regexes

namespace
{
const std::unordered_map<char, bool> allowed_chars = {
    {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
};
const std::unordered_map<std::string, bool> disallowed_strings = {
    {"ab", true},
    {"cd", true},
    {"pq", true},
    {"xy", true},
};
} // namespace

bool is_string_valid_1(const std::string &str)
{
    auto vowel_count = 0;
    auto repeating_count = 0;
    auto had_disallowed_string = false;

    for (size_t i = 0; i < str.size(); ++i)
    {
        char current_char = str[i];
        std::string current_substring{str[i], str[i + 1]};

        if (allowed_chars.count(current_char))
            ++vowel_count;

        if (str[i] == str[i + 1])
            ++repeating_count;

        had_disallowed_string = disallowed_strings.count(current_substring);

        if (had_disallowed_string)
            return false;
    }

    return (vowel_count >= 3 && repeating_count >= 1);
}

bool is_string_valid_2(const std::string &str)
{
    bool has_in_between = false;
    bool has_two_pairs = false;

    std::string previous_pair = "";
    std::unordered_map<std::string, int> pair_count;

    for (size_t i = 0; i < str.size() - 1; ++i)
    {
        const auto pair = str.substr(i, 2);

        if (previous_pair != pair || previous_pair == str.substr(i + 1, 2) /* i.e aaaa */)
        {
            pair_count[pair] += 1;
            has_two_pairs = (pair_count[pair] == 2);
        }

        if (has_two_pairs)
            break;

        previous_pair = pair;
    }

    for (size_t i = 0; i < str.size() - 2; ++i)
    {
        const auto triple = str.substr(i, 3);
        has_in_between = (triple[0] == triple[2]);

        if (has_in_between)
            break;
    }

    return has_in_between && has_two_pairs;
}

int main()
{
    std::int32_t count_1 = 0;
    std::int32_t count_2 = 0;
    for (std::string line; std::getline(std::cin, line);)
    {
        count_1 += is_string_valid_1(line);
        count_2 += is_string_valid_2(line);
    }

    printf("part 1: %d\n", count_1);
    printf("part 2: %d\n", count_2);
    return 0;
}
