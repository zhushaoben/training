#include<bits/stdc++.h>
using namespace std;
const int N=505;
typedef long long LL;
int f[N],c[N],a[N],b[N];
//f[i][j] indicate if the first i basket can used k(k%K=j) berries
int main(){
	int n,k,l,r;LL s1=0,s2=0,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i),s1+=a[i],s2+=b[i];
	f[0]=1;
	for(int i=0;i<n;i++){
		if(a[i]+b[i]<k)continue;
		memset(c,0,sizeof(int)*k);
		l=max(1,k-b[i]);r=min(a[i],k-1);
		if(l<=r)for(int j=0;j<k;j++){
			if(!f[j])continue;
			int l1=(l+j)%k,r1=(r+j)%k;
			c[l1]++,c[r1+1]--;
			if(l1>r1)c[0]++;
		}
		for(int j=1;j<k;j++)f[j]|=(c[j]+=c[j-1]);
	}
	ans=s1/k+s2/k;
	for(int i=1;i<k;i++)
		ans=max(ans,(s1-i)/k+(s2-k+i)/k+(bool)f[i]);
	printf("%lld",ans);
	return 0;
}
