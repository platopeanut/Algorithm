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


class Node:
    def __init__(self, value=None, _next=None):
        self.value = value
        self.next = _next

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        if self.value is not None:
            info = f"Node({self.value})"
            if self.next is not None:
                info += self.next.__str__()
            return info
        else:
            return f"Node()"


def radix_sort(array: list, w=0):
    # put in
    bucket = [Node() for i in range(10)]
    for i in array:
        slot = bucket[(i // 10**w) % 10]
        while slot.next is not None:
            slot = slot.next
        slot.value = i
        slot.next = Node()
    print(bucket)
    # pick up
    index = 0
    for i in bucket:
        while i.next is not None:
            array[index] = i.value
            i = i.next
            index += 1
    if bucket[1].value is None:
        return
    radix_sort(array, w+1)


if __name__ == '__main__':
    a = [i for i in range(100, 0, -1)]
    # for i in range(10):
    #     a.append(random.randint(0, 100))
    print(a)
    radix_sort(a)
    print(a)
