#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c,n,sum,ma;
	scanf("%d%d%d%d",&a,&b,&c,&n);
	ma=max(a,max(b,c)),sum=a+b+c;
	if(n>=ma*3-sum&&(n+sum)%3==0)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
