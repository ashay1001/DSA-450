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
	int arr[] = {3,-4,52,3,-2,3,4,4,10};
	int length = sizeof(arr)/sizeof(arr[0]);
	int max, min,i;

	if(length%2 == 0)
	{
		if(arr[0]>arr[1])
		{
			max = arr[0];
			min = arr[1];
		}
		else
		{
			max = arr[1];
			min = arr[0];
		}
		i = 2;
	}
	else{
		max = arr[0];
		min = arr[0];
		i = 1;
	}

	while(i<length-1)
	{
		if(arr[i]>arr[i+1])
		{
			if(arr[i]>max)
			{
				max = arr[i];
			}
			if(arr[i+1]<min)
			{
				min = arr[i+1];
			}
		}
		else
		{
			if(arr[i+1]>max)
				max = arr[i+1];

			if(arr[i]<min)
				min = arr[i];
		}
		i += 2;
	}
	cout<<"Max and Min from the given  array are: "<<endl;
	cout<<max<<" , "<<min;
	return 0;
}