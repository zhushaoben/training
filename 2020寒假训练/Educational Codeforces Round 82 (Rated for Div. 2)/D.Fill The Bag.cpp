#include<bits/stdc++.h>
using namespace std;
#define LL long long
int num[70];
void work(){
	memset(num,0,sizeof(num));
	LL n,sum=0,sum1=0,ans=0;int m,x;scanf("%lld%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&x);int w=-1;sum+=x;
		while(x)x>>=1,w++;num[w]++;
	}
	if(sum<n){puts("-1");return;}
	sum=0;
	for(int i=0;i<62;i++){
		sum+=num[i]*(1ll<<i);
		if(n&(1<<i)){
			sum1+=(1ll<<i);
			if(sum>=sum1)continue;
			for(int j=i+1;j<62;j++){
				if(num[j]){
					num[j]--;num[i]+=2;sum+=(2ll<<i);ans++;
					for(int k=i+1;k<j;k++)num[k]++,ans++;
					break;
				}
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
