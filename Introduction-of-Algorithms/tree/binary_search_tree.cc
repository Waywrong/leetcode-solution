/* Binary Search Tree */

#include <iostream>
#include <vector>
#include <stack>
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
    node<T> *parent = 0, *child = root;
    while (child != 0)
    {
        if (x == child->data)   break;
        parent = child;
        if (x < child->data)    child = child->left;
        else    child = child->right;
    }    
    if (child->left==0 && child->right==0)
    {
        if (parent != 0)
        {
            if (child == parent->left)  parent->left = 0;
            else    parent->right = 0;
        }
        delete child;
    }
    else if (child->left==0 || child->right==0)
    {
        if (parent != 0)
        {
            if (child == parent->left)
                parent->left = child->left ? child->left : child->right;
            else
                parent->right = child->left ? child->left : child->right;
        }
        else    root = child->left ? child->left : child->right;
        delete child;
    }
    else
    {
        node<T> *pre = child, *cur = child->right;
        while (child->left != 0)
        {
            pre = cur;
            cur = cur->left;
        }
        T tmp = cur->data; cur->data = child->data; child->data = tmp;
        if (cur == child->right)    pre->right = cur->right;
        else    pre->left = cur->right;
        delete cur;
    }
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
void BinSearchTree<T>::postorder_traversal() const
{
    stack<node<T> *> s;
    node<T> *p = root, *last = 0;
    while (p != 0)
    {
        s.push(p);
        p = p->left;
    }
    while (!s.empty())
    {
        p = s.top();
        if (p->right==0 || p->right==last)
        {
            s.pop();
            cout << p->data << "\t";
            last = p;
        }
        else
        {
            p = p->right;
            while (p != 0)
            {
                s.push(p);
                p = p->left;
            }
        }
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
    while (cin >> x)
    {
        bst.remove(x);
        bst.inorder_traversal();
        cout << endl;
    }
    //cout << "MIN is " << bst.minimum() << ", MAX is " << bst.maximum() << endl;
    //bst.postorder_traversal();
    //cout << endl;
    return 0;
}