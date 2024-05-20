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

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2 Heapify", heapSort2, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

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

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1 ", HeapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2 Heapify", heapSort2, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    // 这种情况下, 普通的QuickSort退化为O(n^2)的算法, 不做测试
    // SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2 Heapify", heapSort2, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    return 0;
}