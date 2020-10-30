#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N][N],s1[3][3];
void work(){
	int n,m,ans=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=0;i<3;i++)scanf("%s",s1[i]);
	for(int i=0;i<=n+1;i++)s[i][0]=s[i][m+1]='*';
	for(int i=0;i<=m+1;i++)s[0][i]=s[n+1][i]='*';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			bool fl=1;
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
					if(s1[k][l]!=s[i+k-1][j+l-1]&&(s1[k][l]!='P'||s[i+k-1][j+l-1]=='#'))fl=0;
			if(fl)ans++;
		}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
