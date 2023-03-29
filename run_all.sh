#!/usr/bin/env bash

set -euo pipefail

echo "" && time ./cpp/day01
echo "" && time ./cpp/day02
echo "" && time ./cpp/day02_short < data/day02.txt
echo "" && time ./cpp/day03;
echo "" && time ./cpp/day04;
