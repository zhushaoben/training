#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
const double eps=1e-7;
struct Node{
	int a,p;
	bool operator < (const Node &b)const{
		if(a!=b.a)return a<b.a;
		else return p<b.p;
	}
}w[N];
long double t[N];
int st[N],top;
bool vis[N];
bool check(int i,int j){
	if(w[j].p==w[i].p&&w[j].a==w[i].a)return vis[i]=1,t[j]=1e10,1;
	if(w[j].p>=w[i].p)return 0;
	if(w[j].a==w[i].a)return t[j]=1e10,1;
	long double x=(long double)2.0*(w[i].p-w[j].p)/(w[j].a-w[i].a);
	t[j]=max(t[j],x);
	if(x-t[i]<eps)return 0; 
	return 1;
}
void work(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&w[i].p,&w[i].a),t[i]=0,vis[i]=0;
	sort(w,w+n);top=0;
	for(int i=0;i<n;i++){
		while(top&&!check(st[top],i))top--;
		if(1e10-t[i]>eps)st[++top]=i;
	}
	while(top)if(!vis[st[top--]])ans++;
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
