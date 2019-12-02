#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c;scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	if(a*2<b){puts("NO");return;}
	c=b-a;a-=c,b-=2*c;
	if(a!=b||(a+b)%3)puts("NO");
	else puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
