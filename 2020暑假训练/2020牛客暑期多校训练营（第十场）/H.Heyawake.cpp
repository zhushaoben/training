#include<bits/stdc++.h>
using namespace std;
void work(){
	int n;scanf("%d",&n);
	if(n&1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)putchar('0'+(i&j&1));
			puts("");
		}
	}
	else{
		if(n==2){puts("10"),puts("00");return;}
		if(n==4){puts("1010"),puts("0000"),puts("1010"),puts("0001");return;}
		for(int i=1;i<=n;i++)putchar('0');puts("");
		for(int i=2;i<=n;i++){
			if(i%2==0)printf("100");
			else printf("001");
			for(int j=4;j<=n;j++)putchar('0'+(i%2==0&&j%2==0));
			puts("");
		}
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
