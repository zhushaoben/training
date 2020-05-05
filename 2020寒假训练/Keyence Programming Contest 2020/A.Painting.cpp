#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w,n;scanf("%d%d%d",&h,&w,&n);
	h=max(h,w);
	printf("%d",(n-1)/h+1);
	return 0;
} 
