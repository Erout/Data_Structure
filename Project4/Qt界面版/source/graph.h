#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<fstream>
#include<queue>
#include<stack>
#define SIZE 35
using std::queue;
using std::stack;
using std::string;
using std::ifstream;
struct edge
{
    int ivex,jvex;
    edge* ilink, *jlink;
    int mark;
    edge(int i, int j){
        ivex = i;
        jvex = j;
        mark = 0;
        ilink = jlink = nullptr;
    }
};
struct headnode
{
    int id;
    string name;
    edge* firstedge;
    int mark;
    headnode(int id_,string name_){
        id = id_;
        name = name_;
        firstedge = nullptr;
        mark = 0;
    }
};
struct AcityNode
{
    int id;
    string name;
    AcityNode* next;
    AcityNode(int id_,string name_){
        id = id_;
        name = name_;
        next = nullptr;
    }
};
struct Acity
{
    int id;
    int mark;
    string name;
    AcityNode* firstNode;
    Acity(int id_,string name_){
        id = id_;
        name = name_;
        firstNode = nullptr;
        mark = 0;
    }
};
namespace Ui {
class graph;
}

class graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();
    void setUpGraph();//生成两种储存方式的树，通过读取文件
    void clearFormerBFS();
    void clearFormerDFS();
    void clearMark();
    void nonRecursiveDFS(int vertex);
    void nonRecursiveDFS2(int vertex);
    void BFS(int vertex);
    void BFS2(int vertex);
    void addEdgeToTree(int a,int b, Acity* array[]);
    void RecursivePrintTree(int pr, int offset,Acity* array[]);
    void RecursiveDFS(int vertex);
    void recursiveVisit(int vertex);
private slots:
    void on_BFS_clicked();
    void on_DFS_clicked();
    void on_BFSmul_clicked();
    void on_DFSmul_clicked();
private:
    Ui::graph *ui;
    Acity* city[SIZE];//第三题的邻接表
    headnode* city_mul[SIZE];//第一题的邻接多重表
    Acity* DFSTree[SIZE];//深度优先生成树
    Acity* BFSTree[SIZE];//广度优先生成树
    string cityname[SIZE];
    QStandardItemModel* model;
    QString mytree;
};

#endif // GRAPH_H
