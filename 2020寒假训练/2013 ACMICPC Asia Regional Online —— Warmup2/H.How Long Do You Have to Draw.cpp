#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c[N],d[N];
void work(){
	int a,b,n,m;scanf("%d%d%d%d",&a,&b,&n,&m);
	a=(a-b)*(a-b);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=m;i++)scanf("%d",d+i);
	int l=1,l1=1;double ans=sqrt(a+1ll*(d[l1]-c[l])*(d[l1]-c[l]));
	while(l<n||l1<m){
		if(l==n)l1++;
		else if(l1==m||abs(d[l1]-c[l+1])<abs(d[l1+1]-c[l]))l++;
		else l1++; 
		ans+=sqrt(a+1ll*(d[l1]-c[l])*(d[l1]-c[l]));
	}
	printf("%.2lf\n",ans);
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
