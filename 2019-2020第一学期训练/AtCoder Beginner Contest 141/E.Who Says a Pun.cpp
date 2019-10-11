#include<bits/stdc++.h>
using namespace std;
#define maxn 5000
#define maxs maxn*2
struct SAM{
	int len,link,nex[26];
	SAM(){memset(this,0,sizeof(*this));}
}a[maxs+10];
int si,last;
void init(){
	si=last=1;
	memset(a,1,sizeof(SAM));a[1].link=-1;
}
void insert(int c){
	int now=++si,p=last;a[now]=a[0];last=now;
	a[now].len=a[last].len;
	while(p!=-1&&!a[p].nex[c]){
		a[p].nex[c]=now;
		p=a[p].link;
	}
	if(p==-1)a[now].link=1;
	else{
		int q=a[p].nex[c];
		if(a[q].len==a[p].len)a[now].link=q;
		else{
			int clone=++si;a[clone]=a[q];
			a[clone].len=a[p].len+1;
			a[last].link=a[p].link=clone;
			while(p!=-1&&a[p].nex[c]==q){
				a[p].nex[c]=clone;p=a[p].link;
			}
		}
	}
}
int main(){
	return 0;
} 
