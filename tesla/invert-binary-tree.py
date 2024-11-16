def invertTree(self, root):
    if root:
        root.left = self.invertTree(root.left)
        root.right = self.invertTree(root.right)
        temp = root.right
        root.right = root.left
        root.left = temp
        return root