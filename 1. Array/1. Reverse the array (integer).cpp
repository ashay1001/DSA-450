#include <bits/stdc++.h>
using namespace std;

int check()
{
	#ifndef ONLINE_JUDE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w",stdout);
	#endif
}

int main()
{	
	check();
	int arr[] = {3,4,52,3,2,3,4,4,10};
	int length = sizeof(arr)/sizeof(arr[0]);
	int start=0, end=length -1, temp;
	cout<<"Initial Array: "<<endl;
	for(int i=0; i<length; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	while(start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}

	cout<<"Reverseed Array: "<<endl;
	for(int i=0; i<length; i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}