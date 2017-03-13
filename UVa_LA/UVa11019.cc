#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXCHAR 26
#define no -1
using namespace std;
int n,m,a,b;
int top=0;
int queue[111000],head=0,tail=0;
int fail[111000],nxt[111000][MAXCHAR],ent[111000];
char text[1010][1010];
char mode[110][110];
int cnt[1010][1010],nrt[110];
void insert_trie(char str[],int root,int number){
    int k=root;
    int s=0,index;
    while(str[s]!='\0'){
        index=str[s]-'a';
        if(nxt[k][index]==no){
            nxt[k][index]=++top;
            for(int i=0;i<MAXCHAR;i++)nxt[top][i]=-1;
            //memset(nxt[top],-1,sizeof(nxt[top]));
        }
        k=nxt[k][index];
        //===
        fail[k]=-1;
        ent[k]=0;
        //===
        s++;
    }
    ent[k]=number;
}
void build_AC_Automata(int root){
    fail[root]=-1;
    queue[++head]=root;
    //queue<int> Q;
    //Q.push(root);
    while(head!=tail/*!Q.empty()*/){
        int temp=queue[++tail];
        //int temp=Q.front();
        //Q.pop();
        int fail_ptr=no;
        for(int i=0;i<MAXCHAR;i++){
            if(nxt[temp][i]!=no){
                if(temp==root){
                    fail[nxt[temp][i]]=root;
                }
                else{
                    fail_ptr=fail[temp];
                    while(fail_ptr!=no){
                        if(nxt[fail_ptr][i]!=no){
                            fail[nxt[temp][i]]=nxt[fail_ptr][i];
                            break;
                        }
                        fail_ptr=fail[fail_ptr];
                    }
                    if(fail_ptr==no){
                        fail[nxt[temp][i]]=root;
                    }
                }
                queue[++head]=nxt[temp][i];
                //Q.push(nxt[temp][i]);
            }
        }
    }
}
void query(int root,char str[],int line){
    int k=root;
    int s=0,index;
    while(str[s]){
        index=str[s]-'a';
        while((nxt[k][index]==no)&&(k!=root))k=fail[k];
        k=nxt[k][index];
        k=((k==no)?root:k);
        int temp=k;
        while(temp!=root){
            if(ent[temp]!=0){
                if((line-(ent[temp]-1))>0)cnt[line-(ent[temp]-1)][s-strlen(mode[ent[temp]]-1)]++;
                //else printf("Overflow!\n");
                for(int i=nrt[ent[temp]];i!=0;i=nrt[i]){
                   if((line-(i-1))>0)cnt[line-(i-1)][s-strlen(mode[ent[temp]]-1)]++;
                   //else printf("Overflow!\n");
                }
            }
            temp=fail[temp];
        }
        s++;
    }
}
void clear(){
    top=0;
    for(int i=0;i<MAXCHAR;i++)nxt[0][i]=-1;
    //memset(nxt[0],-1,sizeof(nxt[0]));
    //memset(nrt,0,sizeof(nrt));
    n=m=a=b=0;
    head=tail=0;
}
void input(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        //memset(cnt[i],0,sizeof(cnt[i]));
        for(int j=0;j<m;j++)cnt[i][j]=0;
        scanf("%s",text[i]);
    }
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++){
        scanf("%s",mode[i]);
        nrt[i]=0;
        int only=true;
        for(int j=i-1;j>=1;j--){
            if(strcmp(mode[i],mode[j])==0){
                nrt[j]=i;
                only=false;
                break;
            }
        }
        if(only)insert_trie(mode[i],0,i);
    }
    build_AC_Automata(0);
}
void solve(){
    for(int i=1;i<=n;i++){
        query(0,text[i],i);
    }
    /*
    for(int i=1;i<=a;i++){
        printf("[%d]\n",nrt[i]);
    }
    */
    int ans=0;
    for(int i=1;i<=n;i++/*,printf("\n")*/){
        for(int j=0;j<m;j++){
            //printf("%d ",cnt[i][j]);
            if(cnt[i][j]==a)ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        clear();
        input();
        //debug(); 
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}