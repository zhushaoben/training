#include<bits/stdc++.h>
using namespace std;
int l[11],r[11],a[11];
void work(){
	int n,m,ans=1e9;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)a[i]=i,scanf("%d%d",l+i,r+i);
	do{
		int w=0;
		for(int i=2;i<=m;i++)w+=abs(l[a[i]]-l[a[i-1]])+abs(r[a[i]]-r[a[i-1]]);
		ans=min(ans,w);
	}while(next_permutation(a+1,a+m+1));
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
