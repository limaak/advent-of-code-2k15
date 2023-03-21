#!/usr/bin/env bash

set -euo pipefail

echo "" && time ./cpp/day01
echo "" && time ./cpp/day02
echo "" && time ./cpp/day02_fast < data/day02.txt
