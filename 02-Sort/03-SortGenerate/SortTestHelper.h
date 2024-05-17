#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper
{
    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    /**
     * @brief 生成随机数组
     *
     * 在指定范围内生成一个长度为n的随机整数数组，并返回该数组的指针。
     *
     * @param n 数组长度
     * @param rangeL 范围下限（包含）
     * @param rangeR 范围上限（包含）
     *
     * @return 随机数组指针
     */
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        // 断言范围左边界小于等于右边界
        assert(rangeL <= rangeR);

        // 动态分配整型数组
        int *arr = new int[n];

        // 初始化随机数种子
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            // 生成范围在[rangeL, rangeR]内的随机整数
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    // 打印arr数组的所有内容
    template<typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }
    
} // namespace SortTestHelper
