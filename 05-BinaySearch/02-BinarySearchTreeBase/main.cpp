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


