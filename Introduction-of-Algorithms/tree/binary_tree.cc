/* Bianry Tree */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
class BinTree 
{
    private:
        struct tree_node 
        {
            tree_node *left;
            tree_node *right;
            T data;
            tree_node(T &val=T()) : left(0), right(0), data(val) {}
        };

        tree_node *root;
        tree_node *construct_binary_tree(vector<T> &nums, int l, int r);

    public:
        BinTree(vector<T> &nums)
        {
            root = construct_binary_tree(nums, 0, nums.size()-1);
        }

        void preorder_traversal() const;
        void inorder_traversal() const;
        void postorder_traversal() const;
        void levelorder_traversal() const;
        void morris_preorder_traversal() const;
        void morris_inorder_traversal() const;
};

template<typename T>
typename BinTree<T>::tree_node *BinTree<T>::construct_binary_tree(vector<T> &nums, int l, int r)
{
    if (l > r)  return 0;
    int mid = l + (r-l) / 2;
    tree_node *root = new tree_node(nums[mid]);
    root->left = construct_binary_tree(nums, l, mid-1);
    root->right = construct_binary_tree(nums, mid+1, r);
    return root;
}

template<typename T>
void BinTree<T>::preorder_traversal() const
{
    if (root == 0)
    {
        cout << "Empty tree." << endl;
        return;
    }
    stack<tree_node *> s;
    tree_node *p = root;
    while (p!=0 || !s.empty())
    {
        if (p != 0)
        {
            cout << p->data << "\t";
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

template<typename T>
void BinTree<T>::inorder_traversal() const
{
    if (root == 0)
    {
        cout << "Empty Tree..." << endl;
        return;
    }
    stack<tree_node *> s;
    tree_node *p = root;
    while (p!=0 || !s.empty())
    {
        if (p != 0)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->data << "\t";
            p = p->right;
        }
    }
}

template<typename T>
void BinTree<T>::postorder_traversal() const
{
    if (root == 0)
    {
        cout << "Empty Tree..." << endl;
        return;
    }
    stack<tree_node *> s;
    tree_node *p = root, *last = 0;
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
            cout << p->data << "\t";
            s.pop();
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
void BinTree<T>::levelorder_traversal() const
{
    if (root == 0)
    {
        cout << "Empty Tree..." << endl;
        return;
    }
    queue<tree_node *> q;
    q.push(root);
    while (!q.empty())
    {
        tree_node *p = q.front();
        q.pop();
        cout << p->data << "\t";
        if (p->left != 0)
            q.push(p->left);
        if (p->right != 0)
            q.push(p->right);
    }
}

template<typename T>
void BinTree<T>::morris_preorder_traversal() const
{
    if (root == 0)
    {
        cout << "Empty Tree..." << endl;
        return;
    }
    tree_node *p = root, *free = 0;
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
                cout << p->data << "\t";
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
void BinTree<T>::morris_inorder_traversal() const
{
    if (root == 0)
    {
        cout << "Empty Tree..." << endl;
        return;
    }
    tree_node *p = root, *free = 0;
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

int main(int argc, char **argv)
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    BinTree<int> bt(nums);
    bt.preorder_traversal();
    cout << endl;
    bt.morris_preorder_traversal();
    cout << endl;
    bt.inorder_traversal();
    cout << endl;
    bt.morris_inorder_traversal();
    cout << endl;
    bt.postorder_traversal();
    cout << endl;
    bt.levelorder_traversal();
    cout << endl;
    return 0;
}