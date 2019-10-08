#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,x;scanf("%d%d",&k,&x);
	int l=max(x-k+1,-1000000),r=min(1000000,x+k-1);
	for(int i=l;i<=r;i++)printf("%d ",i);
	return 0;
} 
