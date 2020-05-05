#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
LL s[maxn],k[maxn],b[maxn];
int main(){
	int n,q;scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%lld",s+i);
	for(int i=1;i<n;i++)s[i]+=s[i-1];s[n]=1e18;
	for(int i=0;i<q;i++)scanf("%lld",k+i);
	long long sum=0;
	for(int i=0;i<q;i++){
		sum+=k[i];
		int w=upper_bound(s,s+n,sum)-s;
		printf("%d\n",n-w?n-w:n);
		if(w==n)sum=0;
	}
	return 0;
}
