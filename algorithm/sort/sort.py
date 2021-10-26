# def quick_sort(array: list, lo: int = None, hi: int = None):
#     if lo is None:
#         lo = 0
#     if hi is None:
#         hi = len(array) - 1
#     if lo >= hi:
#         return
#     pivot = array[lo]
#     left, right = lo, hi
#     while left != right:
#         # there have two methods
#         while left != right and array[right] >= pivot:
#             right -= 1
#         array[left] = array[right]
#         while left != right and array[left] < pivot:
#             left += 1
#         array[right] = array[left]
#     mid = left
#     array[mid] = pivot
#     quick_sort(array, lo, mid - 1)
#     quick_sort(array, mid + 1, hi)
import random


def quick_sort(array: list):
    random.shuffle(array)
    print(array)
    if len(array) <= 1:
        return
    stack = [(0, len(array) - 1)]
    while len(stack) != 0:
        lo, hi = stack.pop()
        left, right = lo, hi
        if left >= right:
            continue
        pivot = array[left]
        while left != right:
            while left != right and array[right] >= pivot:
                right -= 1
            array[left] = array[right]
            while left != right and array[left] < pivot:
                left += 1
            array[right] = array[left]
        mid = left
        array[mid] = pivot
        stack.append((lo, mid - 1))
        stack.append((mid + 1, hi))


def selection_sort(array: list):
    size = len(array)
    for i in range(size):
        for j in range(i + 1, size):
            if array[i] > array[j]:
                array[i], array[j] = array[j], array[i]


if __name__ == '__main__':
    a = [i for i in range(1000000, 0, -1)]
    print(a)
    quick_sort(a)
    # selection_sort(a)
    print(a)
