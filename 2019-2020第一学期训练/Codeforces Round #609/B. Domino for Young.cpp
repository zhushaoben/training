#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 300005
LL f[3][maxn],a[maxn];
int work(){
	int n,x;LL ans=0,a=0,b=0;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a+=x/2,b+=x/2;
		if(x&1){
			if(i&1)a++;
			else b++;
		}
	}
	printf("%lld",min(a,b));
	return 0;
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
