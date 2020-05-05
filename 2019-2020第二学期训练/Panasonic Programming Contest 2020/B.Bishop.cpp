#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;scanf("%d%d",&h,&w);
	if(h==1||w==1)return puts("1"),0;
	printf("%lld",(1ll*h*w+1)/2);
	return 0;
}
