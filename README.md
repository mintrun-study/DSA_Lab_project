# DSA Lab Project — Sorting Algorithms

## Overview

This is my Sorting Algorithms project in **Data Structure and Algorithms** course in **HCMUS**, which is supervised by Tran Thi Thao Nhi and Tran Hoang Quan. In this project, we implement several sorting algorithms (from $O(n^2)$ to $O(nlog(n))$ and $O(n)$ ) and analyze their performance across different data distributions.

## Features

- To improve running time of selection sort, which every case is $O(n^2)$, we decide to make an optimized Selection Sort. Instead of traversing and sorting from one way, now in this algorithm, we prefer making it two ways. 

- The repository provides implementations of various algorithms in one of the most fundamental general purpose languages C++

## Compile
```bash
g++ *.cpp -std=c++14 -o 02.exe
```

## File Structure
- `main.cpp` — entry point, parses CLI arguments and calls the appropriate command
- `sort.h / sort.cpp` — implements 12 sorting algorithms, each tracking comparison count
- `time.h/time.cpp` - implements 12 sorting algorithms, without comparison count, for improve running time
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
```

## Examples
```bash
02.exe -a merge-sort input.txt -both
02.exe -a heap-sort 100000 -rand -time
02.exe -a quick-sort 50000 -both
02.exe -c merge-sort heap-sort input.txt
02.exe -c quick-sort merge-sort 100000 -rand
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

## Credit
You are free to use my code to do whatever you want unless you want to use it for your report in **Data Structures and Algorithms** course in **HCMUS**, you have to credit me.
