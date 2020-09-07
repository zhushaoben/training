#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,x;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		ans+=(i%2&&x%2);
	}
	printf("%d",ans);
	return 0;
}
