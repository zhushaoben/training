#include<bits/stdc++.h>
using namespace std;
#define LL long long
int work(){
	LL n,m;scanf("%lld",&n);
	if(n%5==1||n%5==4)puts("hyy");
	else puts("wqy");
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
