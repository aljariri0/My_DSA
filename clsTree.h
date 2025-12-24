#pragma once
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <class T>
class clsTree {

private:

    class TreeNode {

    public:

        TreeNode* lchild;
        T data;
        TreeNode* rchild;
    };

    queue<TreeNode*> node_queue;

    TreeNode* root = nullptr;

public:

    TreeNode* GetRoot() {

        return root;
    }


    void CreateTree() {

        T x;
        root = new TreeNode;

        cout << "\nEnter Root value: ";
        cin >> root->data;
        root->lchild = root->rchild = nullptr;

        node_queue.push(root);

        TreeNode* p = nullptr;

        while (!node_queue.empty()) {

            p = node_queue.front();

            cout << "\nEnter left child of " << p->data << " : ";
            cin >> x;

            if (x != -1) {

                TreeNode* t = new TreeNode;
                t->data = x;
                t->lchild = t->rchild = nullptr;

                p->lchild = t;
                node_queue.push(t);
            }

            cout << "\nEnter right child of " << p->data << " : ";
            cin >> x;

            if (x != -1) {

                TreeNode* t = new TreeNode;
                t->data = x;
                t->lchild = t->rchild = nullptr;

                p->rchild = t;
                node_queue.push(t);
            }

            node_queue.pop();
        }
    }

    void RPreOrder(TreeNode* p) {


        if (p) {

            cout << p->data << " ";
            RPreOrder(p->lchild);
            RPreOrder(p->rchild);
        }
    }

    void RInOrder(TreeNode* p) {

        if (p) {

            RInOrder(p->lchild);
            cout << p->data << " ";
            RInOrder(p->rchild);
        }
    }

    void RPostOrder() {

        TreeNode* p = root;

        if (p) {


            PostOrder(p->lchild);
            PostOrder(p->rchild);
            cout << p->data << " ";
        }
    }

    void IterativePreOrder() {

        TreeNode* p = root;
        stack<TreeNode*> Stack;

        while (p != nullptr || !Stack.empty()) {

            if (p) {

                cout << p->data << " ";
                Stack.push(p);
                p = p->lchild;
            }

            else if (p == nullptr) {

                p = Stack.top();
                Stack.pop();
                p = p->rchild;
            }

        }
    }

    void IterativeInOrder(TreeNode* p) {

        stack<TreeNode*> Stack;

        while (p != nullptr || !Stack.empty()) {

            if (p) {

                Stack.push(p);
                p = p->lchild;
            }

            else if (p == nullptr) {

                p = Stack.top();
                Stack.pop();

                cout << p->data << " ";
                p = p->rchild;
            }

        }
    }

    void LevelOrder() {

        TreeNode* p = root;
        queue<TreeNode*> level_queue;

        cout << p->data << " ";
        level_queue.push(p);

        while (!level_queue.empty()) {

            p = level_queue.front();

            if (p->lchild) {

                cout << p->lchild->data << " ";
                level_queue.push(p->lchild);
            }

            if (p->rchild) {

                cout << p->rchild->data << " ";
                level_queue.push(p->rchild);
            }

            level_queue.pop();
        }
    }

    int CountNodes(TreeNode* p) {

        int x, y;

        if (p) {

            x = CountNodes(p->lchild);
            y = CountNodes(p->rchild);

            return x + y + 1; // instread return x + y + p->data to summ all nodes
        }

        return 0;
    }

    int CountLeafNodes(TreeNode* p) {

        int x, y;

        if (p) {

            x = CountLeafNodes(p->lchild);
            y = CountLeafNodes(p->rchild);

            if (p->lchild == nullptr && p->lchild == nullptr)
                return x + y + 1;

            return x + y;
        }

        return 0;
    }

    TreeNode* RSearch(TreeNode* p, T key) {

        if (p == nullptr)
            return nullptr;

        else if (p->data == key)
            return p;

        else if (p->data < key)
            return RSearch(p->rchild, key);

        else if (p->data > key)
            return RSearch(p->lchild, key);
    }

