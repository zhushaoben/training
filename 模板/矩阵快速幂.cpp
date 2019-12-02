#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 2
#define mo 1000000007//要求的余数 
struct Matrix{
    long long a[maxn][maxn];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator * (const Matrix& c)const{//n^3矩阵乘法 
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
Matrix power(Matrix a,long long b){//快速幂：a^b%mo
    Matrix ans;
    for(int i=0;i<maxn;i++){
    	ans.a[i][i]=1;
	}
    while(b){
        if(b&1)ans=ans*a;
        a=a*a,b>>=1;
    }
    return ans;
}
int main(){
	return 0;
} 
