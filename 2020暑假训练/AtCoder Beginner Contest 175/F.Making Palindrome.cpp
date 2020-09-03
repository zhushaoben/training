#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=55;
const LL inf=1e18;
char s[N][22];
int c[N],l[N],n;
bool vis[N][22][2];
LL f[N][22][2],ans=inf;
LL dp(int x,int y,int k){
	if(y==l[x])return 0;
	LL &ans=f[x][y][k];
	if(vis[x][y][k])return ans;
	vis[x][y][k]=1,ans=inf;bool fl=1;
	if(k)for(int L=0,R=l[x]-y-1;L<R;L++,R--){if(s[x][L]!=s[x][R]){fl=0;break;}}
	else for(int L=y,R=l[x]-1;L<R;L++,R--)if(s[x][L]!=s[x][R]){fl=0;break;}
	if(fl)return ans=0;
	for(int i=0;i<n;i++){
		fl=1;
		if(k)for(int R=l[x]-y-1,L=0;L<l[i]&&R>=0;R--,L++){if(s[x][R]!=s[i][L]){fl=0;break;}}
		else for(int R=l[i]-1,L=y;L<l[x]&&R>=0;R--,L++)if(s[x][L]!=s[i][R]){fl=0;break;}
		if(fl){
			if(y+l[i]<=l[x])ans=min(ans,c[i]+dp(x,y+l[i],k));
			else ans=min(ans,c[i]+dp(i,l[x]-y,k^1));
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s%d",s[i],c+i),l[i]=strlen(s[i]);
	for(int i=0;i<n;i++)ans=min(ans,c[i]+dp(i,0,0));
	printf("%lld",ans==inf?-1:ans);
	return 0;
}
