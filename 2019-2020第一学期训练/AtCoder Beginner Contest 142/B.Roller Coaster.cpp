#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,ans=0,x;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&x),ans+=x>=k;
	printf("%d",ans);
	return 0;
}
