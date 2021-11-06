def merge_sort(array: list, lo: int = None, hi: int = None, target = None):
    if lo is None:
        lo = 0
    if hi is None:
        hi = len(array) - 1
    if target is None:
        target = [0 for _ in range(len(array))]
    if lo >= hi:
        return
    mid = lo + (hi - lo) // 2
    merge_sort(array, lo, mid, target)
    merge_sort(array, mid + 1, hi, target)
    left = lo
    right = mid + 1
    for i in range(lo, hi + 1):
        if right > hi or array[left] < array[right]:
            target[i] = array[left]
            left += 1
        elif left > mid or array[right] < array[left]:
            target[i] = array[right]
            right += 1
    for i in range(lo, hi+1):
        array[i] = target[i]


if __name__ == '__main__':
    a = [10-i for i in range(10)]
    print(a)
    merge_sort(a)
    print(a)
