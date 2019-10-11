#include<bits/stdc++.h>
using namespace std;
#define LL long long
void work(){
	LL a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	LL w=a-b,w1=c-d,w2=w1/w;
	if(!w){
		if(a==b&&b==c&&c==d){
			puts("Yes");puts("");return;
		}
		puts("No");return;
	}
	if((w1%w)||w2<=0){puts("No");return;}
	while(w2){if((w2&1)&&w2!=1){puts("No");return;}w2>>=1;}
	w2=w1/w-1;
	if((c-a)%w||(b-d)%w){puts("No");return;}
	LL a1=(c-a)/w,b1=(b-d)/w;if((a1^b1)!=w2){puts("No");return;}
	puts("Yes");
	for(int i=0;(1ll<<i)<=w2;i++){
		if(a1&(1ll<<i))putchar('B');
		else putchar('A');
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
