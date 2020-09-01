#include<bits/stdc++.h>
using namespace std;
int a[5][5];
void work(){
	int ans=0,fl;
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++){
		fl=1;
		for(int k=1;k<=3;k++)for(int l=1;l<=3;l++){
			if(i==k||j==l)continue;int w=0;
			for(int x=1;x<=3;x++)for(int y=1;y<=3;y++){
				if((x==i&&y==j)||(x==k&&y==l))continue;
				if(x==i||y==j||x==k||y==l)w^=(a[x][y]-1);
				else w^=a[x][y];
			}
			if(!w)fl=0;
		}
		ans+=fl;
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
