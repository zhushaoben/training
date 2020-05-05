#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],d[N],ma[N];
vector<int>v[N];
void dfs(int x){
	ma[x]=x;
	for(auto i:v[x]){
		d[i]=d[x]+1;dfs(i);
		if(d[ma[x]]<=d[ma[i]])ma[x]=ma[i];
	}
	b[ma[x]]++;
}
int main(){
	int n,k,x;scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++){
		scanf("%d",&x);
		v[x].push_back(i);
	}
	dfs(0);b[ma[0]]--;
	sort(a,a+k),sort(b,b+n);
	long long ans=0;
	for(int i=k-1;~i;i--)ans+=1ll*a[i]*b[n-k+i];
	printf("%lld",ans);
	return 0;
}
