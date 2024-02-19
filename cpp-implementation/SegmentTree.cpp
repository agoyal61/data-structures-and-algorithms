#include <bits/stdc++.h>

class NumArray {
private:
    vector<int> nums;
    vector<int> segmentTree;
    int n;    
    void buildSegmentTree(int node, int start, int end){
        if(start==end){
            segmentTree[node]=nums[start];
            return;
        }
        int mid=start+(end-start)/2;
        int leftChild=2*node + 1;
        int rightChild=2*node + 2;
        buildSegmentTree(leftChild, start, mid);
        buildSegmentTree(rightChild, mid+1,end);
        segmentTree[node]=segmentTree[leftChild]+segmentTree[rightChild];
    }

    void updateSegmentTree(int node, int start, int end, int index, int val){
        if(start==end){
            nums[index]=val;
            segmentTree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        int leftChild=2*node + 1;
        int rightChild=2*node + 2;
        if(index<=mid){
            updateSegmentTree(leftChild,start,mid,index,val);
        }else{
             updateSegmentTree(rightChild,mid+1,end,index,val);
        }
        segmentTree[node]=segmentTree[leftChild]+segmentTree[rightChild];
    }

    int sumRangeSegmentTree(int node, int start, int end, int left, int right){
        if(right<start || end<left) return 0;
        if(left<=start&&end<=right) return segmentTree[node];
        int mid=start+(end-start)/2;
        int leftChild=2*node + 1;
        int rightChild=2*node + 2;
        int leftSum=sumRangeSegmentTree(leftChild,start,mid,left,right);
        int rightSum=sumRangeSegmentTree(rightChild,mid+1,end,left,right);
        return leftSum + rightSum;
    }
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        segmentTree.resize(n*4,0);
        buildSegmentTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        if(index<0 || index>=n) return;
        updateSegmentTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        if(left<0 || right>=n || left > right) return 0;
        return sumRangeSegmentTree(0,0,n-1,left,right);
    }
};
