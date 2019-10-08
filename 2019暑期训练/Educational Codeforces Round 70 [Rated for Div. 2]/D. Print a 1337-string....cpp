#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,i1=200;scanf("%d",&n);
	if(n<90000){
		for(int i=0;i<n;i++)putchar('1');
		puts("337");return;
	}
	int i2=i1*(i1-1)/2;
	int w=n/i2,w1=n%i2;
	for(int i=0;i<w;i++)putchar('1');
	for(int i=2;i<i1;i++)putchar('3');
	for(int i=0;i<w1;i++)putchar('1');
	puts("337");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
