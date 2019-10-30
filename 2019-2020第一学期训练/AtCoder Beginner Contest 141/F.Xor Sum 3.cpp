/*
如果某一位二进制位上该为的数量为奇数个，那么不管这些数怎么分，这一位上总是有一堆是1，另一堆是0。
直接插入线性基的时候忽略掉数量为奇数的位，然后线性空间中找最大值即可。
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 100000
LL a[maxn],ans=0;
struct Base{
	LL a[63];
	void insert(LL x){
		for(int i=62;~i;i--){
			if(ans&(1ll<<i))continue;
			if(x&(1ll<<i)){
				if(!a[i]){a[i]=x;return;}
				x^=a[i];
			}
		}
	}
	LL Max(){
		LL ans=0;
		for(int i=62;~i;i--){
			ans^=(ans&(1ll<<i))?0:a[i];
		}
		return ans;
	}
}S;
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",a+i),ans^=a[i];
	for(int i=0;i<n;i++)S.insert(a[i]);
	LL w=S.Max();
	printf("%lld",((w^(w&ans))<<1)+ans);
	return 0;
}
