#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXNODE 110
#define MAXCHAR 26
#define num(x) (x-'a')
#define ms(x,y) memset(x,y,sizeof(x))
#define no -1
using namespace std;
int n,m,a,b;
int top=0;
int fail[MAXNODE*MAXNODE],nxt[MAXNODE*MAXNODE][MAXCHAR],end[MAXNODE*MAXNODE];
char text[MAXNODE*10][MAXNODE*10];
char mode[MAXNODE][MAXNODE];
int cnt[MAXNODE*10][MAXNODE*10],nrt[MAXNODE];
void insert_trie(char str[],int root,int number){
    int k=root;
    int s=0,index;
    while(str[s]){
        index=num(str[s]);
        if(nxt[k][index]==no){
            nxt[k][index]=++top;
        }
        k=nxt[k][index];
        //===
        fail[k]=-1;
        end[k]=0;
        //===
        s++;
    }
    end[k]=number;
}
void build_AC_Automata(int root){
    fail[root]=-1;
    int queue[MAXNODE],head=0,tail=0;
    queue[++head]=root;
    while(head!=tail){
        int temp=queue[++tail];
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
            }
        }
    }
}
void query(int root,char str[],int line){
    int len=strlen(str);
    int k=root;
    int s=0,index;
    while(str[s]){
        index=num(str[s]);
        while((nxt[k][index]==no)&&(k!=root))k=fail[k];
        k=nxt[k][index];
        k=((k==no)?root:k);
        int temp=k;
        while((temp!=root)/*&&(vis[temp]==false)*/){
            if(end[temp]!=0){
                cnt[line-(end[temp]-1)][s-strlen(mode[end[temp]]-1)]++;
                for(int i=nrt[temp];i!=0;i=nrt[i]){
                   cnt[line-(end[i]-1)][s-strlen(mode[end[i]]-1)]++; 
                }
            }
            //vis[temp]=true;
            temp=fail[temp];
        }
        s++;
    }
}
inline void clear(){
    top=0;
    ms(nxt,-1);
    ms(cnt,0);
    ms(nrt,0);
    n=m=a=b=0;
}
inline void input(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",text[i]);
    }
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++){
        scanf("%s",mode[i]);
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
inline void solve(){
    for(int i=1;i<=n;i++){
        query(0,text[i],i);
    }
    
    for(int i=1;i<=a;i++){
        printf("[%d]\n",nrt[i]);
    }
    
    register int ans=0;
    for(int i=0;i<=n;i++,printf("\n")){
        for(int j=0;j<=m;j++){
            printf("%d ",cnt[i][j]);
            if(cnt[i][j]==a)ans++;
        }
    }
    printf("%d\n",ans);
}
void debug(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",mode[i]);
        insert_trie(mode[i],0,i);
    }
    build_AC_Automata(0);
    scanf("%s",text[1]);
    query(0,text[1],0);
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