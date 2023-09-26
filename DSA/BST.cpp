#include <iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class BST{
    private:
        Node *root;
    public:
        BST(){
            root = nullptr;
        }
        Node* getRoot(){
            return root;
        }
        void Insert(int key);
        void Inorder(Node* p);
        Node* Search(int key);
};

void BST::Insert(int key){
    Node* t = root;
    Node* p;
    Node* r;

    // Empty root
    if(root==nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while(t!=nullptr){
        r = t;
        if (key<t->data){
            t = t->lchild;
        }else if(key>t->data){
            t =  t->rchild;
        }else{
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if(key<r->data){
        r->lchild = p;
    } else{
        r->rchild = p;
    }

}

void BST::Inorder(Node* p){
    if (p){
        Inorder(p->lchild);
        cout << p->data<<" ";
        Inorder(p->rchild);
    }
}

Node* BST:: Search(int key){
    Node* t = root;
    while(t != nullptr){
        if(key==t->data){
            return t;
        }else if(key<t->data){
            t = t->lchild;
        }else{
            t = t->rchild;
        }
    }
    return nullptr;
}

int main(){
    BST bst;
    bst.Insert(10);
    bst.Insert(13);
    bst.Insert(2);
    bst.Insert(9);
    bst.Insert(1);

    bst.Inorder(bst.getRoot());
    return 0;
}