#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int x[N],f[N];
void work(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",x+i);
	for(int i=0;i<n;i++)scanf("%*d");
	sort(x,x+n);
	int l=0,ans=0,ma=0;
	for(int i=0;i<n;i++){
		while(x[i]-x[l]>k)ma=max(ma,f[l++]);
		f[i]=i-l+1;ans=max(f[i]+ma,ans);
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
