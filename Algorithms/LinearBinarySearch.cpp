#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void print(int* S, int n){  
    for(int i = 0; i < n; i++)
    cout << S[i] << endl;
}

void initSorted(int* S, int n){
    S[0]=2; for(int i=1; i<n; i++) S[i]=S[i-1]+rand()%4;
}

int linearSearch1(int* S, int n, int x){
    for(int i = 0; i < n; i++)
    {
        if(S[i] == x)
        return i; 
    }
}
int binarySearch1(int* S, int n, int x){
     int left = 0;
     int right = n-1;
     int mid = 0;
     while(left <= right)
     {
        mid = (left + right) / 2;
        if(S[mid] == x)
        {
            return mid;
        }
        else if(S[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
     }
     return -1;
}


int main()
{
    return 0;
}