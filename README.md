# Common-Algorithm
常用算法C++实现

## 排序算法时间复杂度

- 插入排序 O(n^2)   原地    空间 O(1)    稳定   (相等元素相对位置没有发生改变)
- 归并排序 O(nlogn) 非原地  空间 O(n)    稳定           -
- 快速排序 O(nlogn) 原地    空间 O(logn) 不稳定         -
- 堆排序   O(nlogn) 原地    空间 O(1)    不稳定         -

## 归并排序 双路快排 三路快排对比 1000万测试 
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

## 归并 普通快排 双路快排 三路快排 最大堆-O(nlogn) 最大堆Heapify-O(n) 1000万对比
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

## 归并 普通快排 双路快排 三路快排 最大堆-O(nlogn) 最大堆Heapify-O(n) 最大堆优化 1000万对比
- 第一次直接 最大堆优化原始的shiftDown std::swap
    ```
    Test for random array, size = 10000000, random range [0, 10000000]
    Merge Sort : 1.24907 s
    Quick Sort : 0.659602 s
    Quick Sort 2 Ways : 0.672222 s
    Quick Sort 3 Ways : 0.698285 s
    Heap Sort 1 : 3.02872 s
    Heap Sort 2 Heapify : 3.22713 s
    Heap Sort 3 Optimize : 2.71861 s

    Test for nearly ordered array, size = 10000000, swap time = 100
    Merge Sort : 0.200171 s
    Quick Sort : 0.183591 s
    Quick Sort 2 Ways : 0.182653 s
    Quick Sort 3 Ways : 0.274377 s
    Heap Sort 1  : 0.714994 s
    Heap Sort 2 Heapify : 0.628182 s
    Heap Sort 3 Optimize : 0.577857 s

    Test for random array, size = 10000000, random range [0,10]
    Merge Sort : 0.69072 s
    Quick Sort 2 Ways : 0.256066 s
    Quick Sort 3 Ways : 0.111478 s
    Heap Sort 1 : 0.634931 s
    Heap Sort 2 Heapify : 0.601321 s
    Heap Sort 3 Optimize : 0.553766 s
    ```
- 第二次 最大堆优化使用赋值的方式取代不断的std::swap
    ```
    Test for random array, size = 10000000, random range [0, 10000000]
    Merge Sort : 1.17105 s
    Quick Sort : 0.65378 s
    Quick Sort 2 Ways : 0.673984 s
    Quick Sort 3 Ways : 0.691761 s
    Heap Sort 1 : 3.07411 s
    Heap Sort 2 Heapify : 2.8649 s
    Heap Sort 3 Optimize : 2.80469 s

    Test for nearly ordered array, size = 10000000, swap time = 100
    Merge Sort : 0.195288 s
    Quick Sort : 0.181181 s
    Quick Sort 2 Ways : 0.195207 s
    Quick Sort 3 Ways : 0.268691 s
    Heap Sort 1  : 0.695593 s
    Heap Sort 2 Heapify : 0.615506 s
    Heap Sort 3 Optimize : 0.549197 s

    Test for random array, size = 10000000, random range [0,10]
    Merge Sort : 0.705984 s
    Quick Sort 2 Ways : 0.278444 s
    Quick Sort 3 Ways : 0.111828 s
    Heap Sort 1 : 0.678285 s
    Heap Sort 2 Heapify : 0.593424 s
    Heap Sort 3 Optimize : 0.538811 s
    ```


# 二分搜索树 对圣经 god 词频统计
    ```
    There are totally 431180 words in bible.txt

    'god' : 2301
    二分搜索树 BST , time: 0.057559 s.

    'god' : 2301
    第三方库 SequenceST SST , time: 3.15761 s.
    ```
