#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id,x;
	bool operator < (const Node &b)const{
		return x<b.x;
	}
}w[55];
int ans[55][55];
void work(){
	int n,m,a,b;scanf("%d%d%d%d",&n,&m,&a,&b);
	if(n*a!=m*b){puts("NO");return;}
	puts("YES");
	memset(ans,0,sizeof(ans));
	for(int i=0;i<m;i++)w[i].id=i,w[i].x=0;
	for(int i=0;i<n;i++){
		sort(w,w+m);
		for(int j=0;j<a;j++)ans[i][w[j].id]=1,w[j].x++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)printf("%d",ans[i][j]);
		puts("");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work(); 
	return 0;
}
