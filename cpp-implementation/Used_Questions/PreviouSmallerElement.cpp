vector<int> previousSmaller(vector<int>& nums, int n) {
    vector<int> ps;
    stack<int> s;
    for(int i=0;i<n;i++) {
        while (!s.empty() && nums[s.top()]>=nums[i]) s.pop();
        if (s.empty()) ps.push_back(-1);
        else ps.push_back(s.top());
        s.push(i);
    }
    return ps;
}