#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];char s[10];
int main(){
	int n,m,x,ans1=0,ans2=0;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%s",&x,s);
		if(a[x]==-1)continue;
		if(s[0]=='A')ans1++,ans2+=a[x],a[x]=-1;
		else a[x]++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
