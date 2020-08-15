#include<bits/stdc++.h>
using namespace std;
const int N=105;
int d[N];
int main(){
	int n,ma=0,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",d+i),ma=max(ma,d[i]);
	for(int i=0;i<n;i++){
		x=ceil(50.0*d[i]/ma);
		putchar('+');for(int i=0;i<x;i++)putchar('-');putchar('+');puts("");
		putchar('|');for(int i=1;i<x;i++)putchar(' ');if(x)putchar(d[i]==ma?'*':' ');putchar('|');
		printf("%d\n",d[i]);
		putchar('+');for(int i=0;i<x;i++)putchar('-');putchar('+');puts("");
	}
	return 0;
} 
