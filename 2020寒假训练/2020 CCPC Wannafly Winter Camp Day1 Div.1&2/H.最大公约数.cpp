#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define maxs 1000000000
#define LL long long
struct Bign{
	LL a[maxn],l;
	Bign operator * (const int b){
		int x=0;
		for(int i=0;i<l;i++)a[i]=a[i]*b+x,x=a[i]/maxs,a[i]%=maxs;
		if(x)a[l++]=x;
		return *this;
	}
    void Print(){
    	printf("%d",a[--l]);
    	for(int i=l-1;~i;i--)printf("%09d",a[i]);
	}
}ans;
int prim[505],prime_n; 
bool is_pr[505]={1,1};
void prime(){
    int m=500;
    for(int i=2;i<m;i++){
        if(!is_pr[i])prim[prime_n++]=i;//没有筛掉的为素数
        for(int j=0;j<prime_n&&i*prim[j]<m;j++){
            is_pr[prim[j]*i]=1;//筛掉
            if(i%prim[j]==0)break;//后面的数最小因数一定小于等于prim[j]
        }
    }
}
void work(){
	memset(&ans,0,sizeof(ans)),ans.l=ans.a[0]=1;
	int n,k;scanf("%d%d",&n,&k);ans=ans*k;
	for(int i=0;i<prime_n;i++){
		if(prim[i]*k>n)break;
		ans=ans*prim[i];
	}
	ans.Print();puts("");
}
int main(){
	prime();
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
