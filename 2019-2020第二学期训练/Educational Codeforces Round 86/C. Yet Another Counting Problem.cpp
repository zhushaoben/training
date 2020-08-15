#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int f[40005],s;
LL calc(LL x){return x/s*f[s]+f[x%s];}
void work(){
	int a,b,q;scanf("%d%d%d",&a,&b,&q),s=a*b;
	for(int i=1;i<=s;i++)f[i]=f[i-1]+((i%a)%b!=(i%b)%a);
	LL l,r;
	for(int i=0;i<q;i++){
		scanf("%lld%lld",&l,&r);
		printf("%lld ",calc(r)-calc(l-1));
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
