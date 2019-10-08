#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define maxn 2000
int a,b,f[maxn+5][maxn+5];
void work(){
	int n=a+b;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=0;
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i<n&&j>i-a){//push A 
				(f[i+1][j]+=f[i][j])%=mo;
			}
			if(j<n&&i>j-b){//push B
				(f[i][j+1]+=f[i][j])%=mo; 
			}
		}
	}
	printf("%d\n",f[n][n]);
}
int main(){
	while(~scanf("%d%d",&a,&b))work();
	return 0;
} 
