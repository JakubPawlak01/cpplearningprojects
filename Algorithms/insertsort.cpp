#include <iostream>
#include <ctime>
#include <cstdlib>

void print(int* S, int n);
void init(int* S, int n);
void InsertSort(int* S, int n);

main(){

    int n = 20;   
    int *S = new int[n];
    init(S, n);
    print(S, n);
    InsertSort(S, n);
    print(S, n);
    return 0;
}

void print(int* S, int n){               //printing
    for(int i=0; i<n; i++)
    {
        std::cout << S[i] <<" ";
    }
    std::cout<<std::endl;
}

void init(int* S, int n){               //generating random number 
    for(int i=0; i<n; i++)
    {
        S[i] = rand()%100;
    }
}

void InsertSort(int* S, int n){
    for(int i=1; i<n; i++)
    {
        int tmp = S[i];
        int j = i-1;
        for(j; j>=0; j--)
        {
            if(S[j]>tmp) S[j+1] = S[j];
            else break;
        }
        S[j+1] = tmp;
    }
}