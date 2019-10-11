#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int num[maxn+5];
int main(){
//	freopen("1.in","r",stdin);
	int h,w,a,b,c=0,d=0;scanf("%d%d%d%d",&h,&w,&a,&b);
	c=b,d=a;
	for(int i=0;i<h;i++){
		int w1=((i<c)?a:w-a);
		for(int j=0;j<w;j++){
			if(w1&&num[j]<((j<d)?b:h-b))num[j]++,putchar('1'),w1--;
			else putchar('0');
		}
		puts("");
	}
	return 0;
} 

