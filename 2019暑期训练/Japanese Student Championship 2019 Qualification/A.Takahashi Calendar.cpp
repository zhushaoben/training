#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,d,ans=0;scanf("%d%d",&m,&d);
	for(int i=4;i<=m;i++){
		for(int j=22;j<=d;j++){
			if((j%10)>=2&&((j%10)*(j/10))==i)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
