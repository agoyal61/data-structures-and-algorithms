#include <bits/stdc++.h>

using namespace std;

vector<int> nextSmaller(vector<int>& nums, int n) {
    vector<int> ns;
    stack<int> s;
    for(int i=n-1;i>=0;i-=1) {
        while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        if (s.empty()) ns.push_back(n);
        else ns.push_back(s.top());
        s.push(i);
    }
    reverse(ns.begin(), ns.end());
    return ns;
}