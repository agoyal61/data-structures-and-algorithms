def printSubsets(arr):
    n = len(arr)
    # There are 2^n subsets
    for i in range(1 << n):  # Loop through from 0 to 2^n - 1
        subset = []
        for j in range(n):  # Check every bit of i
            if i & (1 << j):  # If the j-th bit of i is set, include arr[j] in the current subset
                subset.append(arr[j])
        print(subset)

# Example usage
arr = [1, 2, 3]
printSubsets(arr)
