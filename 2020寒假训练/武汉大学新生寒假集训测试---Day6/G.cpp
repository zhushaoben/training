#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,x,y;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&x,&y),ans=max(ans,x+y);
	printf("%d",ans);
	return 0;
}
