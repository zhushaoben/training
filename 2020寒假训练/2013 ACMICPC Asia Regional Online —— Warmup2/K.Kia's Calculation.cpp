#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
char s[maxn];
int a[10],b[10],c[10];
void work(){
	memset(a,0,sizeof(a)),memset(b,0,sizeof(a)),memset(c,0,sizeof(a));
	scanf("%s",s);for(int i=0;s[i];i++)a[s[i]-'0']++;
	scanf("%s",s);for(int i=0;s[i];i++)b[s[i]-'0']++;
	bool fl=0,fl1=0;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=9;j++){
			int k=(i+10-j)%10;
			if(a[j]&&b[k]&&k){a[j]--,b[k]--,fl=1;if(i)putchar(i+'0'),fl1=1;break;}
		}
		if(fl)break;
	}
	for(int i=9;i>0;i--){
		for(int j=0;j<=9;j++){
			int k=(i+10-j)%10,w=min(a[j],b[k]);
			c[i]+=w,a[j]-=w,b[k]-=w;
		}
		while(c[i]--)fl1=1,putchar(i+'0');
	}
	int i=0;
	for(int j=0;j<=9;j++){
		int k=(i+10-j)%10;
		c[i]+=min(a[j],b[k]),a[j]-=min(a[j],b[k]),b[k]-=min(a[j],b[k]);
	}
	if(fl1)while(c[i]--)fl1=1,putchar(i+'0');
	else putchar('0');
	puts("");
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
