#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int S=7,mo=1e9+7;
struct Matrix{
    long long a[S][S],n;
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator * (const Matrix& c)const{//n^3æÿ’Û≥À∑® 
        Matrix b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    b.a[i][j]+=a[i][k]*c.a[k][j];
                    b.a[i][j]%=mo;
                }
            }
        }
        b.n=n;
        return b;
    }
}a,b,a1,b1,a2,b2,a3,b3;
Matrix power(Matrix a,long long b){//øÏÀŸ√›£∫a^b%mo
    Matrix ans;ans.n=a.n;
    for(int i=0;i<a.n;i++){
    	ans.a[i][i]=1;
	}
    while(b){
        if(b&1)ans=ans*a;
        a=a*a,b>>=1;
    }
    return ans;
}
LL f[3],f1[3];
LL calc1(LL l,LL r){//(-1)^i
	if(l%2==0){
		return ((r-l)/2+(r%2==0))%mo;
	}
	else{
		return ((-(r-l)/2-(r%2!=0))%mo+mo)%mo;
	}
}
LL calc2(LL l,LL r){//i%5
	LL l1=l/5,r1=r/5,ans=0;
	for(int i=l%5;i<=4;i++)ans+=i;
	for(int i=0;i<=r%5;i++)ans+=i;
	return ((r1-l1-1)*10+ans)%mo;
} 
void work(){
	LL n,n1;scanf("%lld",&n),n1=n;
	f[1]=f[2]=1;
	if(n<=2){puts("1");return;}
	int i;
	for(i=2;n>(1ll<<i);i++){
		b=power(a,1ll<<(i-1)),b1=power(a1,1ll<<(i-1));
		f1[1]=(f[1]*b.a[1][1]+f[2]*b.a[1][0]+(i-1)*b1.a[1][2])%mo;
		f1[2]=(f[1]*b.a[0][1]+f[2]*b.a[0][0]+(i-1)*b1.a[0][2])%mo;
		f[1]=f1[1],f[2]=f1[2];
	}
	i--;n=n-(1ll<<i);
	b=power(a,n),b1=power(a1,n);
	LL ans=(f[1]*b.a[0][1]+f[2]*b.a[0][0]+i*b1.a[0][2])%mo;
	b2=power(a2,n1-2);b3=power(a3,n1-2);
	(ans+=b2.a[0][2]*2+b2.a[0][3]*3+b2.a[0][4]*4+b2.a[0][5]*0+b2.a[0][6]*1+b3.a[0][2]-b3.a[0][3])%=mo;
	printf("%lld\n",(ans+mo)%mo);
}
int main(){
	a.n=2;a.a[0][0]=a.a[0][1]=a.a[1][0]=1;
	a1.n=3;a1.a[0][0]=a1.a[0][1]=a1.a[0][2]=a1.a[1][0]=a1.a[2][2]=1;
	a2.n=7;a2.a[0][0]=a2.a[0][1]=a2.a[0][2]=a2.a[1][0]=a2.a[2][3]=a2.a[3][4]
	=a2.a[4][5]=a2.a[5][6]=a2.a[6][2]=1;
	a3.n=4,a3.a[0][0]=a3.a[0][1]=a3.a[0][2]=a3.a[1][0]=a3.a[2][3]=a3.a[3][2]=1;
	int t=1;
	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
