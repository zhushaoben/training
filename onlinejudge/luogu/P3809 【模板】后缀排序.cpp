#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int sa[N],n,m,c[N],x[N*2],y[N];
//nΪ����,mΪ�ؼ��ּ���С 
//rk[i] ��i����׺������ 
//sa[i] ����Ϊi�ĺ�׺λ��
//height[i] ����Ϊi�ĺ�׺������Ϊ(i-1)�ĺ�׺��LCP 
//cΪ��������Ͱ,x[i]Ϊsuf(i)�ĵ�һ�ؼ���(xʹ���ǿ��ܴ���n)
//y[i]��ʾ�ڶ��ؼ�������Ϊi��������һ�ؼ��ֵ�λ�� 

void get_sa(){//��sa���� 
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++,x[i+n]=0;//suf(i)��һ�ؼ��ֳ�ʼΪs[i] 
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1){//kΪ��ǰ�ؼ��ֳ��� 
		int num=0;
		for(int i=n-k+1;i<=n;i++)y[++num]=i;//��k����׺û�еڶ��ؼ���
		for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
		memset(c,0,sizeof(int)*(m+1));
		for(int i=1;i<=n;i++)++c[x[i]];
		for(int i=2;i<=m;i++)c[i]+=c[i-1];//c��ʾ��һ�ؼ���<=i�ĺ�׺���� 
		for(int i=n;i;i--)sa[c[x[y[i]]]--]=y[i];//���������ؼ��־�����sa
		//����y�ݴ�ؼ��ֳ��ȷ������x���� 
		num=1;
		y[sa[1]]=1;
		//��չ��һ�ؼ���ʱ�ϲ���ͬ�� 
		for(int i=2;i<=n;i++)y[sa[i]]=(x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k])?num:++num;
		if(num==n)break;//���ź� 
		m=num;//���¹ؼ��ּ���С
		memcpy(x,y,sizeof(int)*(n+1));
	}
}
void work(){
	scanf("%s",s+1);
	n=strlen(s+1),m=122;
	get_sa();
	for(int i=1;i<=n;i++)printf("%d ",sa[i]);
}
int main(){
	work();
	return 0;
}
