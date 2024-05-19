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

    
    // 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
    int *copyIntArray(int a[], int n){

        int *arr = new int[n];
        //* 在VS中, copy函数被认为是不安全的, 请大家手动写一遍for循环:)
        copy(a, a+n, arr);
        return arr;
    }

    // 生成一个近乎有序的数组
    // 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
    // swapTimes定义了数组的无序程度:
    // swapTimes == 0 时, 数组完全有序
    // swapTimes 越大, 数组越趋向于无序
    int *generateNearlyOrderedArray(int n, int swapTimes){

        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;

        srand(time(NULL));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx] , arr[posy] );
        }

        return arr;
    }
    // 生成一个近乎有序的数组

    template<typename T>
    bool isSorted(T arr[], int n) {
        // 这里应该是排序检查的逻辑
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true; // 示例返回，实际应替换为正确的检查逻辑
    }

    // 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
    // * 使用VS编码的同学, 对于函数指针的写法和调用方法可能和课程中介绍的有所不同;
    // * 并且不同版本的VS, 其具体语法可能也有差异, 这是因为VS的编译器不完全是按照C++的标准实现的;
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
        // 记录排序开始时间
        clock_t startTime = clock();

        // 调用传入的排序函数进行排序
        sort(arr, n);

        // 记录排序结束时间
        clock_t endTime = clock();

        // 断言排序结果是否正确
        assert(isSorted(arr, n));

        // 输出排序函数名称和排序所花费的时间
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }

    
} // namespace SortTestHelper
