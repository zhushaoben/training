#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,m,x,y,ans=1e9;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		ans=min(ans,((m-1)/x+1)*y);
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
