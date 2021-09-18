#include <bits/stdc++.h>
#include <climits>
using namespace std;

int check()
{
	#ifndef ONLINE_JUDE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w",stdout);
	#endif
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap
{
public:
    int *arr;
    //int capacity;
    int heap_size;

//public:
    //counstructor
    MinHeap(int *a, int size)
    {
        heap_size = size;
        //capacity = size;
        arr = a;
        buildHeap();
    }

    int getParentIndex(int i) { return (i-1)/2; }
    int getLeftChildIndex(int i){ return (2*i+1); }
    int getRightChildIndex(int i){ return (2*i+2); }

    int getMin() { return arr[0]; }
    
    void MinHeapify(int i)
    {
        int left = getLeftChildIndex(i);
        int right = getRightChildIndex(i);
        int smallest = i;

        if(left < heap_size && arr[left] < arr[i]) { smallest = left; }

        if(right < heap_size && arr[right] < arr[smallest]) { smallest = right; }

        if(smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            MinHeapify(smallest);
        }

    }

    
    int extractMin()
    {
        if(heap_size <=0 )
            return INT_MAX;

        if(heap_size == 1) { heap_size--; return arr[0]; }

        int root = arr[0];
        arr[0] = arr[heap_size-1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    void buildHeap()
    {
        int i = (heap_size-1)/2; 
        while(i>=0)
        {
            MinHeapify(i);
            i--;
        }
    }
};


int findKthSmallestElement(int *array, int size, int k)
{
    MinHeap heap(array, size);
    for(int i=0; i<k-1; i++)
    {
        heap.extractMin();
    }
    return heap.getMin();
}

int main()
{   
    check();
        
    int arr[] = {12, 3, 5, 7, 19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    cout<<"k'th smallest element is: "<<findKthSmallestElement(arr,size,k);
    return 0;
}