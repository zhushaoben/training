#include<bits/stdc++.h>
using namespace std;
int work(){
	int n,k;scanf("%d%d",&n,&k);
	if((n^k)&1)return puts("NO"),0;
	long long sum=1ll*(1+2*k-1)*k/2;
	if(n<sum)puts("NO");
	else puts("YES");
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
