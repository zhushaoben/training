#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 1000005
int f[maxn][20],n,q;
inline int query(int l,int r){
	int k=log(r-l+1)/log(2.0);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
inline void ST(){
	int m=log(n)/log(2.0);
	for(int i=0;i<m;i++){
		for(int j=1;j+(1<<(i+1))-1<=n;j++){
			f[j][i+1]=min(f[j][i],f[j+(1<<i)][i]);
		}
	}
}
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",f[i]);
	ST();
	scanf("%d",&q);
	for(int i=0;i<q;i++)scanf("%d%d",&l,&r),printf("%d\n",query(l,r));
	return 0;
}
