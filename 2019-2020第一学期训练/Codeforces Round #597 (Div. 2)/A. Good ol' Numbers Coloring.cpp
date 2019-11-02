#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void work(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(gcd(a,b)==1)puts("Finite");
	else puts("Infinite");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
