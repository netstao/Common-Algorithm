#include <iostream>
#include <vector>
#include "SequenceST.h"
#include "FileOps.h"
#include <queue>
#include <algorithm>
#include <random>

using namespace std;

template <typename Key, typename Value>
class BST
{
private:
    struct Node 
    {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            // 将传入的key赋值给当前节点的key成员变量
            this->key = key;
            // 将传入的value赋值给当前节点的value成员变量
            this->value = value;
            // 将当前节点的左子节点和右子节点都初始化为NULL
            this->left = this->right = NULL;
        }

        Node(Node *node){
             // 复制节点的键值
             this->key = node->key;
             // 复制节点的值
             this->value = node->value;
             // 复制节点的左子节点
             this->left = node->left;
             // 复制节点的右子节点
             this->right = node->right;
         }
    };

    Node *root;
    int count;


private:

    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node *insert(Node *node, Key key, Value value)
    {
        if (node == NULL)
        {
            // 如果当前节点为空，则新建一个节点，并返回
            // 如果node为NULL，说明当前节点为空，新建一个节点，并返回
            count++;
            return new Node(key, value);
        }

        if( key == node->key )
        {
            // 如果键相等，则更新当前节点的值
            node->value = value;
        }
        else if( key < node->key )
        {
            // 如果键小于当前节点的键，则在左子树中插入
            node->left = insert( node->left , key, value);
        }
        else    // key > node->key
        {
            // 如果键大于当前节点的键，则在右子树中插入
            node->right = insert( node->right, key, value);
        }
        return node;
    }
    
    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
    bool contain(Node* node, Key key)
    {

        // 如果节点为空，说明搜索范围已到达空节点，返回false
        if( node == NULL )
            return false;

        // 如果当前节点的key与目标key相等，则返回true
        if( key == node->key ) 
        {
            // 如果目标key小于当前节点的key，则在左子树中继续搜索
            return true;
        }
        else if( key < node->key )
        {
            // 如果目标key大于当前节点的key，则在右子树中继续搜索
            return contain( node->left , key );
        }
        else
        {
            return contain( node->right , key );
        }
    }

    // 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
    Value * search(Node* node, Key key){

        if( node == NULL )
            return NULL;

        if( key == node->key )
        {
            return &(node->value);
        }
        else if( key < node->key )
        {
            return search( node->left , key );
        }
        else // key > node->key
        {
            return search( node->right, key );
        }
    }

    //前序遍历以node为根的二分搜索树
    void preOrder(Node* node){
        if( node == NULL )
            return;

        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // 中序遍历以node为根的二分搜索树
    void inOrder(Node* node){
        if( node == NULL )
            return;

        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

    // 后序遍历以node为根的二分搜索树
    void postOrder(Node* node){
        if( node == NULL )
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }

    //二分搜索树的层序遍历 广度优先遍历
    void levelOrder(Node* node){
        if( node == NULL )
            return;

        queue<Node*> q;
        q.push(node);

        // 当队列不为空时循环
        while(!q.empty()){
            // 取出队列的队首节点
            Node * current = q.front();
            // 输出当前节点的值
            cout << current->key << " ";

            // 遍历当前节点的左右子树，并将非空子节点入队
            // 如果当前节点的左子节点不为空，则将左子节点入队
            if(current->left != NULL)
                q.push(current->left);
            // 如果当前节点的右子节点不为空，则将右子节点入队
            if(current->right != NULL)
                q.push(current->right);

            // 弹出队首节点
            q.pop();
        }
    }

    void destroy(Node* node){
        if(node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
        count--;
    }

    // 查找最小值节点，即键最小的节点
    Key minMum(){
        assert(root != NULL);
        Node* node = root;

        while(node->left != NULL)
            node = node->left;
        return node->key;
    }

    Key maxMum(){
        assert(root != NULL);

        Node* node = root;

        if (node->right == NULL) return node;

        while(node->right != NULL)
            node = node->right;
        return node->key;
    }


    Node * removeMin(Node *node)
    {
        if(node->left == NULL)
        {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        else
        {
            Node *temp = removeMin(node->left);
            node->left = temp;
            return node;
        }
    }

    Node * removeMax(Node *node)
    {
        if(node->right == NULL)
        {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        else
        {
            node->right = removeMin(node->right);
            return node;
        }
    }

    Node * remove(Node* node, Key key){
        if(node == NULL)
            return nullptr;

        if (key < node->key)
        {
            node->left = remove(node->left, key);
            return node;
        } 
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
            return node;
        }
        else  // key == node->key
        {
            if (node->left == NULL)
            {
                Node * rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if (node->right == NULL)
            {
                Node * leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            // Node * delNode = node;

            //hibbbard deltion 
            Node * successor = new Node(minMum(node->right));
            count++;

            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete node;
            count--;

            return successor;
        }
    }
        
        

public:
    BST()
    {
        // 初始化根节点为NULL
        root = NULL;
        // 初始化节点个数为0
        count = 0;
    }
    ~BST(){
        // TODO: ~BST()  
        destroy(root);      
    }

    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // 查看二分搜索树中是否存在键key
    bool contain(Key key){
        return contain(root, key);
    }

    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
    Value* search(Key key){
        return search( root , key );
    }

    int size()
    {
        return count;
    }

    /**
     * @brief 判断容器是否为空
     *
     * 检查容器中的元素数量是否为0，即判断容器是否为空。
     *
     * @return 如果容器为空，返回true；否则返回false。
     */
    bool isEmpty()
    {
        return count == 0;
    }
};


void shuffle( int arr[], int n ){

    srand( time(NULL) );
    for( int i = n-1 ; i >= 0 ; i -- ){
        int x = rand()%(i+1);
        swap( arr[i] , arr[x] );
    }
}



int main(int argc, char const *argv[])
{
    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // 取n个取值范围在[0...n)的随机整数放进二分搜索树中
    int n = 10000;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // order数组中存放[0...n)的所有元素
    int order[n];
    for( int i = 0 ; i < n ; i ++ )
        order[i] = i;
    // 打乱order数组的顺序

    // 乱序删除[0...n)范围里的所有元素
    for( int i = 0 ; i < n ; i ++ )
        if( bst.contain( order[i] )){
            // bst.remove(Node &bst, order[i]);
            cout<<"After remove "<<order[i]<<" size = "<<bst.size()<<endl;
        }

    // 最终整个二分搜索树应该为空
    cout << bst.size() << endl;
    
    return 0;
}