#include <bits/stdc++.h>
using namespace std;

// l=0, r = arr.size() - 1
int bs(const vector<int> &arr, int l, int r, int k) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k) return mid;
        if (arr[mid] > k) return bs(arr, l, mid - 1, k);
        return bs(arr, mid + 1, r, k);
    }
    return -1;
}
