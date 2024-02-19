
# Used to find all prime numbers up to a specified integer.
# It works by iteratively marking the multiples of each prime number starting from 2. 
# The numbers that remain unmarked at the end of the algorithm are the primes.

def sieve_of_eratosthenes(limit):
    primes = []
    prime_flags = [True] * (limit + 1)
    prime_flags[0] = prime_flags[1] = False  # 0 and 1 are not prime

    for p in range(2, int(limit**0.5) + 1):
        if prime_flags[p]:
            # Mark multiples of p as non-prime
            for i in range(p * p, limit + 1, p):
                prime_flags[i] = False

    for p in range(2, limit + 1):
        if prime_flags[p]:
            primes.append(p)

    return primes


def sieve(n):
    prime = [True for _ in range(n+1)]
    prime[0]=prime[1]=False
    p = 2
    while p*p <= n:
        if prime[p]:
            for i in range(p*p, n+1, p):
                prime[i] = False
        p += 1
    return [p for p in range(2, n) if prime[p]]
