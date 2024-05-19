
#include "SortTestHelper.h"
#include <vector>
#include <functional>

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

int main() {
	int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    selectSort (arr, n);

    // SortTestHelper::printArray(arr,n);

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << arr[i] <<"";
    //     cout << endl;
    //     /* code */
    // }
    SortTestHelper::testSort("select sort", selectSort, arr, n);

    delete[] arr;
    return 0;
}