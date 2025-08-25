// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime.
//  However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.


class Solution {
    const long long MOD = 1e9 + 7;
public:
    int countGoodNumbers(long long n) {
        long long no_of_even_spaces = (n + 1) / 2; // even positions
        long long no_of_odd_spaces = n / 2;        // odd positions

        long long res1 = f(5, no_of_even_spaces);
        long long res2 = f(4, no_of_odd_spaces);

        return (res1 * res2) % MOD;
    }

    long long f(long long x, long long n) {
        if (n == 0) return 1;
        long long half = f(x, n / 2);
        long long result = (half * half) % MOD;
        if (n % 2) result = (result * x) % MOD;
        return result;
    }
};
