#include<bits/stdc++.h>
using namespace std;
void work(){
	long long x1,y1,x2,y2,x3,y3;scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
	if((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)<0)puts("Clockwise");
	else puts("Counterclockwise");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
