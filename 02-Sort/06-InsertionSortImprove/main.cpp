// 插入排序犹如打扑克牌时的排序
#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {

        // 寻找元素arr[i]合适的插入位置
        // 写法1
    //    for( int j = i ; j > 0 ; j-- )
    //        if( arr[j] < arr[j-1] )
    //            swap( arr[j] , arr[j-1] );
    //        else
    //            break;

        // 写法2
        T e = arr[i];
        int j;
        for(j = i ; j > 0 && arr[j-1] > e ; j -- )
        {
            arr[j] = arr[j-1];
        }
        arr[j] = e;

    }

    return;
}

/**
 * @netstan 选择排序算法
 *
 * 使用选择排序算法对给定的整数数组进行排序。
 *
 * @param arr 整数数组
 * @param n 数组的长度
 */template <typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {

        //寻找[i, n]区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 比较SelectionSort和InsertionSort两种排序算法的性能效率
// 此时， 插入排序比选择排序性能略低
int main() {

    int n = 100000;

    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectSort,arr2,n);

    // Test for random array, size = 100000, random range [0, 100000]
    // Insertion Sort : 1.32932 s
    // Selection Sort : 9.9533 s

    delete[] arr1;
    delete[] arr2;

    cout<<endl;

    return 0;
}