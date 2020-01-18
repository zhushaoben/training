#include<bits/stdc++.h>
using namespace std;
#define maxn 20
struct Node{
	char s[20];int x;
	bool operator < (const Node &b)const{
		return x>b.x;
	}
}a[maxn];
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s%d",a[i].s,&a[i].x);
	sort(a,a+n);
	printf("%s",a[0].s);
	for(int i=1;i<n;i++)printf(" %s",a[i].s);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
