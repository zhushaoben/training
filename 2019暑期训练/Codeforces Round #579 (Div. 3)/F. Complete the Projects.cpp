#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define maxm 
struct Node{
	int a,b;
	bool operator <(const Node &b)const{
		if(b>=0)return a<b.a;
		return 
	}
}a[maxn],b[maxn];
int s1,s2;
int main(){
	int n,m,x,y,ans=0,;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if(y>=0)a[s1++]={x,y};
		else b[s2++]={x,y};
	}
	sort(a,a+s1);
	for(int i=0;i<s1;i++){
		if(m>=a[i].a)ans++,m+=a[i].b;
	}
	if(f[s2]<=m)ans+=s2;
//	printf("%d\n",ans);
	if(ans==n)puts("YES");
	else puts("NO");
	return 0;
}
