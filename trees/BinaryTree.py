class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
class BinaryTree:
    def __init__(self):
        self.idx=-1
    def build_tree_preorder(self,arr):
        self.idx+=1
        if self.idx >= len(arr) or arr[self.idx]==-1:
            return None
        
        newNode = Node(arr[self.idx])
        newNode.left=self.build_tree_preorder(arr)
        newNode.right=self.build_tree_preorder(arr)

        return newNode
    
    def preorder_traversal(self, node):
        if node==None:
            return
        print(node.data)
        self.preorder_traversal(node.left)
        self.preorder_traversal(node.right)
        

if __name__=="__main__":
    arr=[1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1]
    bTree=BinaryTree()
    root = bTree.build_tree_preorder(arr)
    bTree.preorder_traversal(root)


'''class Node:
    def __init__(self, data):  # Corrected __init__
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):  # Corrected __init__
        self.idx = -1

    def build_tree_preorder(self, arr):
        self.idx += 1
        if self.idx >= len(arr) or arr[self.idx] == -1:
            return None
        
        newNode = Node(arr[self.idx])
        newNode.left = self.build_tree_preorder(arr)  # Call using self
        newNode.right = self.build_tree_preorder(arr)

        return newNode

# Main execution
if __name__ == "__main__":
    arr = [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]
    bTree = BinaryTree()
    root = bTree.build_tree_preorder(arr)
    print(root.data)  # Print root's data to verify'''
 