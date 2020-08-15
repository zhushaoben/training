#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long f[N+1];
int main(){
	freopen("a1.out","r",stdin);
	freopen("a4.out","w",stdout);
	for(int i=1;i<=N;i++)scanf("%lld,",f+i);
	for(int i=N;i>3;i--)f[i]-=f[i-3];
	for(int i=1;i<=N;i++)printf("%lld,",f[i]);
	return 0;
}
