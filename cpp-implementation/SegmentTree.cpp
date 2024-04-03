#include <bits/stdc++.h>

class NumArray {
private:
    vector<int> nums;
    vector<int> segmentTree; // segment tree is a binary tree where each node contains the sum of the elements in the array represented by the leaf nodes of the node.
    int n;   // n is the number of elements in the array for which segment tree is built. 
    // node is the index of the current node in the segment tree. start and end are the starting and ending indices of the segment represented by the current node, which is used to update the segment tree.
    void buildSegmentTree(int node, int start, int end){
        if(start==end){
            segmentTree[node]=nums[start];
            return;
        }
        int mid=start+(end-start)/2; // mid is the middle index of the segment represented by the current node
        int leftChild=2*node + 1; // left child of the current node is at index 2*node + 1
        int rightChild=2*node + 2; // right child of the current node is at index 2*node + 2
        buildSegmentTree(leftChild, start, mid);
        buildSegmentTree(rightChild, mid+1,end);
        segmentTree[node]=segmentTree[leftChild]+segmentTree[rightChild];
    }

    // index is the index of the element to be updated in the array. val is the new value to be updated.
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

    // left and right are the range of the sum query. start and end are the starting and ending indices of the segment represented by the current node.
    int sumRangeSegmentTree(int node, int start, int end, int left, int right){
        if(right<start || end<left) return 0; // range (left, right) of sum query is out of range
        if(left<=start&&end<=right) return segmentTree[node]; // range (left, right) of sum query is completely inside the range represented by the current node
        // range (left, right) of sum query is partially inside and partially outside the range represented by the current node
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
        segmentTree.resize(n*4,0); // segment tree is a full binary tree with 2n-1 nodes. So, the size of the segment tree is 4*n. initialize all the nodes of the segment tree with 0.
        buildSegmentTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        if(index<0 || index>=n) return; // index is out of range
        updateSegmentTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        if(left<0 || right>=n || left > right) return 0; // left or right is out of range
        return sumRangeSegmentTree(0,0,n-1,left,right);
    }
};

/*
Segment Tree is a data structure that allows answering range queries over an array effectively, while still being flexible enough to allow modifying the array. This includes finding the
 sum of consecutive array elements a range query, and modifying the value of a specific element in the array.

Segment Tree is used in cases where there are multiple range queries on array and modifications of elements of the same array. For example, finding the sum of all the elements in an array from indices 
 to , or finding the minimum (famously known as Range Minumum Query problem) of all the elements in an array from indices  to . These problems can be easily solved with one of the most versatile data structures, Segment Tree.

Height of segment tree is  log(n) base 2 where n is the number of elements in the array. Since the segment tree is a full binary tree, the number of nodes at each level is double the number of nodes at the previous level. So,

In each step, the segment is divided into half and the two children represent those two halves. So the height of the segment tree will be log(n) base 2. There are n leaves in the segment tree, 
each representing an element of the array. The number of internal nodes is n-1. So, the total number of nodes are 2n-1.

*/

// Since Segment Tree is a binary tree. 2 * node will represent the left child and 2 * node + 1 will represent the right child. start and end represent the interval represented by the current node.
// Complexity of build is O(n).

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

// Complexity of update will be O(log n).
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
/*
To query on a given range, check 3 conditions.
1. Range represented by a node is completely inside the given range
2. Range represented by a node is completely outside the given range
3. Range represented by a node is partially inside and partially outside the given range
*/

// complexity of query will be O(log n).
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}


