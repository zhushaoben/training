#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,inv=499122177,maxn=2;
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
struct Matrix{
    long long a[maxn][maxn];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator * (const Matrix& c)const{
        Matrix b;
        for(int i=0;i<maxn;i++){
            for(int j=0;j<maxn;j++){
                for(int k=0;k<maxn;k++){
                    b.a[i][j]+=a[i][k]*c.a[k][j];
                    b.a[i][j]%=mo;
                }
            }
        }
        return b;
    }
}a;
Matrix power(Matrix a,long long b){//a^b%mo
    Matrix ans;ans.a[0][0]=ans.a[1][1]=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a,b>>=1;
    }
    return ans;
}
int main(){
	int n,m,l,r;scanf("%d%d%d%d",&n,&m,&l,&r);
	int x=r-l+1,x1=x/2+((l&1)&&(r&1)),x2=x/2+(l%2==0&&r%2==0);
	if(1ll*n*m%2==1){
		printf("%d",Pow(x,(1ll*n*m)%(mo-1)));
		return 0;
	}
	a.a[1][1]=a.a[0][0]=x2,a.a[0][1]=a.a[1][0]=x1;
	a=power(a,1ll*n*m-1);
	printf("%d",(1ll*x1*a.a[1][0]+1ll*x2*a.a[1][1])%mo);
	return 0;
}
