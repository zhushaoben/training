#include<bits/stdc++.h>
using namespace std;
char s[10][10]={"Monday","Tuesday","Wednesday","Thursday","Friday"},s1[10];
void work(){
	int a,b,c,d,e,f;long long dif=0,now;
	scanf("%d%d%d%s%d%d%d",&a,&b,&c,s1,&d,&e,&f);
	dif=360ll*(d-a)+30*(e-b)+(f-c);dif%=5;
	for(int i=0;i<5;i++)if(s1[0]==s[i][0]&&s1[1]==s[i][1])now=i;
	puts(s[(now+dif+5)%5]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
