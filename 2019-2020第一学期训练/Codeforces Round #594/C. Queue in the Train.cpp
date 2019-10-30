#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
#define LL long long
struct Node{
	int id,x;
	bool operator < (const Node &b)const{
		return x<b.x;
	}
}a[maxn+5];
LL ans[maxn+5];
priority_queue<int>q;
int main(){
	int n,p;scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].x),a[i].id=i;
	}sort(a,a+n);
	LL t=a[0].x;
	int t1=0,num=0;
	while(1){
		while(t>=a[t1].x&&t1<n)q.push(-a[t1++].id);
		if(q.empty()){
			t=a[t1].x;continue;
		}
		t+=p;int x=-q.top();q.pop();ans[x]=t;
		if((++num)==n)break;
	}
	for(int i=0;i<n;i++)printf("%lld ",ans[i]);
	return 0;
}
