#include <bits/stdc++.h>

using namespace std;

/*
Initialization:

Create a list of consecutive integers from 2 to 
n: (2, 3, 4, ..., n).
This list will be used to track numbers that are not eliminated; those that remain will be the prime numbers.
First Prime:

Start with the first prime number in the list, which is 2. This is the first prime number.
Eliminate Multiples:

Remove all multiples of 2 (excluding 2 itself) from the list. This means numbers: 4, 6, 8, 10, and so on, are removed.

The algorithm terminates when the square of the next prime exceeds 
n. All remaining unmarked numbers in the list are primes.
*/
// O(nlog log n)
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark all multiples of i as not prime
            }
        }
    }
    return isPrime;
}
