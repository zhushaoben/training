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
