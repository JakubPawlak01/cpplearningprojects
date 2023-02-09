#include <iostream>
#include <ctime>
#include <cstdlib>

void print(int* S, int n);
void init(int* S, int n);
void Merge(int* S, int start, int mid, int end);
void MergeSort(int* S, int start, int end);

main(){

    int n = 20;   
    int *S = new int[n];
    init(S, n);
    print(S, n);
    MergeSort(S, 0, n-1);
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

void Merge(int* S, int start, int mid, int end){
    int *D = new int[end-start+1]; 
    int i = start;
    int j = mid + 1;
    for(int k = 0; k <= end-start; k++)
    {
        if(i>mid)
        {
            D[k] = S[j];
            j++;
        }
        else if(j>end)
        {
            D[k] = S[i];
            i++;
        }
        else if(S[i] <= S[j])
        {
            D[k] = S[i];
            i++;
        }
        else
        {
            D[k] = S[j];
            j++;
        }
    }

    for(int z = start; z<=end; z++)
    {
        S[z] = D[z-start];
    }
}

void MergeSort(int* S, int start, int end){
    if(start<end)
    {
        int mid = (start+end)/2;
        MergeSort(S, start, mid);
        MergeSort(S, mid + 1, end);
        Merge(S, start, mid, end);
    }
}