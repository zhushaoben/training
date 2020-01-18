#include<bits/stdc++.h>
using namespace std;
#define LL long long
void work(){
	int n,m;scanf("%d%d",&n,&m);
	if(n%m)puts("1");
	else puts("0");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
