#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
int h[maxn],num[maxn],n,k,mi,ans,remain;
int main(){
	scanf("%d%d",&n,&k);mi=1e9;
	for(int i=0;i<n;i++)scanf("%d",h+i),mi=min(h[i],mi),num[h[i]]++;
	for(int i=2e5;i;i--)num[i]+=num[i+1];
	for(int i=2e5;i>mi;i--){
		if(remain>=num[i])remain-=num[i];
		else remain=k-num[i],ans++;
	}
	printf("%d",ans);
	return 0;
}
