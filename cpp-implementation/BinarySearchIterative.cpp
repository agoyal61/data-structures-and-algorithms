#include <bits/stdc++.h>

using namespace std;
int bs(const vector<int> &arr, int k) {
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k) return mid;
        if (arr[mid] < k) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}


