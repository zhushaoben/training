#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,mi,x,ans=0;scanf("%d",&n),mi=n;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(mi>=x)mi=x,ans++;
	}
	printf("%d",ans);
	return 0;
}
