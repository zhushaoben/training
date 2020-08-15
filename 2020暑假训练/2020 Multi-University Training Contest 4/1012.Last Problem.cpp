#include<bits/stdc++.h>
using namespace std;
const int N=125,M=8;
int a[N+5][N+5],b[N+5][N+5],w[5]={1,4,2,0,3},d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
//	freopen("3.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			b[i][j]=(j+w[i%5]-1)%5+1;
		}
	}
	for(int i=1;i<=5;i++){
		for(int x=1;x<=N;x++){
			for(int y=1;y<=N;y++){
				if(x+y<=M||(x+n-y+1)<=M||(x+n-y+1)<=M||(2*n-x-y+2)<=M)continue;
				if(b[x][y]!=i)continue;
				int sum=0;
				for(int k=0;k<4;k++)sum+=a[x+d[k][0]][y+d[k][1]];
				if(sum==(i-1)*i/2)printf("%d %d %d\n",x,y,i),a[x][y]=i;
			}
		}
	}
	for(int i=6;i<=n;i++){
		for(int x=1;x<=N;x++){
			for(int y=1;y<=N;y++){
				if(x+y<=M||(x+n-y+1)<=M||(x+n-y+1)<=M||(2*n-x-y+2)<=M)continue;
				if(a[x][y]!=i-5)continue;
				int sum=0;
				for(int k=0;k<4;k++)sum+=a[x+d[k][0]][y+d[k][1]];
				if(sum==i*4-10)printf("%d %d %d\n",x,y,i),a[x][y]=i;
			}
		}
	}
	return 0;
}
