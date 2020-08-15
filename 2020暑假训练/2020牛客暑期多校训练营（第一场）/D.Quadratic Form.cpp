#include<bits/stdc++.h>
using namespace std;
const int N=205,mo=998244353;
typedef long long LL;
int n,a[N][N<<1],b[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*a*ans%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
void gauss(){
	for(int i=1,r;i<=n;i++){
		r=i;
		for(int j=i+1;j<=n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;//找到当前列绝对值最大的行 
		if(r!=i)for(int j=(n<<1);j>=1;j--)swap(a[r][j],a[i][j]);//交换当前列绝对值最大的行和没计算过的第一行
		
		int inv=qpow(a[i][i],mo-2);
		for(int k=1;k<=n;k++){//消去当前列（除本行外）
			if(k==i)continue;
			for(int j=(n<<1);j>=i;j--)(a[k][j]-=1ll*a[k][i]*inv%mo*a[i][j]%mo)%=mo;
		}
		for(int j=(n<<1);j>=1;j--)a[i][j]=1ll*a[i][j]*inv%mo;
	}
}
void work(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",a[i]+j),a[i][j+n]=0;
	for(int i=1;i<=n;i++)scanf("%d",b+i),a[i][i+n]=1;
	gauss();
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			(ans+=1ll*a[i][j+n]*b[j]%mo*b[i]%mo)%=mo;
	printf("%d\n",(ans+mo)%mo);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
