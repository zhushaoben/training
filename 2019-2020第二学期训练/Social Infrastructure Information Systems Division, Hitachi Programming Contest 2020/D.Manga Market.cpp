/*
firstly,we sort the stores by a/(b+1) and do the following dp:
dpi,j = the minimum time needed to visit j stores among the f irst i stores 
we find for one store if a=0 we can visit it lastly
if a!=0,dpi,j grows exponentially in accordance with j (j must less than logT)
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=2e9;
struct Node{
	int a,b;
	bool operator < (const Node &c){
		return 1ll*a*(c.b+1)>1ll*c.a*(b+1);
	}
}a[N];
int b[N],si1,si2;long long f[35];
int main(){
	int n,t,x,y;scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if(x)a[si1++]={x,y};
		else b[si2++]=y;
	}
	sort(a,a+si1);
	sort(b,b+si2);
	for(int i=1;i<31;i++)f[i]=inf;
	for(int i=0;i<si1;i++){
		for(int j=30;~j;j--){
			if(f[j]==inf)continue;
			f[j+1]=min(f[j+1],(f[j]+1)*(a[i].a+1)+a[i].b);
		}
	}
	int ans=0;
	for(int i=0;i<=30;i++){
		if(f[i]>t)break;
		ans=max(ans,i);
		for(int j=0;j<si2;j++){
			if((f[i]+=b[j]+1)>t)break;
			ans=max(ans,i+j+1);
		}
	}
	printf("%d",ans);
	return 0;
} 
