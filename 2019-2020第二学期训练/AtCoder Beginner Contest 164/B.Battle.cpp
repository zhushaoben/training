#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	if((c-1)/b<=(a-1)/d)puts("Yes");
	else puts("No");
	return 0;
}
