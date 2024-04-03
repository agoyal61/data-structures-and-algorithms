#include <iostream>
#include <string>
using namespace std;

/*
    Rabin Karp Algorithm for Pattern Searching. Used to find the multiple pattern in the given text in a linerar time and a moderate space suitable for large strings.
    Time Complexity: O(n + m)
    Space Complexity: O(1)

    The algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match, then it starts matching individual characters.

    The hash value of the pattern is calculated using the formula:  hash = (hash * d + pattern[i]) % q , d = 256, q = 101 (prime number)

*/

// p = 5381 , larger prime number means lower collission (beeter to take large prime number) long long int p = 1000000007;
// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
   txt -> text
   q -> A prime number
*/
void search(char pat[], char txt[], int q) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern
        // If the hash values match then only check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if (i < N - M) {
            t = (d*(t - txt[i]*h) + txt[i+M]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
              t = (t + q);
        }
    }
}

int main() {
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}


/* basic overview of how the Rabin-Karp Algorithm works:
1. Preprocessing Phase: Calculate the hash value of the pattern, P, and the hash value of the first substring of text, 
   T, of length equal to the pattern length. Typically, a rolling hash function is used that allows for constant-time update from one substring to the next.

2. Matching Phase: Compare the hash value of the pattern, P, with the hash value of the current substring of text, T. If the hash values match, compare each character sequentially to verify an actual match since different strings can have the same hash value (a collision).
If the pattern is not found, slide the window one character to the right, update the hash value of the substring in constant time, and repeat the comparison until the end of the text is reached or the pattern is found.

Rolling Hash Function: A common choice is a polynomial rolling hash function. For a string of characters (each character converted to an integer), the hash is computed as:
     m−1      m−i−1
hash=∑  s[i]⋅a       mod q
    i=0
where: s[i] is the integer value of the i-th character in the string, m is the length of the pattern, a is a constant (often a prime number), and
q is a large prime number to avoid overflow and reduce the chance of collisions.

*/