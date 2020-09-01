#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mo=1e9+7;
int b[N],f[N][N];
void work(){
	int n;scanf("%d",&n);
	for(int i=2;i<=n;i++)scanf("%d",b+i);
	f[1][1]=1;
	for(int i=2;i<=n;i++){
		f[i][i]=f[i][1]=0;
		if(b[i])for(int j=i-1;j;j--)f[i][j]=(f[i][j+1]+f[i-1][j])%mo;
		else for(int j=2;j<=i;j++)f[i][j]=(f[i][j-1]+f[i-1][j-1])%mo;
	}
	int ans=0;
	for(int i=1;i<=n;i++)(ans+=f[n][i])%=mo;
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
