#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define maxn 5005
LL A,B,C,P,D,ans,d[2][maxn],tmp;
bool vis[maxn][maxn];
int main(){
	int n;scanf("%d%lld%lld%lld%lld%lld",&n,&A,&B,&C,&P,&D);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			tmp=(A*(i+j)*(i+j)+B*(j-i)*(j-i)+C)%P;
			if(tmp>D)d[1][i]++,d[1][j]++,vis[i][j]=1;
			else d[0][i]++,d[0][j]++;
        }
    }
    for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			ans+=d[!vis[i][j]][i]+d[!vis[i][j]][j];
        }
    }
    printf("%lld",1ll*n*(n-1)*(n-2)/6-ans/4);
	return 0;
}
