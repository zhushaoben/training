#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,m;scanf("%d%d",&n,&m);
	if(1ll*n*(m-1)+1ll*m*(n-1)<=1ll*n*m)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
