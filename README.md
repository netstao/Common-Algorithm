# Common-Algorithm
常用算法C++实现

# 归并排序 双路快排 三路快排对比 1000万测试 
1. 随机 
2. 接近有序 
3. 大量重复
    ```
    Test for random array, size = 10000000, random range [0, 10000000]
    Merge Sort : 1.2529 s
    Quick Sort : 0.667784 s
    Quick Sort 3 Ways : 0.713644 s

    Test for nearly ordered array, size = 10000000, swap time = 100
    Merge Sort : 0.202518 s
    Quick Sort : 0.164294 s
    Quick Sort 3 Ways : 0.276062 s

    Test for random array, size = 10000000, random range [0,10]
    Merge Sort : 0.735248 s
    Quick Sort : 0.248669 s
    Quick Sort 3 Ways : 0.107921 s
    ```

# 归并 普通快排 双路快排 三路快排 最大堆-O(nlogn) 最大堆Heapify-O(n) 1000万对比
    ```
    Test for random array, size = 10000000, random range [0, 10000000]
    Merge Sort : 1.33142 s
    Quick Sort : 0.652934 s
    Quick Sort 2 Ways : 0.658687 s
    Quick Sort 3 Ways : 0.691776 s
    Heap Sort 1 : 3.0032 s
    Heap Sort 2 Heapify : 2.95728 s

    Test for nearly ordered array, size = 10000000, swap time = 100
    Merge Sort : 0.238704 s
    Quick Sort : 0.187564 s
    Quick Sort 2 Ways : 0.166202 s
    Quick Sort 3 Ways : 0.272905 s
    Heap Sort 1  : 0.771505 s
    Heap Sort 2 Heapify : 0.637277 s

    Test for random array, size = 10000000, random range [0,10]
    Merge Sort : 0.810555 s
    Quick Sort 2 Ways : 0.234536 s
    Quick Sort 3 Ways : 0.103528 s
    Heap Sort 1 : 0.61475 s
    Heap Sort 2 Heapify : 0.600641 s
```
