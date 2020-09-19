#include<bits/stdc++.h>
using namespace std;
const int N=15e4+5;
bitset<N> ans,cur;
struct Node{
	int x,id;
	bool operator <(const Node &b)const{return x>b.x;}
}a[N],b[N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i].x),a[i].id=i,ans.set(i);
	for(int i=0;i<m;i++)scanf("%d",&b[i].x),b[i].id=i;
	sort(a,a+n),sort(b,b+m);
	int l=0;
	for(int i=0;i<m;i++){
		while(a[l].x>=b[i].x)cur.set(a[l++].id);
		ans&=cur>>b[i].id;
	}
	printf("%d",ans.count());
	return 0;
} 
