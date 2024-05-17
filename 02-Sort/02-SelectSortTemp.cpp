#include <iostream>
#include "Student.h"

using namespace std;

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

/**
 * @brief 主函数
 *
 * 该函数是程序的入口点，用于执行排序并输出排序后的结果。
 */
int main() {
    // 定义一个整数数组arr并初始化
    int arr[] = {1, 4, 2, 5, 3, 6, 8, 7};
    // 调用selectcSort函数对数组进行排序，传入数组和数组长度作为参数
    selectSort(arr, sizeof(arr) / sizeof(arr[0]));
    // 遍历数组并输出每个元素，元素之间用空格隔开
    for (auto i : arr) {
        cout << i << " ";
    }

    // 测试模板函数，传入浮点数数组
    float b[4] = {4.4,3.3,2.2,1.1};
    selectSort(b,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;

    // 测试模板函数，传入字符串数组
    string c[4] = {"D","C","B","A"};
    selectSort(c,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<c[i]<<" ";
    cout<<endl;

    Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectSort(d,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<d[i];
    cout<<endl;



    return 0;
}