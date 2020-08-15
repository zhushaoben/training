#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,m,n1;scanf("%d%d",&n,&m),n1=sqrt(n);
	if(m%2||m>n*4||m<n1*4+(n1*n1==n?0:2)){puts("No");return;}
	m/=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(m-i-j<0)break;
			int k=(m-i-j);if(k&1)continue;k/=2;
			if(i*j+k>=n&&i+j-1+k<=n){
				puts("Yes");
				n-=i+j-1+k;
				for(int i=0;i<k;i++)printf("%d %d\n",-2,i*2);
				for(int y=0;y<j;y++)printf("0 %d\n",y);
				for(int x=1;x<i;x++){
					int y;
					for(y=min(j-1,n),n-=y;~y;y--){
						printf("%d %d\n",x,y);
					}
				}
				return;
			}
		}
	}
	puts("No");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
