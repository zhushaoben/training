#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n),n%=10;
	if(n==3)puts("bon");
	else if(n==0||n==1||n==6||n==8)puts("pon");
	else puts("hon");
	return 0;
}
