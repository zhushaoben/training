#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,k,x,ans=0;scanf("%d%d%d%d",&a,&b,&c,&k);
	x=min(a,k),k-=x,ans+=x;
	x=min(b,k),k-=x;
	ans-=k;
	printf("%d",ans);
	return 0;
}
