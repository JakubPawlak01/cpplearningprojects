#include <iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* left;
        Node* right;
        Node* parent;

    public:
        Node(int v, Node* l, Node* r, Node* p){
            value = v;
            left = l;
            right = r;
            parent = p;
        }

        int getValue(){
            return value;
        }

        Node* getLeft(){
            return left;
        }

        Node* getRight(){
            return right;
        }

        Node* getParent(){
            return parent;
        }

        void setValue(int v){
            value = v;
        }

        void setLeft(Node* l){
            left = l;
        }

        void setRight(Node* r){
            right = r;
        }

        void setParent(Node* p){
            parent = p;
        }
};

class BSTree{
    private:
        Node* root;

    public:
        BSTree(){
            root = nullptr;
        }

        Node* getRoot(){
            return root;
        }

        bool empty(Node* p){
            if(p == nullptr) return 1;
            return 0;
        }

        void inorder(Node* p){
            if(!empty(p))
            {
                inorder(p->getLeft());
                cout << p->getValue();
                inorder(p->getRight());
            }
        }

        void insert(int x){
            Node* e = new Node(x, nullptr, nullptr, nullptr);
            if(empty(root))
            {
                root = e;
            }
            else
            {
                Node* p = root;

                while(1)
                {
                    if(p->getValue() > e->getValue())
                    {
                        if(!empty(p->getLeft()))
                        {
                            p = p->getLeft();
                        }
                        else
                        {
                            p->setLeft(e);
                            e->setParent(p);
                            break;
                        }
                    }
                    else if(p->getValue() < e->getValue())
                    {
                        if(!empty(p->getRight()))
                        {
                            p = p->getRight();
                        }
                        else
                        {
                            p->setRight(e);
                            e->setParent(p);
                            break;
                        }
                    }
                }
            }
        }

        Node* search(int x){
            Node* n = root;
            while(!empty(n) && n->getValue() != x)
            {
                if(n->getValue() > x)
                {
                    n = n->getLeft();
                }
                else
                {
                    n = n->getRight();
                }
            return n;
            }
        }

        Node* minimum(Node* p){
            if(empty(root))
            {
                return nullptr;
            }
            else
            {
                Node* e = getRoot();
                while(!empty(e->getLeft()))
                {
                    e = e->getLeft();
                }
                return e;
            }
        }

        Node* maximum(Node* p){
            if(empty(root))
            {
                return nullptr;
            }
            else
            {
                Node* e = getRoot();
                while(!empty(e->getRight()))
                {
                    e = e->getRight();
                }
                return e;
            }
        }

        //void del(Node *p);

        int size(Node* p){
            if(empty(p)) return  0;
            else return (1 + size(p->getLeft()) + size(p->getRight()));
        }

        int height(Node* p){
            if(empty(p)) return -1;
            else return (1 + max(height(p->getLeft()),height(p->getRight())));
        }
};


main(){

    BSTree* t = new BSTree();
    t->insert(10);
    t->insert(11);
    t->insert(9);
    t->insert(8);
    t->insert(12);
    t->inorder(t->getRoot());

    return 0;
}
