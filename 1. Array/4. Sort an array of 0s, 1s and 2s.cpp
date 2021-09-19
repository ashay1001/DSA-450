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

void sortArray(int arr[], int size)
{
    int low = 0, mid = 0, high = size-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else        //arr[mid] is equal to 2
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

void print(int a[], int s)
{
    for(int i=0; i<s; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{   
    check();
        
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Befor sorting: \n";
    print(arr,size);
    sortArray(arr, size);
    cout<<"After sorting: \n";
    print(arr,size);
    return 0;
}