#include<bits/stdc++.h>
using namespace std;
#define maxn 205
char s[maxn],t[maxn],ans[maxn*2];
int f[maxn][maxn],pre[maxn][maxn];
int main(){
	scanf("%s%s",s,t);
	int n=strlen(s),m=strlen(t);
	memset(f,0x1f,sizeof(f));
	f[0][0]=-1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(s[i]&&t[j]&&s[i]==t[j]){
				if(f[i][j]+1<f[i+1][j+1])f[i+1][j+1]=f[i][j]+1,pre[i+1][j+1]=i*1000+j;
			}
			if(s[i]&&f[i][j]+1<f[i+1][j])f[i+1][j]=f[i][j]+1,pre[i+1][j]=i*1000+j;
			if(t[j]&&f[i][j]+1<f[i][j+1])f[i][j+1]=f[i][j]+1,pre[i][j+1]=i*1000+j;
		}
	}
	int i=n,j=m,x,y,mi=maxn*3,sum=0;
	while(i||j){
		x=pre[i][j]/1000,y=pre[i][j]%1000;
		if(x==i-1)ans[f[i][j]]=s[i-1];
		else ans[f[i][j]]=t[j-1];
		i=x,j=y;
	}
	for(i=0;i<=f[n][m];i++){
		if(ans[i]=='(')sum++;
		else sum--;
		mi=min(mi,sum);
	}
	for(int i=0;i<mi;i++)putchar('(');printf("%s",ans);
	for(int i=0;i<sum+mi;i++)putchar(')');
	return 0;
}
