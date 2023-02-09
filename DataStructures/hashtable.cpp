#include <iostream>
#include <string>
#include <cmath>

class HashTable{
    private:
        std::string* t;
        int capacity;
        int size;

    public:
        HashTable(int c){
            capacity = c;
            size = 0;
            t = new std::string[c];
        }

        bool empty(){
            if(size == 0)return 1;
            return 0;
        }

        bool full(){
            if(size == capacity) return 1;
            return 0;
        }            
               
 /*       int hashFunction(std::string s){
            double k = 0;
            for(int i = 0; i < s.size(); i++)
                k += s[i];
            double kA = k * 0.6180339887;
            int index = (int)(capacity * (kA - floor(kA)));
            return index;
        }
*/

        int hashFunction(std::string s){
            int sum = 0;
            for(int i = 0; i < s.size(); i++)
                sum += s[i];
            return sum % capacity;
        }

        void insert(std::string s){
            if(!full())
            {
                int index = hashFunction(s);
                while(t[index] != "")
                    index = (index + 1) % capacity;
                t[index] = s;
                size++;
            }
        }
        
        void del(std::string s){
            int index = hashFunction(s);
            while(t[index] != s)
            {
                index = (index + 1) % capacity;
                if(t[index] == "")
                return;
            }
            t[index] = "";
            size--;
            int nextIndex = (index + 1) % capacity;
            while(t[nextIndex] != "")
            {
                std::string temp = t[nextIndex];
                t[nextIndex] = "";
                size--;
                insert(temp);
                nextIndex = (nextIndex + 1) % capacity;
            }
        }
        
        int search(std::string s){
            int index = hashFunction(s);
            while(t[index] != s)
            {
                index = (index + 1) % capacity;
                if(t[index] == "")
                return -1;
            }
            return index;
        }

        friend std::ostream& operator<<(std::ostream& out, HashTable& ht){
            for(int i = 0; i < ht.capacity; i++)
            {
                out << i << ": " << ht.t[i] << std::endl;
            }
            return out;
        }
};

int main(){

    return 0;
}
