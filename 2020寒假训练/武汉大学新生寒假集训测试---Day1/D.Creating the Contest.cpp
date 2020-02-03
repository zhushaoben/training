#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,now=0,x,pre=1e9;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x>pre*2)ans=max(ans,now),now=1;
		else now++;
		pre=x;
	}
	printf("%d",max(ans,now));
	return 0;
}
