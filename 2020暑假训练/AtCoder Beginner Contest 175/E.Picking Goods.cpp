#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int a[N][N];long long f[N][N][3];
int main(){
	int r,c,k,x,y,z;scanf("%d%d%d",&r,&c,&k);
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			for(int k=0;k<3;k++){
				f[i][j][k]=max(f[i-1][j][2],(k?f[i][j-1][k-1]:0))+a[i][j];
				f[i][j][k]=max(f[i][j][k],f[i][j-1][k]);
			}
		}
	}
	printf("%lld",f[r][c][2]);
	return 0;
}