    TreeNode* ISearch(TreeNode* p, T key) {

        while (p) {

            if (p->data == key)
                return p;

            if (p->data < key)
                p = p->rchild;

            if (p->data > key)
                p = p->lchild;
        }

        return nullptr;
    }

    void Insert(T value) {

        TreeNode* r = root;
        TreeNode* q = nullptr;


        while (r) {

            q = r;

            if (r->data == value)
                return;

            else if (r->data < value)
                r = r->rchild;

            else if (r->data > value)
                r = r->lchild;
        }

        TreeNode* temp = new TreeNode;
        temp->data = value;
        temp->lchild = temp->rchild = nullptr;

        if (q == nullptr) {

            root = temp;
            return;
        }

        if (q->data < value)
            q->rchild = temp;
        else if (q->data > value)
            q->lchild = temp;
    }

    int Height(TreeNode* p) {

        int x, y;

        if (p == nullptr)
            return 0;

        x = Height(p->lchild);
        y = Height(p->rchild);

        if (x > y)
            return x + 1;

        else if (y > x)
            return y + 1;
    }

    TreeNode* FindInorderPredecssor(TreeNode* p) {

        p = p->lchild;

        while (p && p->rchild != nullptr) {

            p = p->rchild;
        }

        return p;
    }

    TreeNode* FindInorderSuccessor(TreeNode* p) {

        p = p->rchild;

        while (p && p->lchild != nullptr) {

            p = p->lchild;
        }

        return p;
    }

    TreeNode* Delete(TreeNode* p, T key) {

        TreeNode* q = nullptr;

        if (p == nullptr) {

            return nullptr;
        }

        if (p->lchild == nullptr && p->rchild == nullptr) {

            if (root == p) {

                root = nullptr;
            }

            delete p;
            return nullptr;
        }

        if (key < p->data)
            p->lchild = Delete(p->lchild, key);
        
        else if (key > p->data)
            p->rchild = Delete(p->rchild, key);


        else if (key == p->data) {

            if (Height(p->lchild) > Height(p->rchild)) {
                q = FindInorderPredecssor(p);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }

            else {
                q = FindInorderSuccessor(p);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }

        return p;
    }



};

/*
    clsTree() {

        clsTreeNode* p, * temp;
        int value;

        clsQueue<clsTreeNode*> queue;

        cout << "Enter root value: ";
        cin >> value;

        root = new clsTreeNode;
        root->data = value;
        root->lchild = nullptr;
        root->rchild = nullptr;

        queue.EnQueue(root);

        while (!queue.IsEmpty()) {

            p = queue.DeQueue();

            cout << "\nEnter left child value of " << p->data << " : ";
            cin >> value;

            if (value != -1) {

                temp = new clsTreeNode;
                temp->data = value;
                temp->lchild = nullptr;
                temp->rchild = nullptr;
                queue.EnQueue(temp);

                p->lchild = temp;
            }

            cout << "\nEnter right child value of " << p->data << " : ";
            cin >> value;

            if (value != -1) {

                temp = new clsTreeNode;
                temp->data = value;
                temp->lchild = nullptr;
                temp->rchild = nullptr;
                queue.EnQueue(temp);

                p->rchild = temp;
            }
        }

    }


    // travels by using recursion
    void PreOrder(clsTreeNode* p) {

        if (p) {

            cout << p->data << endl;

            PreOrder(p->lchild);
            PreOrder(p->rchild);
        }
    }

    void InOrder(clsTreeNode* p) {

        if (p) {

            PreOrder(p->lchild);
            cout << p->data << endl;
            PreOrder(p->rchild);
        }
    }

    void PostOrder(clsTreeNode* p) {

        if (p) {

            PreOrder(p->lchild);
            PreOrder(p->rchild);
            cout << p->data << endl;
        }
    }

    clsTreeNode* GetRoot() {

        return root;
    }


    // travels by using iterative

*/
