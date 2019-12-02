#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
struct Tire{
	Tire *son[26],*fail;
	int sum;
	Tire(){
		memset(this,0,sizeof(Tire));
	}
}*root,*que[maxn];
void insert(char *s){//字典树插入字符串 
	Tire *x=root;
	for(int i=0;s[i];i++){
		int w=s[i]-'a';
		if(!x->son[w])x->son[w]=new Tire;
		x=x->son[w];
	}
	x->sum++;
}
int s,t;
void build(){//失配指针构造，类似于bfs 
	s=t=0;que[t++]=root;
	while(s<t){
		Tire *x=que[s++],*y;
		for(int i=0;i<26;i++){
			if(x->son[i]){
				que[t++]=x->son[i];
				if(x==root){
					x->son[i]->fail=root;
				}
				else{
					y=x->fail;
					while(y){
						if(y->son[i]){
							x->son[i]->fail=y->son[i];
							break;
						}
						y=y->fail;
					}
					if(!y)x->son[i]->fail=root;
				}
			}
		} 
	}
}
int find(char *s){//匹配函数，返回有多少匹配串出现过 
	Tire *x=root,*y;int ans=0;
	for(int i=0;s[i];i++){
		int k=s[i]-'a';
		while(!x->son[k]&&x!=root)x=x->fail;
		x=x->son[k];
		if(!x)x=root;
		y=x;
		while(y!=root){
			if(~y->sum){
				ans+=y->sum;
				y->sum=-1;
			}
			else break;
			y=y->fail;
		}
	}
	return ans;
}
void del(Tire *x){//释放空间 
	for(int i=0;i<26;i++){
		if(x->son[i])del(x->son[i]);
	}
	delete x;
}
int main(){
	return 0;
}
