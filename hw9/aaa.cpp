#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
 
using namespace std;
const int N = 9;
const int MAXN = 1e6+10;
int vis[2][MAXN],a[N],pre[2][MAXN]; //vis标记走过的结点，pre记录前置路径
char ss[N],path[2][MAXN]; //path记录路径方向
int dx[2][4] = {-1,1,0,0, 0,0,1,-1};
int dy[2][4] = {0,0,-1,1, 1,-1,0,0};
char op[2][4] = { 'u','d','l','r', 'l','r','u','d' };//方向符号
 
//int dir[2][4][2] = { -1,0, 1,0, 0,-1, 0,1,   0,1, 0,-1, 1,0, -1,0};  //正方向
//char op[2][4] = {'u', 'd', 'l', 'r' ,   'l', 'r', 'u', 'd'  };
 
struct Node
{
    int loc,//记录x在序列中的位置
    id,//记录是正向还是反向
    stu,//记录这个序列的康拓展开编号
    a[N];//记录数组
};
queue <Node> q;
int cantor(int aa[]) //康托展开
{
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        int res = 0,m = 1,c = 1;
        for(int j=i+1;j<N;j++)
        {
            if(aa[j] < aa[i]) res++;
            m*=c; c++;
        }
        ans += res*m;
    }
    return ans+1;
}
 
int bfs() //双向bfs
{
    //初始化
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    Node t1,t2;
    for(int i=0;i<9;i++){
        t1.a[i] = a[i];
        if(a[i] == 9) t1.loc = i;
    }
    t1.id = 0;//0表示正向记录路径
    t1.stu = cantor(t1.a);
    vis[t1.id][t1.stu] = 1;
    pre[t1.id][t1.stu] = -1;
    q.push(t1);
 
    t1.id = 1;//1表示方向寻找路径
    for(int i=0;i<9;i++) t1.a[i] = i+1;
    t1.loc = 8;
    t1.stu = cantor(t1.a);
    vis[t1.id][t1.stu] = 1;
    pre[t1.id][t1.stu] = -1;
    q.push(t1);
    while(!q.empty())
    {
        //cout<<12<<endl;
        t1 = q.front();q.pop();
        int x = t1.loc/3,y = t1.loc%3,id = t1.id;
        if(vis[id^1][t1.stu]) //如果发现正向与反向路径相交就返回返回状态就好了
            return t1.stu;
        for(int i=0;i<4;i++)
        {
            int tx = x + dx[id][i];
            int ty = y + dy[id][i];
            if(0<=tx&&tx<3 && 0<=ty&&ty<3)
            {
                t2.id = t1.id;
                for(int j=0;j<N;j++) t2.a[j] = t1.a[j];
                t2.a[x*3+y] = t2.a[tx*3+ty];
                t2.a[tx*3+ty] = 9;
                t2.loc = tx*3+ty;//记录新出现的位置
                t2.stu = cantor(t2.a);
                if(!vis[id][t2.stu])
                {
                    vis[id][t2.stu] = 1;
                    pre[id][t2.stu] = t1.stu;
                    path[id][t2.stu] = op[id][i]; //替换新的方向符号
                    q.push(t2);
                }
            }
        }
    }
    return -1;
}
void pt1(int stu) //因为是正向路径，所以要后序遍历
{
    if(pre[0][stu] == -1) return ;//当下一个没有就返回
    pt1(pre[0][stu]);
    printf("%c",path[0][stu]);
}
void pt2(int stu) //因为是反向路径，所以要前序遍历
{
    if(pre[1][stu] == -1) return ;
    printf("%c",path[1][stu]);
    pt2(pre[1][stu]);
}
int main(void)
{
    for(int i=0;i<9;i++)
    {
        scanf("%s",ss);
        if(ss[0] == 'x') a[i] = 9;
        else a[i] = ss[0] - '0';
    }
    int tp = bfs();
    if(tp == -1) printf("unsolvable\n"); //不存在这样的情况。
    else{
        pt1(tp); pt2(tp);
        puts("");
    }
    return 0;
}
