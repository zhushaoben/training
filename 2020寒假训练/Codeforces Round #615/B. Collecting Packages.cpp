#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
bool fl;
struct Node{
	int x,y;
	bool operator < (const Node &b)const{
		if(fl||(x<b.x&&y>b.y)||(x>b.x&&y<b.y))return fl=1,0;
		return x<b.x||y<b.y;
	}
}a[maxn];
void work(){
	int n,x=0,y=0;scanf("%d",&n);fl=0;
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a,a+n);
	if(fl){puts("NO");return;}
	puts("YES");
	for(int i=0;i<n;i++){
		while(x<a[i].x)x++,putchar('R');
		while(y<a[i].y)y++,putchar('U');
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
