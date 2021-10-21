"""
��дһ����������֪һ�ö�������ǰ�������������������������ԭ�ö�������
"""
import random


class Node:
    def __init__(self, value=None, leftChild=None, rightChild=None):
        self.value = value
        self.leftChild = leftChild
        self.rightChild = rightChild

    def preorder(self):
        preList = []

        def __preorder(node: Node):
            if node is None:
                return
            preList.append(node.value)
            __preorder(node.leftChild)
            __preorder(node.rightChild)

        __preorder(self)
        return preList

    def inorder(self):
        inList = []

        def __inorder(node: Node):
            if node is None:
                return
            __inorder(node.leftChild)
            inList.append(node.value)
            __inorder(node.rightChild)

        __inorder(self)
        return inList


def rebuild(preorder: list, inorder: list):
    if len(preorder) <= 0:
        return None
    root_value = preorder[0]
    root = Node(root_value)
    index = 0
    for i in range(len(inorder)):
        if root_value == inorder[i]:
            index = i
            break
    # left
    root.leftChild = rebuild(preorder[1:index + 1], inorder[:index])
    # right
    if index + 1 < len(preorder):
        root.rightChild = rebuild(preorder[index + 1:], inorder[index + 1:])

    return root


def random_build_tree(root: Node = None):
    if root is None:
        root = Node(random.randint(0, 100))
    if random.random() < 0.5:
        root.leftChild = Node(random.randint(0, 100))
        random_build_tree(root.leftChild)
    if random.random() < 0.5:
        root.rightChild = Node(random.randint(0, 100))
        random_build_tree(root.rightChild)
    return root


if __name__ == '__main__':
    # �������һ�ö�����
    x = random_build_tree()
    # ��ʾ�ö�������ǰ��������������
    pre_list = x.preorder()
    in_list = x.inorder()
    print(pre_list)
    print(in_list)
    # ����ǰ���������������ؽ�������
    root = rebuild(pre_list, in_list)
    a = root.preorder()
    b = root.inorder()
    print(a)
    print(b)
    # check, У�����Ƿ���ȷ
    flag = True
    for i in range(len(a)):
        if a[i] != pre_list[i]:
            flag = False
            break
    print(flag)
