#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int a[maxn+5];
int main(){
	int n,k,q,x;scanf("%d%d%d",&n,&k,&q);
	k=q-k+1;
	for(int i=0;i<q;i++)scanf("%d",&x),a[x]++;
	for(int i=1;i<=n;i++)if(a[i]>=k)puts("Yes");else puts("No");
	return 0;
}
