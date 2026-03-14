# DSA Lab Project — Sorting Algorithms

## Overview

This is our Sorting Algorithms project for the **Data Structures and Algorithms** course at **HCMUS**, under the supervision of Tran Thi Thao Nhi and Tran Hoang Quan. In this project, we implement and benchmark 12 sorting algorithms ranging from $O(n^2)$ to $O(n\log n)$ and $O(n)$, analyzing their performance across different input sizes and data distributions.

## Features

- To improve running time of selection sort, which every case is $O(n^2)$, we decide to make an optimized Selection Sort. Instead of traversing and sorting from one way, now in this algorithm, we prefer making it two ways. 

- The repository provides implementations of various algorithms in one of the most fundamental general purpose languages C++.

- Each sorting algorithm has two versions: one with comparison counting (`sort.cpp`) and one without (`time.cpp`). When `-time` is used, the program runs the faster version to get more accurate running time measurements.

- **Command `-all`**: Automatically runs all 12 algorithms on the same dataset and prints a ranking from fastest to slowest, both by running time and by number of comparisons.

## Compile
```bash
g++ *.cpp -std=c++14 -o 02.exe
```

## File Structure
- `main.cpp` — entry point, parses CLI arguments and calls the appropriate command
- `sort.h / sort.cpp` — implements 12 sorting algorithms, each tracking comparison count
- `time.h / time.cpp` - implements 12 sorting algorithms, without comparison count, to improve running time
- `process.h / process.cpp` — handles 5 commands, file I/O, and data generation

## Algorithms
`selection-sort`, `insertion-sort`, `binary-insertion-sort`, `bubble-sort`, `shaker-sort`, `shell-sort`, `heap-sort`, `merge-sort`, `quick-sort`, `counting-sort`, `radix-sort`, `flash-sort`

## Commands

```bash
# Command 1: Run on existing file
02.exe -a [algo] [file] [-time/-comp/-both]

# Command 2: Generate data then run
02.exe -a [algo] [size] [order] [-time/-comp/-both]

# Command 3: Run on all 4 data orders
02.exe -a [algo] [size] [-time/-comp/-both]

# Command 4: Compare 2 algorithms on existing file
02.exe -c [algo1] [algo2] [file]

# Command 5: Compare 2 algorithms on generated data
02.exe -c [algo1] [algo2] [size] [order]

# Command All: Run all 12 algorithms and print ranking
02.exe -all [size] [order] [-time/-comp/-both]
```

## Examples
```bash
02.exe -a merge-sort input.txt -both
02.exe -a heap-sort 100000 -rand -time
02.exe -a quick-sort 50000 -both
02.exe -c merge-sort heap-sort input.txt
02.exe -c quick-sort merge-sort 100000 -rand
02.exe -all 100000 -rand -both
02.exe -all 50000 -sorted -time
```

## Parameters

| Flag | Description |
|---|---|
| `-rand` | Random order |
| `-sorted` | Ascending order |
| `-rev` | Descending order |
| `-nsorted` | Nearly sorted |
| `-time` | Print running time (ms) |
| `-comp` | Print comparison count |
| `-both` | Print both |

## Command All
Runs all 12 algorithms on the same generated dataset and prints a ranking from best to worst.

```
02.exe -all 50000 -rand -both
```

Output:
```
ALGORITHM MODE
Input size: 50000
Input order: Randomize

Selection Sort Optimize:
-------------------------
Running time: ... ms
Comparisons: ...

...

RANKING
-------------------------
By Running Time:
1. Counting Sort: 0.4261 ms
2. Flash Sort: 0.9361 ms
3. Radix Sort: 1.146 ms
...
12. Bubble Sort: 9823.45 ms

By Comparisons:
1. Counting Sort: 115538
2. Flash Sort: 432752
3. Radix Sort: 600164
...
```

## Credit
This repository is intended for educational purposes. You are welcome to reference or use our code freely, provided that you do not submit it as your own work in the **Data Structures and Algorithms** course at **HCMUS**. If you use any part of this project in your report or submission, proper credit must be given.