#!/usr/bin/env bash

set -euo pipefail

odin build day01.odin -file -o:speed
odin build day07.odin -file -o:speed
