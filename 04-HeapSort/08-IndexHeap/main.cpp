#include "Heap.h"
#include "SortTestHelper.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"
#include "MergeSort.h"

using namespace std;

template <typename T>
void HeapSort1(T arr[], int n)
{
    MaxHeap<T> max_heap(n);
    for (int i = 0; i < n; ++i)
    {
        max_heap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        arr[i] = max_heap.extractMax();
    }
}

// heapSort2, 借助我们的heapify过程创建堆
// 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
template<typename T>
void heapSort2(T arr[], int n){

    MaxHeap<T> max_heap(arr, n);
    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = max_heap.extractMax();

}

// 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
// 该优化思想和我们之前对插入排序进行优化的思路是一致的
template<typename T>
void __shiftDown2(T arr[], int n, int k){
    // 将元素arr[k]保存到变量e中
    T e = arr[k];
    // 当k节点的下标小于n时，执行循环
    while( 2*k+1 < n ){
        // 左子节点下标
        int j = 2*k+1;
        // 如果右子节点存在且大于左子节点
        if( j+1 < n && arr[j+1] > arr[j] )
            // 更新j为右子节点下标
            j += 1;

        // 如果元素e大于等于j节点对应的元素
        if( e >= arr[j] ) break;

        // 将j节点对应的元素保存到k节点
        arr[k] = arr[j];
        // 更新k为j节点下标
        k = j;
    }

    // 将元素e保存到k节点
    arr[k] = e;
}

/**
 * @brief 向下调整堆
 *
 * 在堆中，从给定的索引 i 开始，通过比较节点与其子节点的值，并进行交换，将堆调整为满足堆性质的状态。
 *
 * @param arr 整数数组
 * @param n 数组的长度
 * @param i 当前节点的索引
 */
void __shiftDown(int arr[], int n, int i){
    // 计算左子节点的索引
    int left_child = 2*i+1;

    // 当左子节点索引小于数组长度时循环
    while(left_child < n){

        // 如果右子节点存在且大于左子节点
        if(left_child + 1 < n && arr[left_child] < arr[left_child+1])
        {
            // 更新左子节点索引为右子节点索引
            ++left_child;
        }

        // 如果父节点大于左子节点
        if(arr[i] >= arr[left_child])
        {
            break;
            
        }
        else
        {
            // 交换父节点和左子节点的值
            swap(arr[i], arr[left_child]);
            // 更新父节点索引为左子节点索引
            i = left_child;
            // 重新计算左子节点的索引
            left_child = 2*i+1;
        }
    }
}

template<typename T>
void heapSort(T arr[], int n){

    for(int i = (n-1-1)/2; i >= 0 ; --i)
    {
        __shiftDown2(arr, n, i);
    }
    
    for(int j = n-1; j > 0 ; --j)
    {
        swap(arr[0], arr[j]);
        __shiftDown2(arr, j, 0);
    }

}


int main()
{
    int n = 10000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    int* arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2 Heapify", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3 Optimize", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1 ", HeapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2 Heapify", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3 Optimize", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    // 这种情况下, 普通的QuickSort退化为O(n^2)的算法, 不做测试
    // SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2 Heapify", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3 Optimize", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    return 0;
}