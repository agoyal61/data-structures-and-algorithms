# time complexity: O(logn) where n is the number of elements in the array
def bs(arr, l, r, x):
    while l <= r:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1


def bs_recursive(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return bs_recursive(arr, l, mid - 1, x)
        else:
            return bs_recursive(arr, mid + 1, r, x)
    else:
        return -1
    
arr = [2, 3, 4, 10, 40]
print(bs(arr, 0, len(arr) - 1, 10))
print(bs_recursive(arr, 0, len(arr) - 1, 10))

