#include<bits/stdc++.h>
using namespace std;
int f[1000][1000];
void work(){
	int q,k,m,n;scanf("%d",&k);
	for(int i=0;i<=20;i++){
		for(int j=0;j<=20;j++){
			int w=1;
			if(i>0)w&=f[i-1][j];
			if(j>0)w&=f[i][j-1];
			if(i>=k&&j>=k)w&=f[i-k][j-k];
			f[i][j]=!w;
			printf("%d ",f[i][j]);
		}
		puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)work();
	return 0;
}
