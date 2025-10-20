#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX 10000

typedef uint64_t ull;

static ull table[MAX] = {0};


ull fib_iterative(int n, ull *ops) {
    if (n < 2) {
        return n;
    }
    ull a = 0;
    ull b = 1;
    ull c;
    for (int i = 2; i <= n; i++) {
        (*ops)++;
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


ull fib_recursive(int n, ull *ops) {
    if (n < 2) {
        return n;
    }
    (*ops)++;
    return fib_recursive(n - 1, ops) + fib_recursive(n - 2, ops);
}


ull fib_dp(int n, ull *ops) {
    if (n < 2) {
        return n;
    }

    if (table[n] > 0) {
        return table[n];
    }

    (*ops)++;

    table[n] = fib_dp(n - 1, ops) + fib_dp(n - 2, ops);
    return table[n];
}


double time_function(ull (*func)(int, ull *), int n, ull *ops, bool print) {

    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    ull result = func(n, ops);
    clock_gettime(CLOCK_MONOTONIC, &end);

    if (print) {
        printf("Result: %lu\n", result);
    }


    return (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
}

void help() {
    printf("Usage: ./fibonacci.out N [Type] [Print]\n");
    printf("\tN: The index in the Fibonacci sequence to calculate (required).\n");
    printf("\t[Type]: 4 for DP and iterative, 3 for all, 2 for DP, 1 for recursive, 0 for iterative. Defaults to 3.\n");
    printf("\t[Print]: Any third argument (e.g., 'print') to print the result row.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Missing required argument N.\n");
        help();
        return 1;
    }

    const int n = atoi(argv[1]);
    if (n >= MAX) {
        fprintf(stderr, "Error: N must be less than %d to avoid stack overflow and table bounds.\n", MAX);
        return 1;
    }

    int type = 3;
    if (argc > 2) {
        type = atoi(argv[2]);
    }

    bool print = false;
    if (argc > 3) {
        print = true;
    }

    ull ops;
    double time;
    switch (type) {
    case 0:
        if(print) printf("Iterative version\n");
        ops = 0;
        time = time_function(fib_iterative, n, &ops, print);
        printf("time: %f(%lu)\n", time, ops);
        break;
    case 1:
        if(print) printf("Recursive version\n");
        ops = 0;
        time = time_function(fib_recursive, n, &ops, print);
        printf("time: %f(%lu)\n", time, ops);
        break;
    case 2:
        if(print) printf("Dynamic Programming version\n");
        ops = 0;
        time = time_function(fib_dp, n, &ops, print);
        printf("time: %f(%lu)\n", time, ops);
        break;
    case 4:
        ops = 0;
        time = time_function(fib_iterative, n, &ops, false);
        printf("%f,%lu,", time, ops);

        ops = 0;
        time = time_function(fib_dp, n, &ops, false);
        printf("%f,%lu,-,-", time, ops);
        break;
    default:
        ops = 0;
        time = time_function(fib_iterative, n, &ops, false);
        printf("%f,%lu,", time, ops);

        ops = 0;
        time = time_function(fib_dp, n, &ops, false);
        printf("%f,%lu,", time, ops);

        ops = 0;
        time = time_function(fib_recursive, n, &ops, false);
        printf("%f,%lu", time, ops);
        break;
    }
    printf("\n");
    return 0;
}