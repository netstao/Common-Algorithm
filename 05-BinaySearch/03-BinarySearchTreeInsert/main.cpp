#include <iostream>

using namespace std;


template <typename Key, typename Value>
class BST
{
private:
    struct Node {
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
    };

    Node *root;
    int count;

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
            // 如果键相等，则更新当前节点的值
            node->value = value;
        else if( key < node->key )
            // 如果键小于当前节点的键，则在左子树中插入
            node->left = insert( node->left , key, value);
        else    // key > node->key
            // 如果键大于当前节点的键，则在右子树中插入
            node->right = insert( node->right, key, value);
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
    }

    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
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


int main(int argc, char const *argv[])
{
    return 0;
}


