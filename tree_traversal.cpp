#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val)
    {
        value = val;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
class Tree
{
private:
    Node *root = NULL;
    void preOrder(Node *rt)
    {
        if (rt == NULL)
            return;
        cout << rt->value << " ";
        preOrder(rt->left);
        preOrder(rt->right);
    }
    void postOrder(Node *rt)
    {
        if (rt == NULL)
            return;
        postOrder(rt->left);
        postOrder(rt->right);
        cout << rt->value << " ";
    }
    void inOrder(Node *rt)
    {
        if (rt == NULL)
            return;
        inOrder(rt->left);
        cout << rt->value << " ";
        inOrder(rt->right);
    }

public:
    Tree(Node *rt)
    {
        root = rt;
    }
    ~Tree()
    {
        delete root;
    }
    void preOrder()
    {
        cout << "PreOrder Traversal: \n";
        preOrder(root);
        cout << "\n";
    }
    void postOrder()
    {
        cout << "PostOrder Traversal: \n";
        postOrder(root);
        cout << "\n";
    }
    void inOrder()
    {
        cout << "InOrder Traversal: \n";
        inOrder(root);
        cout << "\n";
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Tree t1(root);
    cout << "       1\n";
    cout << "    /    \\ \n";
    cout << "   2      3\n";
    cout << "  / \\   /  \\ \n";
    cout << " 4   5 6    7\n";
    //       1
    //    /    \
    //   2     3
    //  / \   / \
    // 4   5 6   7
    t1.inOrder();
    t1.postOrder();
    t1.preOrder();

    return 0;
}
