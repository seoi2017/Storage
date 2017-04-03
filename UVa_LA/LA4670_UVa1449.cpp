#include<iostream>//Accepted!
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#define N 200
#define null_ptr -1
#define MCHR 26
#define MLEN 100
#define TLEN 1000100
#define M (MCHR*MLEN+10000)
using namespace std;
int n,top=0,maxc=0;
int queue[M],head=0,tail=0;
char mode[N][MLEN],text[TLEN];
int fail[M],nxt[M][MCHR],cnt[N],ent[M];
map<string,int> ms;
void clear(){
    ms.clear();
    memset(cnt,0,sizeof(cnt));
    //memset(nxt[0],null_ptr,sizeof(nxt[0]));
    for(int i=0;i<MCHR;i++)nxt[0][i]=null_ptr;
    head=tail=0;
    top=0;
    maxc=0;
}
void insert_trie(int root,int len,int number){
    int k=root,s=0,index;
    while(mode[number][s]){
        index=mode[number][s]-'a';
        if(nxt[k][index]==null_ptr){
            nxt[k][index]=++top;
            memset(nxt[top],null_ptr,sizeof(nxt[top]));
            ent[top]=0;
            fail[top]=null_ptr;
        }
        k=nxt[k][index];
        s++;
    }
    ent[k]=number;
    ms[(string)(mode[number])]=k;
}
void build_AC_Automata(int root){
    fail[root]=null_ptr;
    queue[++head]=root;
    while(head!=tail){
        int x=queue[++tail];
        int fail_ptr=null_ptr;
        for(int i=0;i<MCHR;i++){
            if(nxt[x][i]!=null_ptr){
                if(x==root){
                    fail[nxt[x][i]]=root;
                    queue[++head]=nxt[x][i];
                    continue;
                }
                fail_ptr=fail[x];
                while(fail_ptr!=null_ptr){
                    if(nxt[fail_ptr][i]!=null_ptr){
                        fail[nxt[x][i]]=nxt[fail_ptr][i];
                        break;
                    }
                    fail_ptr=fail[fail_ptr];
                }
                if(fail_ptr==null_ptr)fail[nxt[x][i]]=root;
                queue[++head]=nxt[x][i];
            }
        }
    }
}
void query(char str[],int len,int root){
    int k=root,s=0,index;
    while(str[s]){
        index=str[s]-'a';
        while((nxt[k][index]==null_ptr)&&(k!=root))k=fail[k];
        k=nxt[k][index];
        k=((k==null_ptr)?root:k);
        int x=k;
        while(x!=root){
            if(ent[x]!=0){
                cnt[ent[x]]++;
                maxc=max(maxc,cnt[ent[x]]);
            }
            x=fail[x];
        }
        s++;
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n)&&(n!=0)){
        clear();
        for(int i=1;i<=n;i++){
            scanf("%s",mode[i]);
            insert_trie(0,strlen(mode[i]),i);
        }
        build_AC_Automata(0);
        scanf("%s",text);
        query(text,strlen(text),0);
        printf("%d\n",maxc);
        for(int i=1;i<=n;i++){
            if(cnt[ent[ms[(string)(mode[i])]]]==maxc)printf("%s\n",mode[i]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}