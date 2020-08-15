#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);
	a=h*3600+m*60+s;
	scanf("%d:%d:%d",&h,&m,&s);
	b=h*3600+m*60+s;
	printf("%d\n",abs(a-b));
	return 0;
} 
