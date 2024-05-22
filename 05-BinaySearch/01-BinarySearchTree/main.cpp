#include <iostream>
#include <cassert>
#include <ctime>


using namespace std;

//二分查找法
template<typename T>
int binarySearch(const T arr[], int n, T target)
{
    if (n <= 0) return -1; // 如果数组为空或长度为0，返回-1表示未找到
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // 找到目标值，返回其索引
        }

        // 目标值与中间值的比较
        if (target < arr[mid]) {
            // 如果目标值小于中间值，说明目标值在左半部分
            right = mid - 1; // 目标值在左半部分
        } else {
            // 如果目标值大于中间值，说明目标值在右半部分
            left = mid + 1; // 目标值在右半部分
        }
    }
    return -1; // 循环结束仍未找到目标值，返回-1
}


// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){

    if( l > r )
        return -1;

    // 计算中间位置，防止整形溢出
    // 使用(r-l)/2而不是(l+r)/2，以避免在l和r都很大时相加导致溢出
    int mid = l + (r-l)/2;

    // 如果中间位置的元素等于目标值，则返回中间位置
    if( arr[mid] == target )
        return mid;
    // 如果中间位置的元素大于目标值，则在左半部分继续搜索
    else if( arr[mid] > target )
        return __binarySearch2(arr, l, mid-1, target);
    // 如果中间位置的元素小于目标值，则在右半部分继续搜索
    else
        return __binarySearch2(arr, mid+1, r, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target){

    return __binarySearch2( arr , 0 , n-1, target);
}

int main() {
    int n = 1000000;
    int* a = new int[n];
    for( int i = 0 ; i < n ; i ++ )
        a[i] = i;

    // 测试非递归二分查找法
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;


    // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch2(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

    delete[] a;

    return 0;
}