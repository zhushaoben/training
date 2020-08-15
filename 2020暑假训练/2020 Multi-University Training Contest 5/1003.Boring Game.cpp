#include<bits/stdc++.h>
using namespace std;
int a[205][1<<11],b[11][1<<10],c[11][1<<10];
void work(){
	int n,k,s;scanf("%d%d",&n,&k),s=(1<<k);
	for(int i=0;i<s;i++){
		if(!(i&1))for(int j=n;j;j--)scanf("%d%d",a[j]+(i<<1),a[j]+(i<<1|1));
		else for(int j=1;j<=n;j++)scanf("%d%d",a[j]+(i<<1),a[j]+(i<<1|1));
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s;j++)printf("%d ",a[i][b[k][j]-1]);
		for(int j=0;j<s-1;j++)printf("%d ",a[i][c[k][j]-1]);
		if(i!=n)printf("%d ",a[i][c[k][s-1]-1]);
		else printf("%d\n",a[i][c[k][s-1]-1]);
	}
}
int main(){
	for(int i=1;i<=10;i++){
		for(int j=0;j<(1<<i);j++){
			int x=1,y=j+1,d=2;
			for(int k=1;k<=i;k++){
				if(y<=(1<<(i-k)))x=d-x+1,y=(1<<(i-k))-y+1;
				else x=d+x,y-=(1<<(i-k));
				d*=2;
			}
			b[i][j]=x;
			x=2,y=j+1,d=2;
			for(int k=1;k<=i;k++){
				if(y<=(1<<(i-k)))x=d-x+1,y=(1<<(i-k))-y+1;
				else x=d+x,y-=(1<<(i-k));
				d*=2;
			}
			c[i][j]=x;
		}
	}
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

/*
2 3 
1 4

  6 3 2 7
  5 4 1 8

14 3 6 11 10 7 2 15
13 4 5 12 9  8 1 16
*/
