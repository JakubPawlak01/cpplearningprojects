#include <iostream>
#include <ctime>
#include <cstdlib>

void print(int* S, int n);
void init(int* S, int n);
int ChoosePivot(int *S, int left, int right);
int Split(int* S, int left, int right);
void QuickSort(int* S, int left, int right);

main(){

    int n = 20;   
    int *S = new int[n];
    init(S, n);
    print(S, n);
    QuickSort(S, 0, n-1);
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

int ChoosePivot(int *S, int left, int right){
    int pivot = S[left];
    int count = 0;
    for(int i = left + 1; i <= right; i++)
    {
        if (S[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = left + count;
    return pivotIndex;
}

int Split(int* S, int left, int right){
    int index = ChoosePivot(S, left, right);
    std::swap(S[index], S[right]);
    int pivot = S[right];
    int i = left;
    for(int j = left; j<=right-1; j++)
    {
        if(S[j] < pivot)
        {
            std::swap(S[j], S[i]);
            i = i + 1;
        }
    }
    std::swap(S[i], S[right]);
    return i;
}

void QuickSort(int* S, int left, int right){
    if (left <= right)
    {
    int pvindex = Split(S, left, right);
    QuickSort(S, left, pvindex - 1);
    QuickSort(S, pvindex + 1, right);
    }
}