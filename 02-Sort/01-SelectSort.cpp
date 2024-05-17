#include <iostream>

using namespace std;

/**
 * @netstan 选择排序算法
 *
 * 使用选择排序算法对给定的整数数组进行排序。
 *
 * @param arr 整数数组
 * @param n 数组的长度
 */
void selectcSort(int arr[], int n) {
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

/**
 * @brief 主函数
 *
 * 该函数是程序的入口点，用于执行排序并输出排序后的结果。
 */
int main() {
    // 定义一个整数数组arr并初始化
    int arr[] = {1, 4, 2, 5, 3, 6, 8, 7};
    // 调用selectcSort函数对数组进行排序，传入数组和数组长度作为参数
    selectcSort(arr, sizeof(arr) / sizeof(arr[0]));
    // 遍历数组并输出每个元素，元素之间用空格隔开
    for (auto i : arr) {
        cout << i << " ";
    }
}