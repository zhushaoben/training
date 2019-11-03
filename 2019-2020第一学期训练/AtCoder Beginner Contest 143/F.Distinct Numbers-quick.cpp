#include<bits/stdc++.h>
using namespace std;
#define maxn 300000
#define LL long long
int a[maxn+5],ans[maxn+5];LL b[maxn+5];
int main(){
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),a[x]++,b[a[x]]++;
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	int now=0;
	for(int i=n;i;i--){
		while(b[now+1]>=1ll*(now+1)*i)now++;
		ans[i]=now;
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}
