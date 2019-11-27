#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define LL long long
int a[maxn+5],n;LL ans,sum;
void work(LL x){
	LL w=0,remain=x;int mid=-1;
	for(int i=0;i<n;i++){
		int now=a[i];
		if(now>=remain&&remain!=x)now-=remain,w+=mid!=-1?remain*(i-mid):0,remain=x,mid=-1;
		now%=x;remain-=now;
		if(mid!=-1)w+=1ll*now*(i-mid);
		else if(remain<=x/2)mid=i;
		else w+=x-remain;
	}
	ans=min(ans,w);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),sum+=a[i];
	ans=sum*n;
	if(sum<=1)return puts("-1"),0;
	for(LL i=2;i*i<=sum;i++)
		if(sum%i==0){work(i);while(sum%i==0)sum/=i;}
	if(sum>1)work(sum);
	printf("%lld\n",ans);
	return 0;
} 
