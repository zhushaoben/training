#include<bits/stdc++.h>
using namespace std;
void work(){
	int s,a,b,c;long long d;scanf("%d%d%d%d",&s,&a,&b,&c);
	d=s/c;d+=(d/a)*b;
	printf("%lld\n",d);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
