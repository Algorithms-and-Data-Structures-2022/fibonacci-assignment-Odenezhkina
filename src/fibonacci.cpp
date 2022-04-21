#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {
    if (n <= 1) {
      return n;
    }
    double sqrtFive = sqrt(5);
    double x1 = pow((1 + sqrtFive) / 2, n);
    double x2 = pow((1  - sqrtFive) / 2, n);
    double res = ((x1 - x2) / sqrtFive);
    return res;
  }

  int64_t fib_iterative(int n) {
    if (n <= 1) {
      return n;
    }
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    int res;
    for(int i = 1; i < n; i++){
      res = fib_curr + fib_prev;
      fib_prev = fib_curr;
      fib_curr = res;
    }
    return res;
  }

  int64_t fib_recursive(int n) {
    if(n <= 1){
      return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {
    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }
    cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
    return cache[n];
  }

  int64_t fib_matrix(int n) {
    if (n <= 1) {
      return n;
    }
    Matrix2x2 matrix = matrix_power(FibMatrix, n);
    return matrix[0][1];
  }

}  // namespace assignment
