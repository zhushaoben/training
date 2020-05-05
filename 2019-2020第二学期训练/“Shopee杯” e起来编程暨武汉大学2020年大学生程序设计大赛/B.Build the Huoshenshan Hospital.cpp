#include<bits/stdc++.h>
using namespace std;
const int N=55;
char s[N][N][N];
int a[N][N][N],b[N][N][N],c[N][N][N],d[N][N][N],e[N][N][N],f[N][N][N];
void work1(char x,int i,int j,int k){
	if(x=='.')return;
	for(int u=0;u<=1;u++)for(int v=0;v<=1;v++){
		a[i][j+u][k+v]=max(a[i][j+u][k+v],1);
		b[i+u][j][k+v]=max(b[i+u][j][k+v],1);
		c[i+u][j+v][k]=max(c[i+u][j+v][k],1);
	}
	if(x=='D'){d[i][j][k]=max(2,d[i][j][k]),d[i+1][j][k]=max(2,d[i+1][j][k]);return;}
	if(x=='B'){
		d[i][j][k]=max(1,d[i][j][k]),d[i+1][j][k]=max(1,d[i+1][j][k]);
		e[i][j][k]=max(1,e[i][j][k]),e[i][j+1][k]=max(1,e[i][j+1][k]);
		f[i][j][k]=max(1,f[i][j][k]),f[i][j][k+1]=max(1,f[i][j][k+1]);
	}
	if(x=='C'){
		d[i][j][k]=max(2,d[i][j][k]),d[i+1][j][k]=max(2,d[i+1][j][k]);
		e[i][j][k]=max(2,e[i][j][k]),e[i][j+1][k]=max(2,e[i][j+1][k]);
		f[i][j][k]=max(2,f[i][j][k]),f[i][j][k+1]=max(2,f[i][j][k+1]);
	}
}
void work(){
	int r,C,h;scanf("%d%d%d",&r,&C,&h);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=r;j++)scanf("%s",s[i][j]+1);
	}
	int ans=0;
	for(int i=1;i<=h+1;i++){
		for(int j=1;j<=r+1;j++){
			for(int k=1;k<=C+1;k++){
				a[i][j][k]=b[i][j][k]=c[i][j][k]=d[i][j][k]=e[i][j][k]=f[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=r;j++){
			for(int k=1;k<=C;k++){
				work1(s[i][j][k],i,j,k);
			}
		}
	}
	for(int i=1;i<=h+1;i++){
		for(int j=1;j<=r+1;j++){
			for(int k=1;k<=C+1;k++){
				ans+=a[i][j][k]+b[i][j][k]+c[i][j][k]+d[i][j][k]+e[i][j][k]+f[i][j][k];
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T=1;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
