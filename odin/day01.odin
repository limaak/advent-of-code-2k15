package main

import "core:fmt"
import "core:strings"

data :: #load("../data/day01.txt", string)

main :: proc() {
	acc := 0
	callback :: proc(p: rawptr, r: rune) -> bool {
		acc := transmute(^int)p
		add := 1 if r == '(' else -1
		acc^ += add
		return acc^ < -1
	}
	result_1 := strings.count(data, "(") - strings.count(data, ")")
	result_2 := strings.index_proc_with_state(data, callback, &acc)

	fmt.printf("Part 1 %d\n", result_1)
	fmt.printf("Part 2 %d\n", result_2)
}
