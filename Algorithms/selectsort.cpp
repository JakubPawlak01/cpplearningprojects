#include <iostream>
#include <ctime>
#include <cstdlib>


void print(int* S, int n);               //printing
void init(int* S, int n);              //generating random number 
void SelectSort(int* S, int n);

int main(){

    int n = 20;   
    int *S = new int[n];
    init(S, n);
    print(S, n);
    SelectSort(S, n);
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

void SelectSort(int* S, int n){
    for(int i=0; i<n-1; i++)
    {
        int tmp = 0;
        int min = i;
        for(int j=i+1; j<n; j++)
            {
                if(S[j]<S[min]) min = j;
            }
            std::swap(S[i],S[min]);
    }
}