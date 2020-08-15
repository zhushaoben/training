#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int f[1005][1005];
void work(){
	int a,b;scanf("%d%d",&a,&b);
	printf("%d\n",f[a][b]);
}
int main(){
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			f[i][j]=max(f[i][j-1],f[i-1][j])+(gcd(i,j)==1);
		}
	}
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
