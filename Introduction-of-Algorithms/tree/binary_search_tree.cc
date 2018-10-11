/* Binary Search Tree */

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct node 
{
    node *left;
    node *right;
    T data;
    node(T &val=T()) : left(0), right(0), data(val) {}
};

template<typename T>
class BinSearchTree
{
    private:
        node<T> *root;
    
    public:
        BinSearchTree() : root(0) {}

        void construct(vector<T> &nums);
        node<T> *find(T &x) const;
        void insert(T &x);
        void remove(T &x);

        void preorder_traversal() const;
        void inorder_traversal() const;
        void postorder_traversal() const;

        T maximum() const;
        T minimum() const;

        node<T> *successor(node<T> *p) const;
        node<T> *presuccessor(node<T> *p) const;
};

template<typename T>
void BinSearchTree<T>::construct(vector<T> &nums)
{
    for (auto &x : nums)    
        insert(x);
}

template<typename T>
node<T> *BinSearchTree<T>::find(T &x) const
{
    node<T> *p = root;
    while (p != 0)
    {
        if (p->data == x)   return p;
        else if (p->data > x)   p = p->left;
        else    p = p->right;
    }
    return 0;
}

template<typename T>
void BinSearchTree<T>::insert(T &x)
{
    node<T> *new_node = new node<T>(x);
    if (root == 0)  { root = new_node; return; }
    node<T> *parent = 0, *child = root;
    while (child != 0)
    {
        parent = child;
        if (x <= child->data)   child = child->left;
        else    child = child->right;
    }
    if (x <= parent->data)   parent->left = new_node;
    else    parent->right = new_node;
}

template<typename T>
void BinSearchTree<T>::remove(T &x)
{
    
}

template<typename T>
void BinSearchTree<T>::preorder_traversal() const
{
    node<T> *p = root, *free = 0;
    while (p != 0)
    {
        free = p->left;
        if (free != 0)
        {
            while (free->right!=0 && free->right!=p)
                free = free->right;
            if (free->right == 0)
            {
                cout << p->data << "\t";
                free->right = p;
                p = p->left;
                continue;
            }
            else    free->right = 0;
        }
        else    cout << p->data << "\t";
        p = p->right;
    }
}

template<typename T>
void BinSearchTree<T>::inorder_traversal() const
{
    node<T> *p = root, *free = 0;
    while (p != 0)
    {
        free = p->left;
        if (free != 0)
        {
            while (free->right!=0 && free->right!=p)
                free = free->right;
            if (free->right == 0)
            {
                free->right = p;
                p = p->left;
                continue;
            }
            else    free->right = 0;
        }
        cout << p->data << "\t";
        p = p->right;
    }
}

template<typename T>
T BinSearchTree<T>::maximum() const
{
    node<T> *p = root;
    while (p->right != 0)
        p = p->right;
    return p->data;
}

template<typename T>
T BinSearchTree<T>::minimum() const
{
    node<T> *p = root;
    while (p->left != 0)
        p = p->left;
    return p->data;
}

template<typename T>
node<T> *BinSearchTree<T>::successor(node<T> *p) const
{
    if (p->right == 0)  return 0;
    p = p->right;
    while (p->left != 0)
        p = p->left;
    return p;
}

template<typename T>
node<T> *BinSearchTree<T>::presuccessor(node<T> *p) const
{
    if (p->left == 0)   return 0;
    p = p->left;
    while (p->right != 0)
        p = p->right;
    return p;
}

int main(int argc, char **argv)
{
    BinSearchTree<int> bst;
    vector<int> nums;
    int x;
    for (int i = 0; i < 10; ++ i)
    {
        cin >> x;
        nums.push_back(x);
    }
    bst.construct(nums);
    //bst.preorder_traversal();
    //cout << endl;
    bst.inorder_traversal();
    cout << endl;
    cout << "MIN is " << bst.minimum() << ", MAX is " << bst.maximum() << endl;
    return 0;
}