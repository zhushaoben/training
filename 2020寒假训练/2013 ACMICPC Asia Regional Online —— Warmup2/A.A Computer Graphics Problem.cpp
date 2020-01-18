#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		scanf("%d",&x);x/=10;
		puts("*------------*");
		for(int i=10;i>x;i--)puts("|............|");
		for(int i=0;i<x;i++)puts("|------------|");
		puts("*------------*");
	}
	return 0;
} 
