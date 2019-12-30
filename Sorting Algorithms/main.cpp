//
//  main.cpp
//  Bubble Sort
//
//  Created by Haider Ali on 11/5/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
using namespace std;
# define SIZE 15


class Sorting_Alogos{
    

    void swap(int* v1, int* v2) {
        int hold;
        hold = *v1;
        *v1 = *v2;
        *v2 = hold;
    }

    void merge(int A[], int arr[], int low, int mid, int high){
        int j = low;
        int k = low;
        int l = mid+1;
        
        while (j<=mid && l<=high) {
            if (A[j] < A[l]) {
                arr[k] = A[j];
                k++;
                j++;
            }
            else{
                arr[k] = A[l];
                k++;
                l++;
            }
        }
        while (j<=mid) {
            arr[k] = A[j];
            k++;
            j++;
        }
        while (l<=high){
            arr[k] = A[l];
            k++;
            l++;
        }
        for (int i=low; i<k; i++) {
            A[i] = arr[i];
        }
        
    }

    int split(int A[], int first, int last) {
        int saveF = first;
        static int c = 0;
        c++;
        int split_value = A[first];
        bool onCorrectSide;
        first++;
        
        do {
            onCorrectSide = true;
            while (onCorrectSide) {
                if (A[first] > split_value) {
                    onCorrectSide = false;
                }
                else {
                    first++;
                    onCorrectSide = (first<=last);
                }
            }
            onCorrectSide = (first<=last);
            
            while (onCorrectSide) {
                if (A[last] <= split_value) {
                    onCorrectSide = false;
                }
                else {
                    last--;
                    onCorrectSide = (first<=last);
                }
            }
            if (first<last) {
                swap(A+first,A+last);
                first++;
                last--;
            }
           
        } while (first<=last);
         swap(A+saveF, A+last);
         cout<<c<<endl;
         return last;
    }

    int partition(int A[], int low, int high) {
        int pivot = A[low];
        int left = low+1;
        int right = high;
       
        
        while (right>=left) {
            while (A[left]<=pivot) {
                if (left>right) {
                    break;
                }
                left++;
            }
            while (A[right]>=pivot) {
                if (left>right) {
                    break;
                }
                right--;
            }
            if (left<right) {
                swap(A+left, A+right);
            }
        }
        swap((A+right), A+low);
        return right;
    }

    int partition_1(int A[], int low, int high){
        int pivot = A[high];
        int i = low;
    //    1 2 3 4 5
        for (int j=low; j<high; j++) {
        
            if (A[j] < pivot) {
                swap(&A[i], &A[j]);
                i++;
            }
        }
        swap(&A[i], &A[high]);
        return i;
    }

public:
    void bubbleSort(int *array, int length) {
        int c=0;
        for(int i=0; i<length-1; i++) {
            for (int j=0; j<length-i; j++) {
                
                if(array[j] > array[j+1]) {
                    swap(array+j, array+j+1);
                }
                c++;
            }
        }
        cout<<"buuble sort: "<<c<<endl;
    }

    void shortBubbleSort(int *array, int length) {
        bool isSwap = false;
        int c=0;
        for(int i=0; i<length-1; i++) {
            isSwap = false;
            for (int j=0; j<length-i; j++) {
               
                if(array[j] > array[j+1]) {
                    swap(array+j, array+j+1);
                    isSwap = true;
                }
                 c++;
            }
            if (!isSwap) {
                cout<<"smart bubble sort: "<<c<<endl;
                return;
            }
        }
        cout<<"smart bubble sort: "<<c<<endl;
    }

    void selectionSort(int *array, int length) {
        int min,c=0;
        for (int curr = 0; curr<length-1; curr++) {
            min = curr;
            for (int i=curr+1; i<length; i++) {
                
                if (array[i]<array[min]) {
                    min = i;
                }
                c++;
            }
            swap(array+curr, array+min);
        }
         cout<<"selection sort steps: "<<c<<endl;
    }

    void insertionSort(int arr[], int len) {
        int key;
        int j;
        
        for (int i=1; i<len; i++) {
            key = arr[i];
            j = i-1;
            
            while (j>=0 && arr[j]>key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    
    void quickSort(int A[], int low, int high){
           
           if (low<high) {
       //        int pivot = split(A, low, high);
       //        int pivot = partition_1(A, low, high);
               int pivot = partition(A, low, high);
               quickSort(A, low, pivot-1);
               quickSort(A, pivot+1, high);
           }
       }
       
       void mergeSort(int A[], int low, int high){
           int mid;
           int arr[high+1];
           
           if(low < high) {
               mid = (low+high)/2;
               mergeSort(A, low, mid);
               mergeSort(A, mid+1, high);
               merge(A,arr,low,mid,high);
           }
           else{
               return;
           }
       }

};

int main(){
    
    int a[]={5,4,3,2,1};
    Sorting_Alogos *sort = new Sorting_Alogos();
    sort->mergeSort(a, 0, 1);
    for (int i=0; i<5; i++) {
        cout<<a[0]<<" ";
    }
}
