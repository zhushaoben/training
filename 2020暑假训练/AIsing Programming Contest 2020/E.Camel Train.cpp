#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
struct C{
	int k,l,r;
	bool operator <(const C &b)const{return abs(l-r)>abs(b.l-b.r);}
}a[N];
set<int>S,S1;
void work(){
	int n,n1=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%d",&a[i].k,&a[i].l,&a[i].r),n1+=(a[i].l>a[i].r);
	S.clear(),S1.clear();
	for(int i=1;i<=n1;i++)S.insert(i);
	for(int i=n1+1;i<=n;i++)S1.insert(i);
	sort(a,a+n);LL ans=0;
	for(int i=0;i<n;i++){
		if(a[i].l>a[i].r){
			auto x=S.lower_bound(a[i].k+1);
			if(x!=S.begin()){
				x--;S.erase(x);
				ans+=a[i].l;
			}
			else ans+=a[i].r;
		}
		else{
			auto x=S1.upper_bound(a[i].k);
			if(x!=S1.end()){
				S1.erase(x);ans+=a[i].r;
			}
			else ans+=a[i].l;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
