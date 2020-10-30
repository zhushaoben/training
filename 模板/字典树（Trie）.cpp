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
	bool w;//��¼��ǰ�ڵ��Ƿ��ǵ��ʣ�
	Trie(){
		memset(son,0,sizeof(son)),w=0;
	} 
}root;
int  sum,word;
void search(char s[]){//���ҺͲ��� 
	Trie *x=&root;
	for(int i=0;s[i];i++){
		if(x->son[s[i]-'A']==NULL){//�ж�֮ǰ�Ƿ���ֹ� 
			x->son[s[i]-'A']=new Trie;//�����µĽڵ� 
			sum++;//sum�ܽ����+1
		}
		x=x->son[s[i]-'A'];
	}
	if(!x->w)word,x->w=1;//word�ܵ�����+1 
}
void node_free(Trie* x){//�ڵ��ͷ� 
	for(int i=0;i<26;i++){
		if(x->son[i]!=NULL)node_free(x->son[i]);//���ͷ��ӽڵ� 
	}
	delete x;
} 
void trie_free(){//�ռ��ͷ� 
	for(int i=0;i<26;i++){
		if(root.son[i]!=NULL)node_free(root.son[i]),root.son[i]=NULL;
	}
}
int main(){
	return 0;
}
#endif
