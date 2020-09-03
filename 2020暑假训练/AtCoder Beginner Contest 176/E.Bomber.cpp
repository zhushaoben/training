#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N],b[N];
map<long long,int>mp;
int main(){
	int h,w,m,x,y,ma1=0,ma2=0,si1=0,si2=0;scanf("%d%d%d",&h,&w,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&x,&y),a[x]++,b[y]++,mp[1ll*x*N+y]=1;
	for(int i=1;i<=h;i++)ma1=max(ma1,a[i]);
	for(int i=1;i<=h;i++)if(a[i]==ma1)a[si1++]=i;
	for(int i=1;i<=w;i++)ma2=max(ma2,b[i]);
	for(int i=1;i<=w;i++)if(b[i]==ma2)b[si2++]=i;
	for(int i=0;i<si1;i++)
		for(int j=0;j<si2;j++)
			if(!mp[1ll*a[i]*N+b[j]])return printf("%d",ma1+ma2),0;
	printf("%d",ma1+ma2-1);
	return 0;
}
