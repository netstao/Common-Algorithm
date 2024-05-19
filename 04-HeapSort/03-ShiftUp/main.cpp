#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;


template <typename Item>
class MaxHeap{
    
private:
    Item* data;
    int count;

public:
    /**
     * @brief 构造函数，初始化最大堆
     *
     * 根据给定的容量初始化最大堆。
     *
     * @param capacity 最大堆的容量
     */
    MaxHeap(int capacity): count(0){
        data = new Item[capacity + 1];  // 索引从1开始
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size() 
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }
};



int main()
{
    MaxHeap<int> max_heap(100);

    cout << max_heap.size() << endl;
    return 0;
}