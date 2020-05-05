#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t,c;int a,b;
	cin>>s>>t>>a>>b>>c;
	if(s==c)a--;
	else b--;
	printf("%d %d",a,b);
	return 0;
} 
