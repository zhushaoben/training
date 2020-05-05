#include<bits/stdc++.h>
using namespace std;
int num[11];char s[10];
int main(){
	int n,x,w,w1;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%d",s,&x);
		if(s[0]=='a'){
			for(w=0;(1<<w)<x;w++);
			w1=-1;for(int i=w;i<11;i++)if(num[i]){w1=i;break;}
			if(w1==-1){puts("ERROR!");continue;}
			num[w1]--,w=(1<<w1)-x;
			for(int i=0;i<11;i++)if(w&(1<<i))num[i]++;
			for(int i=0;i<11;i++)printf("%d ",num[i]);
			puts("");
		}
		else{
			for(int i=0;i<11;i++)if(x&(1<<i))num[i]++;
			for(int i=0;i<11;i++)printf("%d ",num[i]);
			puts("");
		}
	}
	return 0;
} 
