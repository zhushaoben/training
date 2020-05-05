#include<bits/stdc++.h>
using namespace std;
int ans[2005];
int main(){
	int n,x,y;scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans[min(j-i,abs(x-i)+abs(j-y)+1)]++;
		}
	}
	for(int i=1;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}
