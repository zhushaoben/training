#include<bits/stdc++.h>
using namespace std;
void work(){
	int n;scanf("%d",&n);
	if(n&1)putchar('7'),n-=3;
	while(n)putchar('1'),n-=2;
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
