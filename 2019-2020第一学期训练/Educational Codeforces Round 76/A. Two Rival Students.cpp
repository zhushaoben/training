#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,x,a,b;scanf("%d%d%d%d",&n,&x,&a,&b);
	printf("%d\n",min(abs(a-b)+x,n-1));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
