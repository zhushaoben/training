/*
将图分为9块，其中123为一层，456为一层，789为一层。

1.两点在不同层（除了2，8）：两点之间的距离即为两点欧几里得距离，为了避免（2，8）这种情况，可以通过交换（x，y）转化为（4，6）。

2.两点在同一层，并且不在456这层：可以往下递归，y轴保持不变。

3.两点在同一层，并且在456这层：由于需要绕过中间这块，只要判断往上走还是往下走即可。


*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w[30]={1};
LL calc(LL x1,LL y1,LL x2,LL y2,int d){
	if(d==-1)return abs(y2-y1);
	LL a=x1/w[d],b=y1/w[d],c=x2/w[d],d1=y2/w[d];
	if(a!=c)return abs(x2-x1)+abs(y2-y1);
	else if(a==1&&abs(b-d1)>=2){
		x1-=w[d],x2-=w[d];
		return abs(y2-y1)+min(x1+x2+2,w[d]*2-x1-x2);
	}
	x1-=w[d]*a,x2-=w[d]*a;
	return calc(x1,y1,x2,y2,d-1);
}
LL work(){
	LL a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	a--,b--,c--,d--;if(abs(a-c)>abs(b-d))swap(a,b),swap(c,d);
	return calc(a,b,c,d,29);
}
int main(){
	for(int i=1;i<30;i++)w[i]=w[i-1]*3;
	int t;scanf("%d",&t);
	while(t--)printf("%lld\n",work());
	return 0;
}

