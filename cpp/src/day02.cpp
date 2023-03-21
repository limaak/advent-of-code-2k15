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
  explicit box(int length, int width, int height)
      : l(length), w(width), h(height) {}
  int l = 0;
  int w = 0;
  int h = 0;
};

std::int32_t calculate_surface_area(box *b) {
  if (b == nullptr)
    return 0;

  const auto area_a = (2 * b->l * b->w);
  const auto area_b = (2 * b->w * b->h);
  const auto area_c = (2 * b->h * b->l);
  const auto total_area = area_a + area_b + area_c;

  return total_area + (std::min({area_a, area_b, area_c}) / 2);
}

std::int32_t calculate_ribbon_area(box *b) {
  if (b == nullptr)
    return 0;

  const auto face_a = (2 * b->l + 2 * b->w);
  const auto face_b = (2 * b->w + 2 * b->h);
  const auto face_c = (2 * b->l + 2 * b->h);
  const auto ribbon = b->l * b->w * b->h;

  return ribbon + std::min({face_a, face_b, face_c});
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
    if (lwh.size() == 3) {
      const auto l = std::stoi(lwh[0]);
      const auto w = std::stoi(lwh[1]);
      const auto h = std::stoi(lwh[2]);
      box_vec.push_back(new box(l, w, h));
    }
  }

  printf("2015d2\n");

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
