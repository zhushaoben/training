#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct Node{
	int l,r;
	bool operator <(const Node &b)const{
		return l<b.l;
	}
}a[maxn];
priority_queue<int>q;
void work(){
	int n,now=0,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a,a+n);a[n].l=0;
	for(int i=0;i<n;i++){
		while(!q.empty()&&now<a[i].l){
			int x=-q.top();q.pop();
			if(x>=now)now++,ans++;
		}
		now=a[i].l;
		q.push(-a[i].r);
		while(a[i+1].l==a[i].l)q.push(-a[++i].r);
	}
	while(!q.empty()){
		int x=-q.top();q.pop();
		if(x>=now)now++,ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
