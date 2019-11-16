#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 2
#define mo 1000000007
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
Matrix power(Matrix a,long long b){
    Matrix ans;ans.a[0][0]=ans.a[1][1]=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a,b>>=1;
    }
    return ans;
}
long long Fibonacci(long long x){
    if(x<2)return 1;a.a[0][0]=a.a[1][0]=a.a[0][1]=1,a.a[1][1]=0;
    Matrix b=power(a,x-2);
    return (b.a[0][0]+b.a[1][0])%mo;
}
void work(){
	LL n;scanf("%lld",&n);
	printf("%lld\n",Fibonacci(n+2)-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
