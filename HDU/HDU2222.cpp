//HDU2222
//2017/3/1 20:37
//Powered by Inv.
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX_CHARS 26//最大字符集
#define MAX_STRINGS 256//最大字符串数量
#define MAX_LENGTH 256//最大字符串长度
struct ACNode{//AC自动机节点结构体
    ACNode* fail;//失配指针
    ACNode* next[MAX_CHARS];//子节点指针
    int ID;//唯一节点编号
    int end;//终止节点代表的模式串编号，为0则不是终止节点
    int count;//重复的相同模式串数量
    ACNode(int ID=0){//初始化构造函数
        this->ID=ID;
        this->fail=NULL;
        this->end=0;
        this->count=0;
        memset(this->next,NULL,sizeof(this->next));
    }
};
int top=0,tot=0,vis[1213313];//top是节点数量，tot是模式串数量，vis是节点是否已访问数组
char modes[MAX_STRINGS+1][MAX_LENGTH];//模式串存储数组
void insert_trie(char str[],ACNode* root,int number){//将模式串插入trie树，number是模式串编号
    ACNode* k=root;//迭代指针，指向根节点
    int s=0,index;//s是字符位数指针，index是字符集下标指针
    while(str[s]){//如果有字符
        index=str[s]-'a';//取整形字符下标
        if(k->next[index]==NULL){//如果当前节点子节点中无想要插入的节点
            k->next[index]=new ACNode(++top);//新建节点，节点数量++
        }
        k=k->next[index];//迭代到下一层
        s++;//字符位数指针+1，指向下一个字符
    }
    k->count++;//迭代完成，k已指向最末节点，使其count++，表示该模式串出现过了一次，若同一模式串多次出现，则count不止为1
    k->end=number;//k为该模板串的最末节点，故打上模板串编号，便于输出
}
void build_AC_Automata(ACNode* root){//构建AC自动机
    root->fail=NULL;//根节点无失配指针
    queue<ACNode*> Q;//队列，对Trie树按BFS序搜索构建Trie图
    Q.push(root);//将根节点插入队列
    while(!Q.empty()){//如果队列中还有元素
        ACNode* temp=Q.front();//当前操作节点，取队列首元素
        Q.pop();//弹出队列
        ACNode* fail_ptr=NULL;//临时失配指针
        for(int i=0;i<MAX_CHARS;i++){//依照字符集遍历子节点
            if(temp->next[i]!=NULL){//如果该字符子节点不为空
                if(temp==root){//如果当前节点是根节点
                    temp->next[i]->fail=root;//根节点的所有子节点的失配指针都指向根节点
                }
                else{//如果当前节点不是根节点
                    fail_ptr=temp->fail;//临时失配指针指向当前操作节点的失配指针，开始寻找失配指针
                    while(fail_ptr!=NULL){//如果临时失配指针不为空
                        if(fail_ptr->next[i]!=NULL){//如果临时失配指针指向节点的相同字符子节点不为空
                            temp->next[i]->fail=fail_ptr->next[i];//找到最终失配指针
                            break;//结束寻找失配指针
                        }
                        fail_ptr=fail_ptr->fail;//继续迭代，寻找失配指针
                    }
                    if(fail_ptr==NULL){//如果临时失配指针为空，则找到了根节点，因为只有根节点的失配指针为空
                        temp->next[i]->fail=root;//将失配指针指向根节点
                    }
                }
                Q.push(temp->next[i]);//将下一个节点压入队列
            }
        }
    }
}
int query(ACNode* root,char str[]){//查询目标串
    int len=strlen(str);//取目标串长度
    ACNode* k=root;//建立迭代指针，指向根节点
    int cnt=0,s=0,index;//cnt是已匹配的模式串数，s是字符位数指针，index是字符集下标指针
    while(str[s]){//如果有字符
        index=str[s]-'a';//取整形字符下标
        while((k->next[index]==NULL)&&(k!=root))k=k->fail;//如果向下失配，则沿失配指针迭代直至可以继续向下匹配
        k=k->next[index];//向下迭代一层
        k=((k==NULL)?root:k);//若为空，说明迭代到了根节点的失配指针，直接指向根节点
        ACNode* temp=k;//取当前操作节点，访问所有相同字符的节点，看是否找到了匹配
        while((temp!=root)&&(vis[temp->ID]!=1)){//如果节点未访问且不在根节点
            if(temp->end!=0){//若有匹配
                //printf("String has been found:%s*%d\n",modes[temp->end],temp->count);//输出匹配以及重复数量
                cnt+=temp->count;//总匹配数增加
            }
            vis[temp->ID]=1;//标记为已访问
            temp=temp->fail;//检索下一个同字符节点
        }
        s++;//字符位数加1
    }
    return cnt;//返回总匹配数
}
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        ACNode* root=new ACNode(0);//新建根节点
        //memset(vis,0,sizeof(vis));//清空访问数组
        for(int i=0;i<=1211312;i++){
            vis[i]=0;
        }
        scanf("%d",&tot);//读入模式串数
        for(int i=1;i<=tot;i++){
           scanf("%s",modes[i]);//读入模式串
           insert_trie(modes[i],root,i);//插入到字典树
        }
        build_AC_Automata(root);//构建AC自动机
        char str[1000100];//目标串
        scanf("%s",str);//读入目标串
        printf("%d\n",query(root,str));//查询匹配并输出
    }
    system("pause");
    return 0;
}