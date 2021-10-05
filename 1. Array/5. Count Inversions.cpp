#include<bits/stdc++.h>
using namespace std;


int merge(int *arr, int start, int mid, int end)
{
    int temp[end-start+1];
    int i = start, j = mid+1, k = 0, inversions = 0;

    while(i<=mid && j<=end)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }
    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=end)
    {
        temp[k++] = arr[j++];
    }
    for(i=0; i<(end-start+1); i++)
    {
        arr[start+i] = temp[i];
    }
    return inversions; 
}

int mergeSort(int *arr, int start, int end)
{
    int inversion = 0;
    if(start < end)
    {
        int mid = (start + end)/2;
        inversion += mergeSort(arr, start, mid);
        inversion += mergeSort(arr, mid+1, end);
        inversion += merge(arr, start, mid, end);
    }
    return inversion;
}
int main()
{
    int arr[] = {468,335,1,170,225,479,359,463,465,206,146,282,328,462,492,496,443,328,437,392,105,403,154,293,383,422,217,219,396,448,227,272,39,370,413,168,300,36,395,204,312,323};
    int n = sizeof(arr)/sizeof(arr[0]);
    int inversions = mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<inversions;
    return 0;
}