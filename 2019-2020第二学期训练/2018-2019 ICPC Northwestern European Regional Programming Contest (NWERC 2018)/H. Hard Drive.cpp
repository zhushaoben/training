#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int z[N];
int main(){
	int n,c,b,l=0,pre=0;scanf("%d%d%d",&n,&c,&b);
	for(int i=0;i<b;i++)scanf("%d",z+i);
	putchar(pre=(c&1?'1':'0'));
	for(int i=2;i<=n;i++){
		if(z[l]==i){c-=pre!='0',putchar(pre='0'),l++;continue;}
		if(c)putchar(pre^=1),c--;
		else putchar(pre);
	}
	return 0;
} 
