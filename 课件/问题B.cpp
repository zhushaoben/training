#include<cstdio>
typedef long long ll;
ll f[13]={0,1},l,r,s=10,ans[10];
ll sum(ll x){//ѯ��[0,x]���������������ֳ��ֵĴ����ܺ� 
	if(x<0)return 0;
	ll ans=1,x1=x,s=1,i=1;
	while(x>=10){
		ans+=9*s*i;
		x/=10,s*=10,i++;
	}
	return ans+s*(x-1)*i+(x1%s+1)*i;
}
ll query(ll x,int k){//ѯ��[0,x]��������k���ֵĴ��� 
	if(x<0)return 0;
	ll sum=0,a,i=1,s=1,x1=x;
	while(x){
		a=x%10;
		sum+=f[i-1]*a;
		if(a>k)sum+=s;
		else if(a==k)sum+=x1%s+1;
		x/=10,s*=10,i++;
	}
	return sum;
}
/*
ll query0(ll x,ll k=0){//ѯ��[0,x]��������k���ֵĴ��� 
	if(x<0)return 0;
	ll sum=0,a=1,i=1,s=1,x1;
	while(x/10){//ö��k������ÿһλ 
		i=x%10,x/=10;//i��ʾk���ֵ���һλ��ԭ������ʲô,x��ʾԭ����i֮ǰ������ 
		x1=x-1;
		if(i>k)sum+=s*(x1+1);//3������������� 
		else if(i==k)sum+=s*x1+a;
		else sum+=s*x1;
		a+=i*s,s*=10;//a��ʾԭ����i֮�������+1 
	}
	if(!k)return sum+1;//ΪkΪ0���޷�����һλ 
}
*/
int main(){
	for(int i=2;i<12;i++){
		f[i]=f[i-1]*10+s,s*=10;
	}
	scanf("%lld%lld",&l,&r);
	ans[0]=sum(r)-sum(l-1);
	for(int i=1;i<=9;i++){
		ans[i]=query(r,i)-query(l-1,i);
		ans[0]-=ans[i];
	}
	for(int i=0;i<=9;i++)printf("%lld ",ans[i]);
	return 0;
}
