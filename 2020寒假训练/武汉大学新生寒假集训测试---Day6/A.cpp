#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn],num[maxn];
int main(){
	int n,b=0,c=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),num[a[i]]++;
	for(int i=1;i<=100;i++)if(num[i]==1)b++;else if(num[i]>2)c++;
	if((b&1)&&c==0)return puts("NO"),0;
	puts("YES");
	int fl=(b&1);
	for(int i=0;i<n;i++){
		if(fl&&num[a[i]]>2)putchar('B'),fl=0;
		else if(num[a[i]]==1){
			if(b&1)putchar('A');
			else putchar('B');
			b--;
		}
		else putchar('A');
	}
	return 0;
} 
