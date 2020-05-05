#include<bits/stdc++.h>
using namespace std;
int num[50];
int main(){
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),num[x+20]++;
	long long ans=1ll*num[20]*(num[20]-1)/2;
	for(int i=0;i<20;i++)ans+=1ll*num[i]*num[40-i]; 
	printf("%lld\n",ans);
	return 0;
} 
