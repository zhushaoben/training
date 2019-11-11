#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,n,s;scanf("%d%d%d%d",&a,&b,&n,&s);
	if(1ll*a*n+b>=s&&s%n<=b)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
