# Heapify 
- 给定一个数组 让这个数组成一个堆的形状 这个过程叫做Heapify
# 用数组存储二叉堆
- 索引从下标0开始
    - parent(i) = (i-1)/2    父节点 (当前索引-1)/2
    - left child(i) = 2*i+1  左节点 2*当前索引 + 1
    - right child(i) = 2*i+2 右节点 2*当前索引 + 2
    - (count -1 ) /2  最后一个非叶子节点的索引 (总数-1)/2
- 索引下标从1开始
    - 左节点的序列号都是父节点的2倍 left child(i) = 2*i
    - 右节点的序列号都是父节点的2倍+1  right child(i) = 2*i+1
    - parent(i) = i / 2
    - left child(i) = 2*i 
    - right child(i) = 2*i+1