#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,M=2e6+5;
struct Node{
	int x,y;
	bool operator <(const Node &b)const{return y>b.y;}
}a[N];
int x[N],y[N],mi[M];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<m;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a,a+m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[j].y<y[i])break;
			mi[a[j].y-y[i]]=max(mi[a[j].y-y[i]],a[j].x-x[i]+1);
		}
	}
	int ans=1e9;
	for(int i=1e6+5;~i;i--)mi[i]=max(mi[i],mi[i+1]),ans=min(ans,mi[i]+i);
	printf("%d",ans);
	return 0;
}
