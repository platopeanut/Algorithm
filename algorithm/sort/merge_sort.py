import random


class Node:
    def __init__(self, value=None, _next=None):
        self.value = value
        self.next = _next


def node_show(node: Node):
    curr = node
    print('[[', end='')
    while curr is not None:
        print(curr.value, end=' ')
        curr = curr.next
    print(']]')


def load_node(array: list):
    curr = head = Node(array[0])
    for i in array[1:]:
        curr.next = Node(i)
        curr = curr.next
    return head


def merge_sort(head: Node):
    if head is None or head.next is None:
        return
    left, right = head, head.next
    ll, rr = left, right
    flag = True
    while head is not None:
        if flag:
            ll.next = head
            ll = ll.next
            flag = not flag
        else:
            rr.next = head
            rr = rr.next
            flag = not flag
        head = head.next
        node_show(head)
    # node_show(head)
    # node_show(left)
    # node_show(right)


if __name__ == '__main__':
    a = [i*3 for i in range(10)]
    b = load_node(a)
    merge_sort(b)
    # node_show(b)
    # node_show(b)
