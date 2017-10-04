#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define MX 33
using namespace std;
struct file_t{
    string name;
    int sons;
    file_t *son[MX];
    file_t(string name){
        this->name=name;
        this->sons=0;
    }
}root("ROOT");
inline void input(){
    string now;
    char temp;
    bool canfind=false;
    file_t *n=&root;
    while(scanf("%c",&temp)){
        now.clear(),now+=temp;
        while(
            scanf("%c",&temp)\
             && temp!='/' \
             && temp!='\n'\
             )now+=temp;
        if(now=="0")break;
        if(temp=='\n'){//file
            for(int i=1;i<=n->sons;i++){
                if(n->son[i]->name==now && n->son[i]->sons==0){
                    n=n->son[i];
                    canfind=true;
                    break;
                }
            }
            if(!canfind){
                n->son[++n->sons]=new file_t(now);
                n=n->son[n->sons];
            }
            canfind=false;
            n=&root;
        }
        else{//folder
            for(int i=1;i<=n->sons;i++){
                if(n->son[i]->name==now && n->son[i]->sons!=0){
                    n=n->son[i];
                    canfind=true;
                    break;
                }
            }
            if(!canfind){
                n->son[++n->sons]=new file_t(now);
                n=n->son[n->sons];
            }
            canfind=false;
        }
    }
}
inline bool cmp(file_t *x,file_t *y){
    if(x->sons==0 && y->sons!=0)return false;
    if(x->sons!=0 && y->sons==0)return true;
    return x->name<y->name;
}
void solve(file_t *n,int deep){
    for(int i=1;i<=deep;i++)printf("    ");
    cout<<(n->name)<<endl;
    sort(n->son+1,n->son+1+n->sons,cmp);
    for(int i=1;i<=n->sons;i++){
        solve(n->son[i],deep+1);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    file_t *n=&root;
    sort(n->son+1,n->son+1+n->sons,cmp);
    for(int i=1;i<=n->sons;i++){
        solve(n->son[i],0);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}