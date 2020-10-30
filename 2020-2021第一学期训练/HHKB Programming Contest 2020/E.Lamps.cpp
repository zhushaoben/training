#include<bits/stdc++.h>
using namespace std;
const int N=2005,mo=1e9+7;
char s[N][N];
int u[N][N],d[N][N],l[N][N],r[N][N],pow2[N*N];
int main(){
	int h,w,si=0,ans=0;scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)scanf("%s",s[i]+1);
	pow2[0]=1;for(int i=1;i<=h*w;i++)pow2[i]=pow2[i-1]*2%mo;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(s[i][j]=='#')continue;
			u[i][j]=u[i-1][j]+1,l[i][j]=l[i][j-1]+1;
			si++;
		}
	}
	for(int i=h;i;i--){
		for(int j=w;j;j--){
			if(s[i][j]=='#')continue;
			d[i][j]=d[i+1][j]+1,r[i][j]=r[i][j+1]+1;
			int x=u[i][j]+d[i][j]+l[i][j]+r[i][j]-3;
			(ans+=1ll*pow2[si-x]*(pow2[x]-1)%mo)%=mo;
		}
	}
	printf("%d",(ans+mo)%mo);
	return 0;
}
