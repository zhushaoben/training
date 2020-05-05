#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void P(int x,int s){
	if(x==0&&s==0)return;
	if(s<=x*9){
		for(int i=5;i<=9;i++){
			if(s-i<=(x-1)*9){
				printf("%d",i);
				P(x-1,s-i);
				return;
			}
		}
	}
	int w=(s-9*x-1)%4+1;
	printf("%d",w),P(x,s-w);
}
int work(){
	//s(2i)=2*s(i)-9x
	//s(i)=(a*s(i)/b+9*x)/2;
	//(2b-a)s(i)=9bx
	//s(i)=9bx/(2b-a)
	int a,b;scanf("%d%d",&a,&b);
	if(2*b-a<0||9*b<5*(2*b-a))return puts("0"),0;
	if(2*b==a)return puts("1"),0;
	int x=(2*b-a)/gcd(9*b,2*b-a),s=9*b*x/(2*b-a);
	P(x,s);puts("");
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
