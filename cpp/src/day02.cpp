#include <chrono>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr auto input_file_path = "../data/day02.txt";

std::vector<std::string> split_on(const std::string &str, char delimeter) {
  std::vector<std::string> result;
  std::stringstream ss(str);
  std::string item;

  while (getline(ss, item, delimeter)) {
    result.push_back(item);
  }

  return result;
}
} // namespace

struct box {
  box(int length, int width, int height) : l(length), w(width), h(height) {}
  int l = 0;
  int w = 0;
  int h = 0;
};

std::int32_t calculate_surface_area(box *b) {
  if (b == nullptr)
    return 0;

  auto x = 2 * b->l * b->w;
  auto y = 2 * b->w * b->h;
  auto z = 2 * b->h * b->l;

  return x + y + z + (std::min({x, y, z}) / 2);
}

std::int32_t calculate_ribbon_area(box *b) {
  if (b == nullptr)
    return 0;

  auto x = 2 * b->l + 2 * b->w;
  auto y = b->l * b->w * b->h;

  return x + y;
}

std::int32_t part_1(const std::vector<box *> &box_vec) {
  auto sum = 0;

  for (auto box : box_vec)
    sum += calculate_surface_area(box);

  return sum;
}

std::int32_t part_2(const std::vector<box *> &box_vec) {
  auto sum = 0;

  for (auto box : box_vec)
    sum += calculate_ribbon_area(box);

  return sum;
}

int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  std::ifstream f(input_file_path);

  std::vector<box *> box_vec;

  for (std::string line; std::getline(f, line);) {
    const auto lwh = split_on(line, 'x');
    const auto l = std::stoi(lwh[0]);
    const auto w = std::stoi(lwh[1]);
    const auto h = std::stoi(lwh[2]);
    box_vec.push_back(new box(l, w, h));
  }

  // Part 1
  {
    auto t1 = high_resolution_clock::now();
    auto result = part_1(box_vec);
    auto t2 = high_resolution_clock::now();

    auto total_time = duration_cast<milliseconds>(t2 - t1);
    printf("part 1: %d [%lldms]\n", result, total_time.count());
  }

  // Part 2
  {
    auto t1 = high_resolution_clock::now();
    auto result = part_2(box_vec);
    auto t2 = high_resolution_clock::now();

    auto total_time = duration_cast<milliseconds>(t2 - t1);
    printf("part 2: %d [%lldms]\n", result, total_time.count());
  }

  return 0;
}
