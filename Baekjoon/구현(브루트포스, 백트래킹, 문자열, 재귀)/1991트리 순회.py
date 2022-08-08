import sys

class Node:
    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right

def preorder(node):
    print(node.data, end='')
    if not node.left == '.':
        preorder(tree[node.left])
    if not node.right == '.':
        preorder(tree[node.right])

def inorder(node):
    if not node.left == '.':
        inorder(tree[node.left])
    print(node.data, end='')
    if not node.right == '.':
        inorder(tree[node.right])

def postorder(node):
    if not node.left == '.':
        postorder(tree[node.left])
    if not node.right == '.':
        postorder(tree[node.right])
    print(node.data, end='')

if __name__=="__main__":
    n = int(sys.stdin.readline())
    tree=dict()
    for i in range(n):
        test = sys.stdin.readline().split()
        tree[test[0]] = Node(test[0], test[1], test[2])

    preorder(tree['A'])
    print()
    inorder(tree['A'])
    print()
    postorder(tree['A'])

