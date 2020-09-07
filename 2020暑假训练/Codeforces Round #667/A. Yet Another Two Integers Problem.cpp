#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void work(){
	int a,b;scanf("%d%d",&a,&b);
	printf("%d\n",a==b?0:(abs(a-b)-1)/10+1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
