# Hubbard Deletion 删除法 O(logn)
- 删除节点 d 左右都有孩子
- s = min(d->right)
- s->right = delMin(d->right)
- s->left = d->left
