#include<bits/stdc++.h>
using namespace std;
#define maxn 105
struct Node{
	int x,id;
	bool operator < (const Node &b)const{
		return x>b.x;
	}
}b[maxn];
int a[maxn][maxn],ans1[maxn];
int main(){
	int n,m,ans=maxn,w,sum;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)for(int j=1;j<=n;j++)scanf("%d",a[i]+j);
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++)b[j]={a[j][i]-a[j][n],j};
		sort(b,b+m);
		for(w=0,sum=0;w<m;w++){
			sum+=b[w].x;
			if(sum<0)break;
		}
		w=m-w;
		if(w<ans){
			ans=w;
			for(int i=1;i<=ans;i++)ans1[i]=b[m-i].id;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)printf("%d ",ans1[i]+1);
	return 0;
}
