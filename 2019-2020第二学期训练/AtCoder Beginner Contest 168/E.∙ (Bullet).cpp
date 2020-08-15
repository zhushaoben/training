#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mo=1e9+7,N=2e5+5;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
struct Node{
	LL a[2];
	bool operator < (const Node &b)const{
		if(a[0]!=b.a[0])return a[0]<b.a[0];
		return a[1]<b.a[1];
	}
};
map<Node,Node>mp;
int Pow[N];
int main(){
	int n,d;LL a,b,c,ans=1,w=0;scanf("%d",&n);
	Pow[0]=1;for(int i=1;i<=n;i++)Pow[i]=Pow[i-1]*2%mo;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		if(!(a|b)){w++;continue;}
		c=gcd(a,b),a/=c,b/=c;
		if(abs(b)<abs(a))d=1,swap(a,b),b=-b;
		else if(abs(a)==abs(b)&&(a|b)<0)d=1,a=abs(a),b=abs(b);
		else d=0;
		if(!a)b=1;if(a<0)a=-a,b=-b;
		mp[{a,b}].a[d]++;
	}
	for(auto x:mp)(ans*=Pow[x.second.a[0]]+Pow[x.second.a[1]]-1)%=mo;
	printf("%d",((ans+w-1)%mo+mo)%mo);
	return 0;
}
