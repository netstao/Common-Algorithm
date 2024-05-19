#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>
#include <cmath>


using namespace std;


template <typename Item>
class MaxHeap{
    
private:
    Item* data;
    int count;
    int capacity;

    void shiftUp(int index)
    {
        // 当父节点的值小于当前节点的值时执行循环 index > 1 代表已经是根节点了
        //index/2 代表当前节点的父节点索引 index代表当前节点的索引 父节点小于当前节点交换位置
        while (index > 1 &&  data[index/2] < data[index]) {
            // 交换当前节点和父节点的值
            swap(data[index], data[index/2]);
            // 将索引更新为当前节点的父节点索引
            index /= 2;
        }
    }

    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

public:
    /**
     * @brief 构造函数，初始化最大堆
     *
     * 根据给定的容量初始化最大堆。
     *
     * @param capacity 最大堆的容量
     */
    MaxHeap(int capacity): count(0), capacity(capacity){
        data = new Item[capacity + 1];  // 索引从1开始
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size() 
    {
        return count;
    }

    /**
     * @brief 判断是否为空
     *
     * 检查当前对象的元素数量是否为0，即是否为空。
     *
     * @return 如果元素数量为0，则返回true；否则返回false。
     */
    bool isEmpty()
    {
        return count == 0;
    }

    void insert(Item item)
    {
        assert(count + 1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }

    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }
};



int main()
{
    MaxHeap<int> max_heap(100);

    srand48(time(NULL));
    for (size_t i = 0; i < 20; i++)
    {
        max_heap.insert(rand()%100);
        /* code */
    }
    
    max_heap.testPrint();

    // cout << max_heap.size() << endl;
    return 0;
}