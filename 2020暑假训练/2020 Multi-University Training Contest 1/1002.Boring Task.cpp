#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
	LL t,d;
	bool operator <(const Node &b)const{
		return max(0ll,a.t+a.d-b.t)<max(0ll,b.t+b.d-a.t);
	}
	bool operator ==(const Node &b)const{return !(a<b||b<a);}
}a[N];
bool cmp(Node &a,Node &b){
	return a.t<b.t;
}
priority_queue<Node>q;
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i].t);
	for(int i=0;i<n;i++)scanf("%lld",&a[i].d);
	sort(a,a+n);
	LL now=0,ans=0;
	for(int i=0;i<n;i++){
		while(i<n-1&&a[i]==a[i+1])
		now=max(now,a[i].t);
		ans=max(ans,now-a[i].t);
		now+=a[i].d;
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
