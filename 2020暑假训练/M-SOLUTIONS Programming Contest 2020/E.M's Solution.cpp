#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=15;
int x[N],y[N],p[N],mix[1<<N][N],miy[1<<N][N];
LL ans[N+5];
int main(){
	int n,s;scanf("%d",&n),s=(1<<n);
	for(int i=0;i<n;i++)scanf("%d%d%d",x+i,y+i,p+i);
	for(int i=0;i<s;i++){
		for(int j=0;j<n;j++){
			mix[i][j]=abs(x[j]),miy[i][j]=abs(y[j]);
			for(int k=0;k<n;k++)if(i&(1<<k))
				mix[i][j]=min(mix[i][j],abs(x[j]-x[k])),miy[i][j]=min(miy[i][j],abs(y[j]-y[k]));
		}
	}
	LL w,w1;memset(ans,0x1f,sizeof(ans));
	for(int i=0,j=0;i<s;i++,j=i){
		do{
			w1=w=0;
			for(int k=0;k<n;k++)if(i&(1<<k))w++;
				else w1+=1ll*min(mix[j][k],miy[i^j][k])*p[k];
			ans[w]=min(ans[w],w1);
			j=(j-1)&i;
		}while(i!=j);
	}
	for(int i=0;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}
/*
The time complexity of this solution is O(n*3^n)
the other solution is enumerate which point calculate according to x while the others according to y
The time complexity of this solution is O(n^3*2^n)
*/

