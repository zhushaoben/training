#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int num[N];
int main(){
	int n,q,x,b,c;scanf("%d",&n);long long sum=0;
	for(int i=0;i<n;i++)scanf("%d",&x),num[x]++,sum+=x;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&b,&c);
		sum+=1ll*(c-b)*num[b];
		num[c]+=num[b];num[b]=0;
		printf("%lld\n",sum);
	}
	return 0;
} 
