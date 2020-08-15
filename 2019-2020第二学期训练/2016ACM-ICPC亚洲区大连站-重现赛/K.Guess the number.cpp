#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,mo=1e8+73;
int f[N],cnt[N];
int main(){
	f[1]=1,cnt[1]=1,f[2]=2,cnt[2]=2,f[3]=2,cnt[3]=1;int n,x=3,w=0,pre=3;
	for(int i=3;;i++){
		for(int j=0;j<i&&x<N;j++){
			f[++x]=i;
			if(j>1)cnt[x]=((cnt[x-1]-cnt[x-i-1])%mo+mo)%mo;
			else if(j==1)cnt[x]=pre;
			else cnt[x]=(pre+cnt[x-i])%mo;
			(w+=cnt[x])%=mo;
		}
		pre=w,w=0;
		if(x>=N)break;
	}
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		b-=a-1;
		printf("%d %d\n",f[b],cnt[b]%mo);
	}
	return 0;
}
