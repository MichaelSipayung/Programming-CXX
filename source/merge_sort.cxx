#ifndef MERGE_SORT
#define MERGE_SORT
#define TOTAL_DATA 16
#include "merge_sort.hpp"
#include <iostream>
void merge(char A[TOTAL_DATA] ,int lo,int mid,int hi){
    char aux[TOTAL_DATA] ={0};
    for (size_t k = lo; k <= hi; k++)
    {
        aux[k]=A[k];
    }
    int i=lo,j=mid+1;
    for (size_t k = lo; k <=hi; k++)
    {
        if (i>mid) {A[k]= aux[j++];}
        else if(j>hi) {A[k] =aux[i++];}
        else if (aux[j]<=aux[i])
        {
            A[k]=aux[j++];
        }
        else{A[k]=aux[i++];}
    }
}
void sort(char A[TOTAL_DATA],int lo,int hi){
    if (hi<=lo) {return;}
    int mid  = lo + (hi-lo)/2;
    sort(A,lo,mid);
    sort(A,mid+1,hi);
    merge(A,lo,mid,hi);
}
void show_data(char A[TOTAL_DATA]){
    for (size_t i = 0; i < TOTAL_DATA; i++)
    {
        std::cout<<" " << A[i];
    }
    std::cout<<std::endl;
}
#endif