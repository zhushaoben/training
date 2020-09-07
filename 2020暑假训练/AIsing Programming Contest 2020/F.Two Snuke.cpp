/*
a^(n+5).a[10][0] indicate the number that splitting n to 5 even numbers
a^(n+10).a[15][0] indicate the number that splitting x(x<=n) to 5 even numbers
*/
#include<bits/stdc++.h>
using namespace std;
const int N=25,mo=1e9+7;
struct Matrix{
	int a[N][N],n;
	Matrix operator * (const Matrix &b)const{
		Matrix c;c.n=n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				c.a[i][j]=0;
				for(int k=0;k<n;k++)(c.a[i][j]+=1ll*a[i][k]*b.a[k][j]%mo)%=mo;
			}
		return c;
	}
}a;
Matrix qpow(Matrix a,int b){
	Matrix ans;ans.n=a.n;
	for(int i=0;i<a.n;i++){
		for(int j=0;j<a.n;j++)ans.a[i][j]=0;
		ans.a[i][i]=1;
	}
	while(b){
		if(b&1)ans=ans*a;
		a=a*a,b>>=1;
	}
	return ans;
}
int main(){
	a.n=21;
	for(int i=0;i<5;i++)a.a[i<<1][i<<1|1]=a.a[i<<1|1][i<<1]=a.a[(i+1)<<1][i<<1]=1;
	for(int i=10;i<=20;i++)a.a[i+1][i]=a.a[i][i]=1;
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",qpow(a,n+10).a[20][0]);
	}
	return 0;
}
