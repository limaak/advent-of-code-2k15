package main

import "core:fmt"
import "core:strings"
import "core:strconv"
import "core:os"

main :: proc() {
	data, ok := os.read_entire_file("../data/day02.txt", context.allocator)
	defer delete(data, context.allocator)

	it := string(data)
	result := 0
	for line in strings.split_lines_iterator(&it) {
		ss := strings.split(line, "x")

		l, _ := strconv.parse_int(ss[0])
		w, _ := strconv.parse_int(ss[1])
		h, _ := strconv.parse_int(ss[2])

		result += 2 * l * w + 2 * w * h + 2 * h * l + min(l * w, w * h, h * l)
	}

	fmt.printf("Part 1: %d\n", result);
}
