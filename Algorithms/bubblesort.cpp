#include <iostream>
#include <ctime>
#include <cstdlib>

void print(int* S, int n);
void init(int* S, int n);
void BubbleSort(int* S, int n);

main(){

    int n = 20;   
    int *S = new int[n];
    init(S, n);
    print(S, n);
    BubbleSort(S, n);
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
void BubbleSort(int* S, int n){
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>=i; j--)
        {
            if(S[j]<S[j-1])
            {
                int tmp = S[j];
                S[j] = S[j-1];
                S[j-1] = tmp;
            }
        }
    }
}