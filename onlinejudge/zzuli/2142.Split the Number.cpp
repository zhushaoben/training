#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[100]={1,1};
void work(){
	LL n,k,num=0;scanf("%lld%lld",&n,&k);
	if(n<k){puts("No");return;}
	for(int i=86;i;i--)if(n>=f[i])n-=f[i],num++;
	if(num<=k)puts("Yes");
	else puts("No");
}
int main(){
	for(int i=2;i<87;i++)f[i]=f[i-1]+f[i-2];
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
