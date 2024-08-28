from typing import Union, List, Deque
from collections import deque


class TreeNode:
    def __init__(self, val: int=0, left: Union['TreeNode', None]=None, right: Union['TreeNode', None]=None) -> None:
        self.val = val
        self.left = left
        self.right = right

    """ PROPERTIES """
    @property  # var = TreeNode.val
    def val(self) -> int:
        return self._val

    @val.setter  # TreeNode.val = new_val
    def val(self, new_val: int) -> None:
        if (new_val < -100) or (new_val > 100):
            raise ValueError("Constraints for 'value' violated")
        self._val = new_val

    @property  # var = TreeNode.left
    def left(self) -> Union['TreeNode', None]:
        return self._left

    @left.setter  # TreeNode.left = new_left
    def left(self, new_left: Union['TreeNode', None]) -> None:
        if isinstance(new_left, TreeNode) or new_left is None:
            self._left = new_left
        else:
            raise ValueError(f"Unsupported type {type(new_left)} for TreeNode.left")

    @property  # var = TreeNode.right
    def right(self) -> Union['TreeNode', None]:
        return self._right

    @right.setter  # TreeNode.right = new_right
    def right(self, new_right: Union['TreeNode', None]) -> None:
        if isinstance(new_right, TreeNode) or new_right is None:
            self._right = new_right
        else:
            raise ValueError(f"Unsupported type {type(new_right)} for TreeNode.right")


class Solution:
    def insertLevelOrder(self, arr: List[int]) -> Union[TreeNode, None]:
        if len(arr) == 0 or arr[0] is None: return None  # Handle empty or root = None case
        root = TreeNode(arr[0])
        q = deque([root])
        i = 1
        while q and i < len(arr):
            current = q.popleft()
            # Insert the left/right child if it is not None
            if i < len(arr) and arr[i] is not None:
                current.left = TreeNode(arr[i])
                q.append(current.left)
            i += 1  # Move to the next element in the array
            if i < len(arr) and arr[i] is not None:
                current.right = TreeNode(arr[i])
                q.append(current.right)
            i += 1  # Move to the next element in the array
        return root

    def preorderTraversal(self, root: Union[TreeNode, None]=None) -> List[int]:
        result = []
        self.recursion(root, result, "preorder")
        return result

    def inorderTraversal(self, root: Union[TreeNode, None]=None) -> List[int]:
        result = []
        self.recursion(root, result, "inorder")
        return result
    
    def postorderTraversal(self, root: Union[TreeNode, None]=None) -> List[int]:
        result = []
        self.recursion(root, result, "postorder")
        return result
    
    def levelorderTraversal(self, root: Union[TreeNode, None]=None) -> List[List[int]]:
        result = []
        if root is None: return result
        q = deque([root])
        while q:
            levelSize = len(q)
            currentLevel = []
            for i in range(levelSize):
                node = q.popleft()
                currentLevel.append(node.val)
                if node.left is not None: q.append(node.left)
                if node.right is not None: q.append(node.right)
            result.append(currentLevel)
        return result
    
    def recursion(self, node: Union[TreeNode, None], result: List[int], type: str) -> None:
        if not node: return
        if type == "preorder":
            result.append(node.val)
            self.recursion(node.left, result, "preorder")
            self.recursion(node.right, result, "preorder")
        elif type == "inorder":
            self.recursion(node.left, result, "inorder")
            result.append(node.val)
            self.recursion(node.right, result, "inorder")
        elif type == "postorder":
            self.recursion(node.left, result, "postorder")
            self.recursion(node.right, result, "postorder")
            result.append(node.val)