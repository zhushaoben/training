#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,n,sum=0,x;scanf("%d%d",&h,&n);
	for(int i=0;i<n;i++)scanf("%d",&x),sum+=x;
	if(sum>=h)puts("Yes");
	else puts("No");
	return 0;
} 
