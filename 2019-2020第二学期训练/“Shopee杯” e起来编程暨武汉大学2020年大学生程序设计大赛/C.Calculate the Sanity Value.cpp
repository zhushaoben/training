#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int rk[N],sa[N],height[N],n,m,c[N],x[N*2],y[N];
//nΪ����,mΪ�ؼ��ּ���С 
//rk[i] ��i����׺������ 
//sa[i] ����Ϊi�ĺ�׺λ��
//height[i] ����Ϊi�ĺ�׺������Ϊ(i-1)�ĺ�׺��LCP 
//cΪ��������Ͱ,x[i]Ϊsuf(i)�ĵ�һ�ؼ���(xʹ���ǿ��ܴ���n)
//y[i]��ʾ�ڶ��ؼ�������Ϊi��������һ�ؼ��ֵ�λ�� 

void get_sa(){//��sa���� 
	memset(c,0,sizeof(int)*(m+1));
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
void get_height(){//��rk��height 
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k)--k;//h[i]>=h[i-1]+1,����h[i]=height[rk[i]]
		if(rk[i]==1)continue;
		int j=sa[rk[i]-1];
		while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])k++;
		height[rk[i]]=k;
	}
}
int f[N][18];
inline int query(int l1,int r1){
	int l=rk[l1],r=rk[r1];
	if(l>r)swap(l,r);l++;
	int k=log(r-l+1)/log(2.0);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
void ST(){
	int m=log(n)/log(2.0);
	for(int i=1;i<=n;i++)f[i][0]=height[i];
	for(int i=0;i<m;i++)
		for(int j=n-(1<<(i+1))+1;j>=0;j--)
			f[j][i+1]=min(f[j][i],f[j+(1<<i)][i]);
}
void work(){
	scanf("%s",s+1);
	n=strlen(s+1),m=122;
	int ans=1;
	get_sa(),get_height();ST();
	for(int l=1;;l++){
		if(n/l<=ans)break;
		for(int i=l+1;i<=n;i+=l){
			if(s[i-l]!=s[i])continue;
			int w=query(i-l,i),t=i-l-(l-w%l),w1=w/l+1;
			if(t>0&&query(t,t+l)>=(l-w%l))w1++;
			ans=max(ans,w1);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)work();
	return 0;
}
