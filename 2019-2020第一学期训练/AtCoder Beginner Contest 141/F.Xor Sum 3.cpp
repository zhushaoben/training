/*
���ĳһλ������λ�ϸ�Ϊ������Ϊ����������ô������Щ����ô�֣���һλ��������һ����1����һ����0��
ֱ�Ӳ������Ի���ʱ����Ե�����Ϊ������λ��Ȼ�����Կռ��������ֵ���ɡ�
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
