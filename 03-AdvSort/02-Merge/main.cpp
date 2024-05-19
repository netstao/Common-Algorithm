#include <iostream>
#include "SortTestHelper.h"

using namespace std;


template<typename T>
/**
 * @brief 插入排序算法
 *
 * 使用插入排序算法对给定数组进行排序。
 *
 * @param arr 数组指针
 * @param n 数组长度
 */
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

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r){

    for( int i = l+1 ; i <= r ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
/**
 * @brief 合并两个已排序的子数组
 *
 * 将两个已排序的子数组合并为一个完整的已排序数组。该函数采用归并排序算法中的合并操作。
 *
 * @param arr 目标数组
 * @param l 左半部分子数组的起始索引
 * @param mid 左半部分子数组的结束索引，右半部分子数组的起始索引减一
 * @param r 右半部分子数组的结束索引
 *
 * @note
 * - Visual Studio 不支持动态长度数组，因此不能使用 `T aux[r-l+1]` 的方式申请辅助数组的空间。
 * - 使用 Visual Studio 的用户，请使用 `new` 的方式申请辅助数组空间。
 * - 使用 `new` 申请空间后，不要忘记在函数最后使用 `delete[]` 释放申请的空间。
 *
 * @tparam T 数组元素的类型
 */
void __merge(T arr[], int l, int mid, int r){
    // VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
    // 使用VS的同学, 请使用new的方式申请aux空间
    // 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
    //* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
    //* 使用VS的同学, 请使用new的方式申请aux空间
    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
    // T aux[r-l+1];   //当数据过大时  1000万事 会段错误，栈空间不够
    T *aux = new T[r-l+1];   //堆空间分配内存 1000万顺利排序 1亿也可以顺利排序

    // 将arr[l]到arr[r]的元素复制到aux数组中
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        // 如果左半部分元素已经全部处理完毕
        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            // 将右半部分剩余的元素依次拷贝回arr数组
            arr[k] = aux[j-l]; j ++;
        }
        // 如果右半部分元素已经全部处理完毕
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            // 将左半部分剩余的元素依次拷贝回arr数组
            arr[k] = aux[i-l]; i ++;
        }
        // 左半部分所指元素 < 右半部分所指元素
        else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
            // 将左半部分当前最小元素拷贝回arr数组，并将i指针右移
            arr[k] = aux[i-l]; i ++;
        }
        // 左半部分所指元素 >= 右半部分所指元素
        else{  // 左半部分所指元素 >= 右半部分所指元素
            // 将右半部分当前最小元素拷贝回arr数组，并将j指针右移
            arr[k] = aux[j-l]; j ++;
        }
    }

    // 在函数最后，释放通过new申请的aux数组空间
    delete[] aux;
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
/**
 * @brief 归并排序函数
 *
 * 使用归并排序算法对指定范围的数组进行排序。
 *
 * @param arr 数组指针
 * @param l 排序范围的左边界
 * @param r 排序范围的右边界
 */
void __mergeSort(T arr[], int l, int r){

    // 如果左边界大于等于右边界，说明当前区间无需排序，直接返回
    // 优化2: 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    // 计算中间位置
    int mid = (l+r)/2;

    // 递归对左半部分进行归并排序
    __mergeSort(arr, l, mid);

    // 递归对右半部分进行归并排序
    __mergeSort(arr, mid+1, r);

    // 优化1: 对于arr[mid] <= arr[mid+1]的情况,不进行merge
    // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
    if( arr[mid] > arr[mid+1] )
        __merge(arr, l, mid, r);

}

template<typename T>
/**
 * @brief 归并排序
 *
 * 使用归并排序算法对给定的数组进行排序。
 *
 * @param arr 待排序数组
 * @param n 数组元素个数
 */
void mergeSort(T arr[], int n){

    __mergeSort( arr , 0 , n-1 );
}

int main() {

    // Merge Sort是我们学习的第一个O(nlogn)复杂度的算法
    // 可以在1秒之内轻松处理100万数量级的数据
    // 注意：不要轻易尝试使用SelectionSort, InsertionSort或者BubbleSort处理100万级的数据
    // 否则，你就见识了O(n^2)的算法和O(nlogn)算法的本质差异：）
    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    

    // SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    // 测试2 测试近乎有序的数组
    int swapTimes = 10;
    assert( swapTimes >= 0 );

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    // arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);
    // SortTestHelper::testSort("Merge Sort 2",   mergeSort2,    arr3, n);

    delete[] arr1;
    delete[] arr2;
    // delete[] arr3;


    cout<<endl;
    return 0;
}