#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
typedef long long LL;
LL f[N][N];
//f[l][r] indicate for the top l+r largest points the maximum total happiness that the number of the points move to left is l
struct Node{
	int a,x;
	bool operator < (const Node &b)const{return a>b.a;} 
}a[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].a),a[i].x=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			int k=i-j-1;
			f[j+1][k]=max(f[j+1][k],f[j][k]+1ll*a[i].a*abs(a[i].x-j-1));
			f[j][k+1]=max(f[j][k+1],f[j][k]+1ll*a[i].a*abs(a[i].x-(n-k)));
		}
	}
	LL ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,f[i][n-i]);
	printf("%lld",ans);
	return 0;
}
