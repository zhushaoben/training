#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
const int N=30;
double a[N][N],f[N];
int d[N];
int gauss_jordan(int n){
	int r,w=0;
	for(int i=0;i<n&&w<n;w++,i++){
		int r=w;
		for(int j=w+1;j<n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;
		if(fabs(a[r][i])<eps){w--;continue;}
		if(r!=w)for(int j=0;j<=n;j++)swap(a[r][j],a[w][j]);
		for(int k=0;k<n;k++)
			if(k!=w)for(int j=n;j>=w;j--)a[k][j]-=a[k][i]/a[w][i]*a[w][j];
	}
	return w;
}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v),d[u]++,d[v]++;
		a[u][v]=-1,a[v][u]=-1;
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]/=d[i];
	for(int i=0;i<n;i++)a[i][i]=a[i][n]=1,a[n-1][i]=0;
	a[n-1][n-1]=1,a[n-1][n]=0;
	gauss_jordan(n);
	printf("%.8lf",a[0][n]/a[0][0]);
	return 0;
}
