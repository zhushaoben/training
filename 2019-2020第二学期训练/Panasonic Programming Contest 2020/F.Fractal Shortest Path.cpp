/*
��ͼ��Ϊ9�飬����123Ϊһ�㣬456Ϊһ�㣬789Ϊһ�㡣

1.�����ڲ�ͬ�㣨����2��8��������֮��ľ��뼴Ϊ����ŷ����þ��룬Ϊ�˱��⣨2��8���������������ͨ��������x��y��ת��Ϊ��4��6����

2.������ͬһ�㣬���Ҳ���456��㣺�������µݹ飬y�ᱣ�ֲ��䡣

3.������ͬһ�㣬������456��㣺������Ҫ�ƹ��м���飬ֻҪ�ж������߻��������߼��ɡ�


*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w[30]={1};
LL calc(LL x1,LL y1,LL x2,LL y2,int d){
	if(d==-1)return abs(y2-y1);
	LL a=x1/w[d],b=y1/w[d],c=x2/w[d],d1=y2/w[d];
	if(a!=c)return abs(x2-x1)+abs(y2-y1);
	else if(a==1&&abs(b-d1)>=2){
		x1-=w[d],x2-=w[d];
		return abs(y2-y1)+min(x1+x2+2,w[d]*2-x1-x2);
	}
	x1-=w[d]*a,x2-=w[d]*a;
	return calc(x1,y1,x2,y2,d-1);
}
LL work(){
	LL a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	a--,b--,c--,d--;if(abs(a-c)>abs(b-d))swap(a,b),swap(c,d);
	return calc(a,b,c,d,29);
}
int main(){
	for(int i=1;i<30;i++)w[i]=w[i-1]*3;
	int t;scanf("%d",&t);
	while(t--)printf("%lld\n",work());
	return 0;
}

