#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int x,type;
	bool operator < (const Node &b)const{
		return x>b.x;
	}
}a[N*3]; 
int main(){
	int x,y,z=0,A,b,c,si=0;scanf("%d%d%d%d%d",&x,&y,&A,&b,&c);
	for(int i=0;i<A;i++)scanf("%d",&a[si].x),a[si++].type=1;
	for(int i=0;i<b;i++)scanf("%d",&a[si].x),a[si++].type=2;
	for(int i=0;i<c;i++)scanf("%d",&a[si++].x);
	sort(a,a+si);
	long long ans=0;
	for(int i=0;i<si;i++){
		 if(a[i].type==1&&x)x--,ans+=a[i].x;
		 else if(a[i].type==2&&y)y--,ans+=a[i].x;
		 else if(a[i].type==0&&x+y+z>0)z--,ans+=a[i].x;
		 if(x+y+z==0)break;
	}
	printf("%lld",ans);
	return 0;
}
