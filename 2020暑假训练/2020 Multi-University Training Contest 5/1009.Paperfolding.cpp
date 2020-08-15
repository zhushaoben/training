#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
#define maxn 3
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
}a,b;
Matrix power(Matrix a,long long b){//a^b%mo
    Matrix ans;ans.a[0][0]=ans.a[1][1]=ans.a[2][2]=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a,b>>=1;
    }
    return ans;
}
void work(){
	long long n;scanf("%lld",&n);
	a.a[0][0]=2,a.a[1][1]=748683265ll*6%mo,a.a[0][1]=-1,a.a[0][2]=-1,a.a[2][2]=1;
	b=power(a,n);
	printf("%d\n",((4ll*b.a[0][0]+b.a[0][1]+b.a[0][2])%mo+mo)%mo);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
