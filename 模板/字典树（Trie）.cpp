#define PACKAGE 1

#if PACKAGE
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct Trie{
	int tot,fa[N],tr[N][26];
	void insert(char s[]){
		int p=1;
		for(int i=0;s[i];i++){
			int x=s[i]-'a';
			if(!tr[p][x])tr[p][x]=++tot,fa[tot]=p;
			p=tr[p][x];
		}
	}
};
int main(){
	return 0;
}
#endif

#if !PACKAGE
#include<cstdio>
#include<cstring>
using namespace std;
struct Trie{
	Trie *son[26];
	bool w;//记录当前节点是否是单词；
	Trie(){
		memset(son,0,sizeof(son)),w=0;
	} 
}root;
int  sum,word;
void search(char s[]){//查找和插入 
	Trie *x=&root;
	for(int i=0;s[i];i++){
		if(x->son[s[i]-'A']==NULL){//判断之前是否出现过 
			x->son[s[i]-'A']=new Trie;//创建新的节点 
			sum++;//sum总结点数+1
		}
		x=x->son[s[i]-'A'];
	}
	if(!x->w)word,x->w=1;//word总单词数+1 
}
void node_free(Trie* x){//节点释放 
	for(int i=0;i<26;i++){
		if(x->son[i]!=NULL)node_free(x->son[i]);//先释放子节点 
	}
	delete x;
} 
void trie_free(){//空间释放 
	for(int i=0;i<26;i++){
		if(root.son[i]!=NULL)node_free(root.son[i]),root.son[i]=NULL;
	}
}
int main(){
	return 0;
}
#endif
