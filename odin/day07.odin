package main

import "core:fmt"
import "core:strings"
import "core:os"
import "core:strconv"
import "core:time"

main :: proc() {
	op_map := make(map[string][]string)
	defer delete(op_map)

	data, ok := os.read_entire_file("../data/day07.txt", context.allocator)
	defer delete(data, context.allocator)

	it := string(data)
	for line in strings.split_lines_iterator(&it) {
		ss := strings.split(line, " -> ")

		operation := ss[0]
		provided_to := ss[1]

		op_map[provided_to] = strings.split(operation, " ")
	}

	fmt.println(op_map)

	// stop := false;
	// for ; !stop; {
	//     for key, value in op_map {
	//         if len(value) == 1 {
	//             fmt.println(value);
	//         }
	//     }
	//     time.accurate_sleep(512 * time.Millisecond);
	// }
}
