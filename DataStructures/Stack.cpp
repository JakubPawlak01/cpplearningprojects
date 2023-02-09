#include <iostream>
#include <cstdlib>
#include <ctime>


class Element{
    private:
        int value;
        Element* next;

    public:
        Element(int x, Element* next){
            value = x;
            next = next;
        }

        int getValue(){
            return value;
        }

        Element* getNext(){
            return next;
        }

        void setNext(Element* p){
            next = p;
        }
};

class LinkedStack{
    private:
        Element* top;

    public:
        LinkedStack(){
            top = nullptr;
        }

        bool empty(){
            if(top == nullptr)return 1;
            return 0;
        }
        
        void push(int x){ 
            Element* p = new Element(x, top);
            top = p;
        }

        int peek(){
            return top->getValue();
        }

        void pop(){
            Element* p = top;
            top = top->getNext();
            delete p;
        }

        void clear(){
            while(!empty())
            {
                pop();
            }
        } 

        friend std::ostream& operator<<(std::ostream& out, LinkedStack* s){
            Element* p = s->top;
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