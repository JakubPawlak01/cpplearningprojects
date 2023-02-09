#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ArrayFifo{
    private:
        int* items;
        int capacity;            
        int size;                
        int head;               
        int tail;

    public:
        ArrayFifo(int c){
            capacity = c;
            size = 0;
            head = -1;
            tail = -1;
            items = new int[capacity];
        }

        bool empty(){
            if(size == 0) return 1;
            return 0;
        }

        bool full(){
            if(size == capacity)return 1;
            return 0;
        }

        void enqueue(int x){
            if(full())
            {
                std::cout << "pelna!";
            }
            else
            {
                size++;
                tail = (tail + 1) % capacity;
                items[tail] = x;
            }
        }

        int peek(){
            return items[head];
        }

        void dequeue(){
            size--;
            int tmp = head;
            head = (head+1) % capacity;
            items[tmp] = 0;
        }

        void clear(){
            size = 0;
            head = -1;
            tail = -1;
            delete[] items;
        }

        friend std::ostream& operator<<(std::ostream& out, ArrayFifo& f){
            for(int i = f.head; i <= f.tail; i++)
            {
                out << f.items[i] << " ";
            }
            return out;
        }
};

int main(){

    return 0;
}
