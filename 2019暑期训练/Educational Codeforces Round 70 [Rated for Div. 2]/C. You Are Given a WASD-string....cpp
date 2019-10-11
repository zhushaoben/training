#include<bits/stdc++.h>
using namespace std;
#define maxn 200015
char s[maxn];
int X[maxn],Y[maxn],f[2][4][maxn];
void work(){
	scanf("%s",s+1);int n=strlen(s+1);
	int x=0,y=0,ax,mix,may,miy;
	ax=mix=may=miy=0;
	for(int i=1;s[i];i++){
		if(s[i]=='D'){y++;may=max(may,y);}
		if(s[i]=='W'){x--;mix=min(mix,x);}
		if(s[i]=='A'){y--;miy=min(miy,y);}
		if(s[i]=='S'){x++;ax=max(ax,x);}
		X[i]=x,Y[i]=y;
	}
	bool fl1=1,fl2=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<4;j++)f[0][j][i]=f[0][j][i-1];
		if(X[i]==mix)f[0][0][i]=1;
		if(X[i]==ax)f[0][1][i]=1;
		if(Y[i]==miy)f[0][2][i]=1;
		if(Y[i]==may)f[0][3][i]=1;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<4;j++)f[1][j][i]=f[1][j][i+1];
		if(X[i]==mix){f[1][0][i]=1;if(f[0][1][i]&&f[1][1][i])fl1=0;}
		if(X[i]==ax){f[1][1][i]=1;if(f[0][0][i]&&f[1][0][i])fl1=0;}
		if(Y[i]==miy){f[1][2][i]=1;if(f[0][3][i]&&f[1][3][i])fl2=0;}
		if(Y[i]==may){f[1][3][i]=1;if(f[0][2][i]&&f[1][2][i])fl2=0;}
	}
	int w=ax-mix+1,w1=may-miy+1;
	if((w<=w1||w1<=2)&&w>2&&fl1){
		printf("%lld\n",1ll*(w-1)*w1);
	}
	else if(w1>2&&fl2){
		printf("%lld\n",1ll*w*(w1-1));
	}
	else printf("%lld\n",1ll*w*w1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work(); 
	return 0;
} 
