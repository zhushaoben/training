#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int a[maxn][maxn];
int main(){
	int n,x,y;scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		scanf("%d",a[i]+j);
		if(a[i][j]==-1)x=i,y=j;
	}
	int x1=x+(x>0?-1:1),y1=y+(y>0?-1:1);
	printf("%d",a[x][y1]+a[x1][y]-a[x1][y1]);
	return 0;
}
