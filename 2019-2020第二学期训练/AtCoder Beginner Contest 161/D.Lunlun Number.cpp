#include<bits/stdc++.h>
using namespace std;
int f[10][11],g[10];
void work(int pre,int d,int k){
	if(d==-1)return;
	for(int i=max(pre-1,0);i<=pre+1;i++){
		if(f[d][i]>=k){
			printf("%d",i);work(i,d-1,k);break;
		}
		k-=f[d][i];
	}
}
int main(){
	for(int i=0;i<10;i++)f[0][i]=1;
	g[0]=9;for(int i=1;i<10;i++){
		for(int j=0;j<10;j++){
			if(j)f[i][j]+=f[i-1][j-1];
			f[i][j]+=f[i-1][j]+f[i-1][j+1];
		}
		g[i]=g[i-1];
		for(int j=1;j<10;j++)g[i]+=f[i][j];
	}
	int n;scanf("%d",&n);
	for(int i=0;i<10;i++){
		if(g[i]>=n){
			if(i)n-=g[i-1];
			for(int j=1;j<10;j++)if(f[i][j]>=n){printf("%d",j);work(j,i-1,n);break;}
			else n-=f[i][j];
			break;
		}
	}
	return 0;
}
