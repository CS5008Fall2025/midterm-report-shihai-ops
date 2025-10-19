[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/kdfTwECC)
# Midterm p1: Report on Analysis of Fibonacci  Series
* **Author**: Haisheng Shi
* **GitHub Repo**: [linke to github repo with this report]
* **Semester**: Fall 2025
* **Languages Used**: c, Python

> You are free to rename/ modify these sections as you need (and don't forget to remove this line..)

## Overview
This report focuses on the speed differences between different implementations of the Fibonacci Series. It is worth mentioning that this sequence was popularized to the Western world by Leonardo of Pisa, or Fibonacci, in the early 13th century, but its concept appeared in Indian mathematics centuries ago.

The Fibonacci sequence is a sequence of integers in which each number is the sum of the two preceding numbers. Usually the first two terms F(0) = 0 and F(1) = 1 start. Its mathematical expression is: 

$$F_n = F_{n-1} + F_{n-2}$$

The first 10 numbers of the sequence as follows:0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
There are many ways we can implement the Fibonacci sequence in code, which will be discussed in detail below. The algorithm complexity (Big O) for the various implementations used in this report is shown in the table below:
| Version |  Big O | Space Used | 
| :-- | :-- |  :-- |
| Iterative | $O(n)$ | $O(1)$ |
| Recursive | $O(2^n)$  | $O(n)$ |
| Dynamic Programming | $O(n)$ | $O(n)$ |

The iterative version uses only one loop, calculating each number from scratch, so the time complexity is O(n). It only needs to store the first two digits, so the spatial complexity is O(1). The pseudocode for the recursive version is as follows:
```Plaintext
Function Fib(n)
    if n <= 1: return n
    return Fib(n - 1) + Fib(n - 2)
```
To compute Fib(n), the function calls Fib(n-1) and Fib(n-2). These two calls each generate more calls, resulting in exponential increases in the number of calculations. This results in a time complexity of O(2 
n), but since the depth of the call stack is up to n, the spatial complexity is O(n).

The dynamic planning version stores the calculation results for each Fib(i) (a process called "memory"). When a value is needed again, it can be fetched directly from storage at constant time without recalculation. This effectively cuts out the duplicate recursive branches, reducing time complexity to O(n) at the cost of requiring O(n) of space to store the results.

For this analysis, I chose Python as my second language. Aside from being a well-known language, the main reason is that it provides auxiliary functions such as lru_cache and cache in the built-in FuncTools library, greatly simplifying the implementation of dynamic programming. Moreover, it is the language I am most familiar with. This makes it easy for me to experiment with these built-in tools while using a language designed for rapid development and experimentation.

## Empirical Data & Discussion 


## Language Analysis


### Language 1: C



### Language 2: UPDATE



### Comparison and Discussion Between Experiences


## Conclusions / Reflection

## References

