#include<bits/stdc++.h>
using namespace std;
char s[200];
void work(){
	int n,a,b,c,ans=0;scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=1;i<=n;i++){
		if(i%a&&i%b&&i%c)ans++;
	}
	printf("%d",ans);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
