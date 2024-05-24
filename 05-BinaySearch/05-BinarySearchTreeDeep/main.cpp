#include <iostream>
#include <vector>
#include "SequenceST.h"
#include "FileOps.h"

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

    void destroy(Node* node){
        if(node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
        count--;
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


int main(int argc, char const *argv[])
{
    // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();;
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "二分搜索树 BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "第三方库 SequenceST SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }
    return 0;
}
