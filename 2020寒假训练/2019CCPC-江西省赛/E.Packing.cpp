#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
struct Node{
	int t,x;
	bool operator <(const Node &b)const{
		return t<b.t;
	}
}a[maxn];
int n,m,b[maxn];
void work(){
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].t,&a[i].x);
	for(int i=0;i<m;i++)scanf("%d",b+i);
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
} 
