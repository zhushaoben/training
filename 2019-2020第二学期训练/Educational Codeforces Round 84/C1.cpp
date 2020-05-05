#include<bits/stdc++.h>
using namespace std;
const int N=205;
int x[N],y[N];
char s[N*N*2];
int main(){
	int n,m,k,ans=0,x1,y1;scanf("%d%d%d",&n,&m,&k);
	printf("%d\n",n+m+n*m-2);
	for(int i=1;i<n;i++)putchar('U');
	for(int i=1;i<m;i++)putchar('L');
	for(int i=0;i<n;i++){
		if(i&1)for(int j=1;j<m;j++)putchar('L');
		else for(int j=1;j<m;j++)putchar('R');
		putchar('D');
	}
	return 0;
}
