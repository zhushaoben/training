#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e;scanf("%d%d%d",&a,&b,&c),d=a^b^c;
	e=(a==d)+(b==d)+(c==d);
	if(e==1)puts("Yes");
	else puts("No");
	return 0;
}
