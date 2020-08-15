#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c;scanf("%d%d",&a,&b);
	c=min(max(a,2*b),max(2*a,b));
	printf("%d\n",c*c);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
