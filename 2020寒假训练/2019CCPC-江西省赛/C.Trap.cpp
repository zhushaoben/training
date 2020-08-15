#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,S=1e4;
typedef long long LL;
int n,a[N],num[N*5];
vector<int>v[N*5];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void work(){
	for(int i=1;i<=S;i++)v[i].clear(),num[i]=0;
	for(int i=0;i<n;i++)scanf("%d",a+i),num[a[i]]++;
	sort(a,a+n);n=unique(a,a+n)-a;
	for(int i=0;i<n;i++){
		if(num[a[i]]<2)continue;
		for(int j=1;j<=S;j++)
			if(gcd(j,a[i])==1)v[j].push_back(a[i]);
	}
	LL ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int w=(a[j]-a[i])/2+1,d=gcd(a[j],a[i]),
			x=lower_bound(v[d].begin(),v[d].end(),w)-v[d].begin();
			ans+=v[d].size()-x;
			if(d==1){
				if(num[a[i]]==2&&a[i]>=w)ans--;
				if(num[a[j]]==2&&a[j]>=w)ans--;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
