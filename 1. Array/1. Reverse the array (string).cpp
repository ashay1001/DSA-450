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
	string s,revString = "";
	cin>>s;
	
	for(int i=s.length()-1; i>=0; i--)
	{
		revString += s[i];
	}

	cout<<revString<<endl;
	return 0;
}