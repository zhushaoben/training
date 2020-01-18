#include<bits/stdc++.h>
using namespace std;
void change(int &h,int &m,int &s){
	s++,m+=s/60,h+=m/60;s%=60,m%=60,h%=12;
}
int calc(int a1,int a2){
	return a1-a2>=0?a1-a2:a1-a2+360*120;
}
int main(){
	int h,m,s,a,t=1;
	while(~scanf("%d:%d:%d%d",&h,&m,&s,&a)){
		printf("Case #%d: ",t++);a%=180;
		a*=120;int a1=3600*h+60*m+s,a2=720*m+12*s,op;
		if(calc(a2,a1)<a)op=(a-calc(a2,a1))/11;
		else if(calc(a1,a2)<=a)op=(a+calc(a1,a2))/11;
		else op=(360*120-calc(a2,a1)-a)/11;
		while(op--)change(h,m,s);
		printf("%02d:%02d:%02d\n",h,m,s);
	}
	return 0;
}
