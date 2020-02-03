#include<bits/stdc++.h>
using namespace std;
int ma[105][11],num[11],ac[105][11],now[105][11];
int main(){
	int n,m,w,x,y,c;scanf("%d%d%d",&n,&m,&w);
	for(int i=0;i<w;i++){
		scanf("%d%d%d",&x,&y,&c);
		if(c==1){
			ma[x][y]=max(ma[x][y],now[x][y]),now[x][y]=0;
			if(!ac[x][y])ac[x][y]=1,num[y]++;
		}
		else now[x][y]++;
	}
	for(int i=1;i<=n;i++){
		int s=0,d=0,w=0;
		for(int j=1;j<=m;j++){
			ma[i][j]=max(ma[i][j],now[i][j]),d|=ma[i][j];
			if(ac[i][j])s++,w+=ma[i][j]*ma[i][j];
			else{
				w+=ma[i][j]*ma[i][j]*2;
				if(num[j])w+=20;if(num[j]>=n/2)w+=10;
			}
		}
		if(!s){
			if(!d)puts("998244353");
			else puts("1000000");
		}
		else if(s==m)puts("0");
		else printf("%d\n",w);
	}
	return 0;
}
