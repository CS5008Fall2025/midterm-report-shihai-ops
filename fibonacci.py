# fibonacci.py

from enum import Enum
from functools import lru_cache
import argparse
import sys
import time
from typing import Callable

sys.setrecursionlimit(100000)


OPS = 0


class FibType(Enum):
    ITERATIVE_DP_TOGETHER = 4
    ALL = 3
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0


@lru_cache(maxsize=None)
def fib_dp(n: int) -> int:
    if n < 2:
        return n
    global OPS
    OPS += 1
    return fib_dp(n - 1) + fib_dp(n - 2)


def fib_r(n: int) -> int:
    if n < 2:
        return n
    global OPS
    OPS += 1
    return fib_r(n - 1) + fib_r(n - 2)


def fib_iterative(n: int) -> int:
    global OPS
    a, b = 0, 1
    if n < 2:
        return n

    for _ in range(n - 1):
        OPS += 1
        a, b = b, a + b
    return b


def run_and_time(func: Callable, n: int, print_it: bool = False):
    global OPS
    OPS = 0
    start = time.perf_counter()
    result = func(n)
    end = time.perf_counter()
    if print_it:
        print(f"Fib({n}) = {result}")
    return end - start, OPS


def main(n: int, algo: FibType, print_it: bool):
    if algo == FibType.ITERATIVE_DP_TOGETHER:
        time_i, ops_i = run_and_time(fib_iterative, n)
        time_dp, ops_dp = run_and_time(fib_dp, n)
        print(f"{time_i:0.6f},{ops_i},{time_dp:0.6f},{ops_dp},-,-")

    elif algo == FibType.ALL:
        time_i, ops_i = run_and_time(fib_iterative, n)
        time_dp, ops_dp = run_and_time(fib_dp, n)
        time_r, ops_r = run_and_time(fib_r, n)
        print(f"{time_i:0.6f},{ops_i},{time_dp:0.6f},{ops_dp},{time_r:0.6f},{ops_r}")

    else:
        func_map = {
            FibType.ITERATIVE: ("Iterative Version", fib_iterative),
            FibType.RECURSIVE: ("Recursive Version", fib_r),
            FibType.DP: ("Dynamic Programming Version", fib_dp)
        }
        if algo in func_map:
            name, func_to_run = func_map[algo]
            if print_it:
                print(name)
            time, ops = run_and_time(func_to_run, n, print_it)
            if print_it:
                print(f"Time: {time:0.6f}s, Operations: {ops}")
        else:
            print("Unknown algorithm type.", file=sys.stderr)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Fibonacci Sequence Calculator")
    parser.add_argument("n", type=int, help="The nth number to generate in the sequence")
    parser.add_argument(
        "algo",
        type=int,
        choices=[0, 1, 2, 3, 4],
        help="The algorithm to use: 0=iterative, 1=recursive, 2=dp, 3=all, 4=iterative and dp together",
    )
    parser.add_argument(
        "--print", action="store_true", default=False, help="Print the generated number and details"
    )

    args = parser.parse_args()
    algo = FibType(args.algo)
    main(args.n, algo, args.print)