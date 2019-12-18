/*
let f[i][j][k] be the shortest length of sequences that contain the first i characters of s and the first j characters of t
and the difference of '(' and ')' is k
*/ 
#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define inf 0x1f1f1f1f
char s[maxn],t[maxn],ans1[maxn*2];
int f[maxn][maxn][maxn],pre[maxn][maxn][maxn];
int main(){
	scanf("%s%s",s,t);
	int n=strlen(s),m=strlen(t),q=max(n,m);
	memset(f,0x1f,sizeof(f));
	f[0][0][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=q;k++){
				int w=(s[i]=='('),w1=t[j]=='(',w2=s[i]==')',w3=t[j]==')';
				if(f[i+w][j+w1][k+1]>f[i][j][k]+1)f[i+w][j+w1][k+1]=f[i][j][k]+1,pre[i+w][j+w1][k+1]=i*maxn+j+k*maxn*maxn;
				if(k&&f[i+w2][j+w3][k-1]>f[i][j][k]+1)f[i+w2][j+w3][k-1]=f[i][j][k]+1,pre[i+w2][j+w3][k-1]=i*maxn+j+k*maxn*maxn;	
			}
			for(int k=q;~k;k--){
				int w=(s[i]=='('),w1=t[j]=='(',w2=s[i]==')',w3=t[j]==')';
				if(f[i+w][j+w1][k+1]>f[i][j][k]+1)f[i+w][j+w1][k+1]=f[i][j][k]+1,pre[i+w][j+w1][k+1]=i*maxn+j+k*maxn*maxn;
				if(k&&f[i+w2][j+w3][k-1]>f[i][j][k]+1)f[i+w2][j+w3][k-1]=f[i][j][k]+1,pre[i+w2][j+w3][k-1]=i*maxn+j+k*maxn*maxn;	
			}
		}
	}
	int k=0,i=n,j=m,x,y,z,w=f[n][m][0];
	while(i||j||k){
		x=(pre[i][j][k]/maxn)%maxn,y=pre[i][j][k]%maxn,z=pre[i][j][k]/maxn/maxn;
		if(z==k+1)ans1[--w]=')';
		else ans1[--w]='(';
		i=x,j=y,k=z;
	}
	puts(ans1);
	return 0;
}
