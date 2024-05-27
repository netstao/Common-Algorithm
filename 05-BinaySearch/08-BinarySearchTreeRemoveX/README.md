# Hibbard Deletion 删除法 O(logn) 
- 删除节点 d 左右都有孩子 又有左孩子又有右孩子
- s = min(d->right) 右子树中的最小值  如果是左边则寻找左边最大值 s=max(d->left)
- s->right = delMin(d->right)
- s->left = d->left
