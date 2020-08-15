#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL calc(int n,int m,int a1){
	if(a1<1)return 0;
	int w1=n-m*a1,w2=w1/2;
	if(w1&1){
		int r=m-w2+1,l=r-1;
		return max(0,min(l-1,m-r+1));
	}
	else{
		int r=m-w2+2,l=r-2;
		return max(0,min(l-1,m-r+1));
	}
}
LL cal(int n,int m){
	int l=(n-3)/m,r=(n+3)/m-2;
	LL ans=0;
	for(int i=r;i<=l;i++)ans+=calc(n,m,i);
	return ans;
}
int f[100][100];
int main(){
	freopen("e123.out","w",stdout);
	for(int i=1;i<=99;i++){
		LL w=0;
		for(int m=3;m<=i-3;m++){
			f[i][m]=cal(i,m)+f[i-1][m];
			printf("%5d",f[i][m]);
		}
		puts("");
	}
	return 0;
} 
