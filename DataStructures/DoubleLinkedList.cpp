#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Element{
    private:
        int v;
        Element* next;
        Element* prev;

    public:
        Element(){
            v = 0;
            next = nullptr;
            prev = nullptr;
        }

        Element(int x, Element* next, Element* prev){
            v = x;
            next = next;
            prev = prev;
        }

        int getValue(){
            return v;
        }

        void setValue(int v){
            v = v;
        }

        Element* getNext(){
            return next;
        }

        Element* getPrev(){
            return prev;
        }

        void setNext(Element* p){
            next = p;
        }

        void setPrev(Element* p){
            prev = p;
        }
};


class DoubleLinkedList{
    private:
        Element* head;
        Element* tail;
        int size;
    
    public:
        DoubleLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        bool empty(){
            if(size == 0) return 1;
            return 0;
        }

        int getSize(){
            return size;
        }

        Element* getFirst(){
            return head;

        }
        Element* getLast(){
            return tail;
        }

        Element* getNext(Element *p){
            return p->getNext();
        }

        Element* getPrev(Element *p){
            return p->getPrev();
        }

        int retrive(Element* p){
            return p->getValue();
        }

        Element* locate(int x){
            if(empty()) cout << "pusto";
            else
            {
                Element* p;
                p = head;
                while(p != nullptr)
                {
                    if(p->getValue() == x)
                    {
                        return p;
                    }
                    else
                    {
                        p = p->getNext();
                    }
                }
                return p;
            }
        }

        void append(int x){
            Element* p = new Element(x, nullptr, tail);
            tail = p;
        }

        void prepend(int x){
            Element* p = new Element(x, head, nullptr);
            head = p;
        }

        void insert(Element* k, int x){
            Element* p = new Element(x, nullptr, nullptr);
            Element* e = k->getPrev();
            e->setNext(p);
            k->setPrev(p);
            p->setPrev(e);
            p->setNext(k);

        }

        void del(Element *k){
            Element* p = k->getPrev();
            Element* e = k->getNext();
            p->setNext(e);
            e->setPrev(p);
            delete k;
        }

        friend ostream& operator<<(ostream& out, DoubleLinkedList* l){
            Element* p = l->head;
            while(p != nullptr)
            {
                out << p->getValue() << " ";
                p = p->getNext();
            }
            return out;
        }
        
};

int main(){
    
    return 0;
}