#include<bits/stdc++.h>
using namespace std;
int x1,y10,x2,y2,x3,y3;
void work(){
	printf("%lld\n",llabs(11ll*(x1-x2)*(y3-y2)-11ll*(x3-x2)*(y10-y2)));
}
int main(){
	while(~scanf("%d%d%d%d%d%d",&x1,&y10,&x2,&y2,&x3,&y3))work();
	return 0;
} 
