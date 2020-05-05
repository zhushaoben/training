#include<bits/stdc++.h>
using namespace std;
int a,b,g[10],f[10],Pow[10];
int calc(int x,int fl){//[0,x]的答案  fl=1则第一位不能是2
	if(x==0)return 1;
	int w=x,d=0,ans=0;//d表示x位数-1    w表示x最高位 
	while(w>=10)w/=10,d++;
	for(int i=0;i<w;i++){
		if(i==2&&fl)continue;
		ans+=(i==6?f[d]:g[d]);
	}
	if(w!=2||!fl)ans+=calc(x-w*Pow[d],w==6&&d&&(x-w*Pow[d])>=Pow[d-1]);
	return ans;
}
int main(){
	f[0]=g[0]=Pow[0]=1;
	for(int i=1;i<10;i++)
		f[i]=8*g[i-1]+f[i-1],
		g[i]=9*g[i-1]+f[i-1],
		Pow[i]=Pow[i-1]*10;
	while(~scanf("%d%d",&a,&b)&&b){
		printf("%d\n",calc(b,0)-calc(a-1,0));
	}
	return 0;
}
