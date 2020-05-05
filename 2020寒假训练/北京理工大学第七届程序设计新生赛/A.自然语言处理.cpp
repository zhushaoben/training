#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
double a[15][15];int n,m;
int Guass(){
	int i=1,j=1,k,r,c;
	while(i<=m&&j<=n){
		r=i;for(k=i+1;k<=m;k++)if(fabs(a[k][j])>fabs(a[r][j]))r=k;
		if(fabs(a[r][j])>eps){
			for(c=1;c<=n+1;c++)swap(a[i][c],a[r][c]);
			for(k=i+1;k<=m;k++)if(fabs(a[k][j])>eps){
				double f=a[k][j]/a[i][j];
				for(c=j;c<=n+1;c++)a[k][c]-=f*a[i][c];
			}
			i++;
		}
		j++;
	}
	for(k=i;k<=m;k++)if(fabs(a[k][n+1])>eps)return 0;
	return 1;
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%lf",a[j]+i);
	for(int i=1;i<=m;i++)a[i][n+1]=0;
	if(n>m){puts("YES");return;}
	m++;a[m][1]=a[m][n+1]=1;
	for(int i=2;i<=n;i++)a[m][i]=0;
	if(Guass())puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
