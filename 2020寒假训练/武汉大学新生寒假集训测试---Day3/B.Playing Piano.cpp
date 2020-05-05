#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int f[maxn][5],pre[maxn][5],ans[maxn],a[maxn];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	f[1][0]=f[1][1]=f[1][2]=f[1][3]=f[1][4]=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]<a[i])for(int j=0;j<5;j++){
			for(int k=0;k<j;k++){
				if(f[i-1][k])f[i][j]=1,pre[i][j]=k;
			}
		}
		else if(a[i-1]>a[i])for(int j=0;j<5;j++){
			for(int k=j+1;k<5;k++)if(f[i-1][k])f[i][j]=1,pre[i][j]=k;
		}
		else for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)if(f[i-1][k]&&j!=k)f[i][j]=1,pre[i][j]=k;
	}
	int fl=0;
	for(int i=0;i<5;i++){
		if(f[n][i])fl=i+1;
	}
	if(!fl)return puts("-1"),0;
	for(int i=n;i;i--){
		ans[i]=fl;
		fl=pre[i][fl-1]+1;
	}
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	printf("%d",ans[n]);
	return 0;
}
