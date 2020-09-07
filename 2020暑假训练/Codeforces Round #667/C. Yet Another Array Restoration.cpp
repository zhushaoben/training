#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,x,y;scanf("%d%d%d",&n,&x,&y);
	for(int i=1;;i++){
		if((y-x)%i||(y-x)/i+1>n)continue;
		for(int j=x;j<=y;j+=i,n--)printf("%d ",j);
		for(int j=x-i;j>0&&n;j-=i,n--)printf("%d ",j);
		for(int j=y+i;n;j+=i,n--)printf("%d ",j);
		break;
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
