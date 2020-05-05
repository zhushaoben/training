#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c,d,u,v,x1,y1,x2,y2;
	scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&u,&v,&x1,&y1,&x2,&y2);
	if(((x2-x1)==0&&(a|b))||((y2-y1)==0&&(c|d))||u-x1<a-b||x2-u<b-a||v-y1<c-d||y2-v<d-c)puts("No");
	else puts("Yes");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
