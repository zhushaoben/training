#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
	int A,B,m,ans,mi=1e9,x,y,c;scanf("%d%d%d",&A,&B,&m);
	for(int i=1;i<=A;i++)scanf("%d",a+i),mi=min(mi,a[i]);ans=mi,mi=1e9;
	for(int i=1;i<=B;i++)scanf("%d",b+i),mi=min(mi,b[i]);ans+=mi;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&c);
		ans=min(ans,a[x]+b[y]-c);
	}
	printf("%d",ans);
	return 0;
}
