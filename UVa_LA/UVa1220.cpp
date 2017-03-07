#include<iostream>//Accepted
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
const int N=210;
int f[N][2],n,ans=0;
bool only[N][2];
struct per_t{
    vector<int> son;
    string name;
    void clear(){
        son.clear();
        name="";
    }
}p[N];
map<string,int> person;
int input(){
    string fa[N];
    cin>>n;
    if(n==0)return 0;
    cin>>p[1].name;
    person.insert(map<string,int>::value_type(p[1].name,1));
    for(int i=2;i<=n;i++){
        cin>>p[i].name;
        person.insert(map<string,int>::value_type(p[i].name,i));
        cin>>fa[i]; 
    }
    for(int i=2;i<=n;i++){
        p[person[fa[i]]].son.push_back(i);
    }
    //=======
    //for(int i=1;i<=n;i++,cout<<endl){
    //    if(p[i].son.size()==0)cout<<"0";
    //    for(int j=0;j<p[i].son.size();j++){
    //        cout<<p[i].son[j]<<" ";
    //    }
    //}cout<<"========================="<<endl;
    //=======
    return 1;
}
void clear(){
    ans=0;
    for(int i=0;i<N;i++){
        only[i][0]=only[i][1]=true;
        f[i][0]=f[i][1]=0;
        p[i].clear();
    }
    person.clear();
}
void dfs_dp(int x){
    f[x][0]=0;
    f[x][1]=1;
    for(int i=0;i<p[x].son.size();i++){
        dfs_dp(p[x].son[i]);
        int temp=max(f[p[x].son[i]][0],f[p[x].son[i]][1]);
        f[x][0]+=temp;
        if(f[p[x].son[i]][0]==f[p[x].son[i]][1])only[x][0]=false;
        else if(temp==f[p[x].son[i]][0] && only[p[x].son[i]][0]==false)only[x][0]=false;
        else if(temp==f[p[x].son[i]][1] && only[p[x].son[i]][1]==false)only[x][0]=false;
        f[x][1]+=f[p[x].son[i]][0];
        if(only[p[x].son[i]][0]==false)only[x][1]=false;
    }
    //printf("[%d:%d|%d]",x,f[x][0],f[0][1]);
}
void work(){
    dfs_dp(1);
    int choice=-1;
    if(max(f[1][1],f[1][0])==f[1][1])choice=1,printf("%d ",f[1][1]);
    else choice=0,printf("%d ",f[1][0]);
    f[1][0]==f[1][1]?printf("No\n"):only[1][choice]?printf("Yes\n"):printf("No\n");
}
int main(){
    ios::sync_with_stdio(false);
    freopen("output.txt","w",stdout);
    clear();
    while(input()){
        work();
        clear();
    }
    return 0;
}