#include <iostream>

class MinHeap{
    private:
        int* kopiec;
        int capacity;
        int size;

    public:
        MinHeap(int c){
            capacity = c;
            kopiec = new int[capacity];
            size = 0;
        }

        bool empty(){
            if(size == 0) return 1;
            return 0;
        }

        bool full(){
            if(size == capacity) return 1;
            return 0;
        }
        
        int getLeft(int i){
            if(2*i+1 < size) return 2*i +1;
            else return -1;

        }

        int getRight(int i){
            if(2*i+2 < size) return 2*i +2;
            else return -1;
        }

       int getParent(int i){
        if(i == 0) return -1;
        else return (i-1) / 2;
        }

        int getSize(){
            return size;
        }       

        void setSize(int s){
            size = s;
        }

        int getValue(int i){
            return kopiec[i];
        }

        void setValue(int i, int x){
            kopiec[i] = x;
        }

        void bottomUp(int i){
            if(i > 0)
            {
                int p = getParent(i);
                if(kopiec[i] < kopiec[p])
                {
                    int tmp = kopiec[i];
                    kopiec[i] = kopiec[p];
                    kopiec[p] = tmp;
                    bottomUp(p);
                }
            }
        }

        void topDown(int i){
            int l = getLeft(i);
            int r = getRight(i);
            int g = i;
            if(l != -1 && kopiec[l] < kopiec[i])
            {
                g = l;
            }
            if(r != -1 && kopiec[r] < kopiec[i])
            {
                g = r;
            }
            if(g != i)
            {
                int tmp = kopiec[i];
                kopiec[i] = kopiec[g];
                kopiec[g] = tmp;
                topDown(g);
            }
        }

        friend std::ostream& operator<<(std::ostream& out, MinHeap& h){
            for(int i=0; i<h.size; i++)
            {
                out<<h.kopiec[i]<< " ";
            }
            return out;
        }

        void insert(int x){
            if(full())
            {
                std::cout << "kopiec pelny";
            }
            else
            {
                kopiec[size] = x;
                bottomUp(size);
                size++;
            }
        }

        void delMin(){
            if(empty())
            {
                std::cout << "pusty";
            }
            else
            {
                size--;
                int tmp = kopiec[0];
                kopiec[0] = kopiec[size];
                kopiec[size] = tmp;
                topDown(0);
            }
        }

        void del(int k){
            if(empty())
            {
                std::cout << "pusty";
            }
            else
            {
                size--;
                int tmp = kopiec[k];
                kopiec[k] = kopiec[size];
                kopiec[size] = tmp;
                topDown(k);
                bottomUp(k);
            }
        }        

        int minumum(){
             return kopiec[0];   
        }

};

int main(){

    return 0;
}
