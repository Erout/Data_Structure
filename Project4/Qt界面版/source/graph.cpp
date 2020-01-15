#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
    for(int i = 0; i < SIZE; i++){
        city[i] = nullptr;
        city_mul[i] = nullptr;
        DFSTree[i] = nullptr;
        BFSTree[i] = nullptr;
    }
    model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("起点"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("终点"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,80);
    ui->tableView->setColumnWidth(1,80);
}

graph::~graph()
{
    delete ui;
    for(int i = 0; i < SIZE; i++){
        if(city[i] != nullptr)
            delete city[i];
        if(DFSTree[i] != nullptr)
            delete DFSTree[i];
        if(BFSTree[i] != nullptr)
            delete BFSTree[i];
        if(city_mul[i] != nullptr)
            delete city_mul[i];
        city_mul[i] = nullptr;
        city[i] = nullptr;
        DFSTree[i] = BFSTree[i] = nullptr;
    }
}
void graph::clearFormerBFS(){
    for(int i = 0; i < SIZE; i++){
        if(BFSTree[i] != nullptr){
            delete BFSTree[i];
            BFSTree[i] = nullptr;
        }
    }
}
void graph::clearFormerDFS(){
    for(int i = 0; i < SIZE; i++){
        if(DFSTree[i] != nullptr){
            delete DFSTree[i];
            DFSTree[i] = nullptr;
        }
    }
}
void graph::clearMark(){
    for(int i = 0; i < SIZE; i++){
        if(city[i] != nullptr)
            city[i]->mark = 0;
        if(city_mul[i] != nullptr)
            city_mul[i]->mark = 0;
    }
    model->clear();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("起点"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("终点"));
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,50);
}
void graph::setUpGraph(){
    //读城市号码对应的名称
    ifstream fname("city_and_number.txt");
    string tempName;
    int tempId;
    while(!fname.eof()){
        fname>>tempId;
        fname>>tempName;
        cityname[tempId] = tempName;
    }
    ifstream fin("city_connect.in");
    int a,b;
    while(!fin.eof()){
        fin>>a;
        fin>>b;
        //先建立邻接表
        AcityNode* tmpAdd;
        if(city[a] == nullptr){
            city[a] = new Acity(a,cityname[a]);
            city[a]->firstNode = new AcityNode(b,cityname[b]);
        }
        else{
            tmpAdd = city[a]->firstNode;
            while(tmpAdd->next != nullptr){
                tmpAdd = tmpAdd->next;
            }
            tmpAdd->next = new AcityNode(b,cityname[b]);
        }
        if(city[b] == nullptr){
            city[b] = new Acity(b,cityname[b]);
            city[b]->firstNode = new AcityNode(a,cityname[a]);
        }
        else{
            tmpAdd = city[b]->firstNode;
            while(tmpAdd->next != nullptr){
                tmpAdd = tmpAdd->next;
            }
            tmpAdd->next = new AcityNode(a,cityname[a]);
        }
        //cout<<"over for link list"<<endl;
        //再建立邻接多重表

        edge* tmp,*addEdge;
        bool add = 0;
        addEdge = new edge(a,b);
        if(city_mul[a] == nullptr){
            //cout<<"here a"<<endl;
            city_mul[a] = new headnode(a,cityname[a]);
            city_mul[a]->firstedge = addEdge;
        }
        else{
            add = 0;
            tmp = city_mul[a]->firstedge;
            while(!add){
                //cout<<tmp->ivex<<" "<<tmp->ilink<<" "<<tmp->jvex<<" "<<tmp->jlink<<endl;
                if(tmp->ivex == a){
                    if(tmp->ilink != nullptr){
                        tmp = tmp->ilink;
                    }
                    else{
                        tmp->ilink = addEdge;
                        add = 1;
                    }
                }
                else if(tmp->jvex == a){
                    if(tmp->jlink != nullptr)
                        tmp = tmp->jlink;
                    else{
                        tmp->jlink = addEdge;
                        add = 1;
                    }
                }
            }
        }
        if(city_mul[b] == nullptr){
            //cout<<"here b"<<endl;
            city_mul[b] = new headnode(b,cityname[b]);
            city_mul[b]->firstedge = addEdge;
        }
        else{
            add = 0;
            tmp = city_mul[b]->firstedge;
            while(!add){
                if(tmp->ivex == b){
                    if(tmp->ilink != nullptr)
                        tmp = tmp->ilink;
                    else{
                        tmp->ilink = addEdge;
                        add = 1;
                    }
                }
                else if(tmp->jvex == b){
                    if(tmp->jlink != nullptr)
                        tmp = tmp->jlink;
                    else{
                        tmp->jlink = addEdge;
                        add = 1;
                    }
                }
            }
        }
    }
}
//邻接多重表广度优先搜索,树也使用邻接表存储
void graph::BFS(int vertex){
    clearFormerBFS();
    clearMark();
    int visitOrder[SIZE];
    int order = 0;
    int edgeSet[SIZE*SIZE][2];
    int edgecount = 0;
    queue<headnode*> Q;
    Q.push(city_mul[vertex]);
    headnode* serach;
    edge* tempEdge;
    while(!Q.empty()){
        serach = Q.front();
        Q.pop();
        visitOrder[order++] = serach->id;
        serach->mark = 1;
        tempEdge = serach->firstedge;
        while(tempEdge != nullptr){
            if(tempEdge->ivex == serach->id){
                //若和正在遍历的点相连的节点未被遍历，那么则将它加到遍历队伍之中
                if(city_mul[tempEdge->jvex]->mark != 1){
                    city_mul[tempEdge->jvex]->mark = 1;
                    edgeSet[edgecount][0] = tempEdge->ivex;
                    edgeSet[edgecount][1] = tempEdge->jvex;
                    edgecount++;
                    addEdgeToTree(tempEdge->ivex,tempEdge->jvex,BFSTree);
                    Q.push(city_mul[tempEdge->jvex]);
                }
                tempEdge = tempEdge->ilink;
            }
            else if(tempEdge->jvex == serach->id){
                if(city_mul[tempEdge->ivex]->mark != 1){
                    city_mul[tempEdge->ivex]->mark = 1;
                    edgeSet[edgecount][0] = tempEdge->jvex;
                    edgeSet[edgecount][1] = tempEdge->ivex;
                    edgecount++;
                    addEdgeToTree(tempEdge->jvex,tempEdge->ivex,BFSTree);
                    Q.push(city_mul[tempEdge->ivex]);
                }
                tempEdge = tempEdge->jlink;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(BFSTree[i] == nullptr){
            BFSTree[i] = new Acity(i,cityname[i]);
        }
    }
    //cout<<"                             ";
    //cout<<"以下是节点访问序列"<<endl;
    QString vord;
    for(int i = 0; i < order; i++){
        //cout<<visitOrder[i]<<" ";
        vord += QString::number(visitOrder[i]);
        vord += QString::fromStdString(" ");
    }
    ui->textBrowser->setText(vord);
    //cout<<endl;
    //cout<<"                             ";
    //cout<<"以下是生成树的边集"<<endl;
    QString eord;
    int row = 0;
    for(int i = 0; i < edgecount; i++){
        //cout<<edgeSet[i][0]<<"->"<<edgeSet[i][1]<<" ,";
        model->setItem(row,0,new QStandardItem(QString::number(edgeSet[i][0])));
        model->setItem(row,1,new QStandardItem(QString::number(edgeSet[i][1])));
        row++;
    }

    //cout<<endl;
    //cout<<"                             ";
    //cout<<"以下是生成树"<<endl;
    mytree = "";
    RecursivePrintTree(vertex,0,BFSTree);
    ui->textBrowser_2->setText(mytree);
}
//树边，为有向边，存出边邻接表
void graph::addEdgeToTree(int a, int b, Acity* array[]){
    if(array[a] == nullptr){
        array[a] = new Acity(a,cityname[a]);
        array[a]->firstNode = new AcityNode(b,cityname[b]);
    }
    else{
        AcityNode* temp = array[a]->firstNode;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new AcityNode(b,cityname[b]);
    }
}
void graph::RecursivePrintTree(int pr, int offset,Acity* array[]){
    AcityNode* n;
    //QString mytree;
    n = array[pr]->firstNode;
    for(int i = 0; i < (offset-1)*5; i++){
        //cout<<" ";
        mytree += QString::fromStdString(" ");
    }
    if(offset){
        //cout<<'+';
        mytree += QString::fromStdString("+");
        for(int i = 0; i < 4; i++){
            //cout<<"-";
            mytree += QString::fromStdString("-");
        }
    }
    //cout<<array[pr]->id<<array[pr]->name<<endl;
    mytree += QString::number(array[pr]->id);
    mytree += QString::fromStdString(array[pr]->name);
    mytree += QString::fromStdString("\n");
    while(n != nullptr){
        RecursivePrintTree(n->id,offset+1,array);
        n = n->next;
    }
}
//邻接表广度优先搜索，树使用邻接表存储
void graph::BFS2(int vertex){
    clearFormerBFS();
    clearMark();
    int visitOrder[SIZE];
    int order = 0;
    int edgeSet[SIZE*SIZE][2];
    int edgecount = 0;
    queue<int> Q;
    Q.push(vertex);
    int serach;
    AcityNode* n;
    while(!Q.empty()){
        serach = Q.front();
        Q.pop();
        visitOrder[order++] = serach;
        city[serach]->mark = 1;
        n = city[serach]->firstNode;
        while(n != nullptr){
            if(city[n->id]->mark != 1){
                city[n->id]->mark = 1;
                Q.push(n->id);
                edgeSet[edgecount][0] = serach;
                edgeSet[edgecount][1] = n->id;
                edgecount++;
                addEdgeToTree(serach,n->id,BFSTree);
            }
            n = n->next;
        }
    }
    for(int i = 0; i < 26; i++){
        if(BFSTree[i] == nullptr){
            BFSTree[i] = new Acity(i,cityname[i]);
        }
    }
    QString vord;
    for(int i = 0; i < order; i++){
        //cout<<visitOrder[i]<<" ";
        vord += QString::number(visitOrder[i]);
        vord += QString::fromStdString(" ");
    }
    ui->textBrowser->setText(vord);
    //cout<<endl;
    //cout<<"                             ";
    //cout<<"以下是生成树的边集"<<endl;
    QString eord;
    int row = 0;
    for(int i = 0; i < edgecount; i++){
        //cout<<edgeSet[i][0]<<"->"<<edgeSet[i][1]<<" ,";
        model->setItem(row,0,new QStandardItem(QString::number(edgeSet[i][0])));
        model->setItem(row,1,new QStandardItem(QString::number(edgeSet[i][1])));
        row++;
    }
    //cout<<"以下是生成树"<<endl;
    mytree = "";
    RecursivePrintTree(vertex,0,BFSTree);
    ui->textBrowser_2->setText(mytree);
}
//邻接表DFS
void graph::recursiveVisit(int vertex){
    AcityNode* n;
    if(city[vertex]->mark != 2){
        city[vertex]->mark  = 2;
        n = city[vertex]->firstNode;
        while(n != nullptr){
            if(city[n->id]->mark != 2){
                addEdgeToTree(vertex,n->id,DFSTree);
                recursiveVisit(n->id);
            }
            n = n->next;
        }
    }
}
void graph::RecursiveDFS(int vertex){
    recursiveVisit(vertex);
    for(int i = 0; i < 26; i++){
        if(DFSTree[i] == nullptr){
            DFSTree[i] = new Acity(i,cityname[i]);
        }
    }
    RecursivePrintTree(vertex,0,DFSTree);
}
//邻接表的非递归DFS
void graph::nonRecursiveDFS2(int vertex){
    clearFormerDFS();
    clearMark();
    int visitOrder[SIZE];
    int order = 0;
    int edgeSet[SIZE*SIZE][2];
    int edgecount = 0;
    visitOrder[order++] = vertex;
    stack<int> S;
    S.push(vertex);
    int serach;
    AcityNode* n;
    while(!S.empty()){
        serach = S.top();
        city[serach]->mark = 3;
        n = city[serach]->firstNode;
        while(n != nullptr && city[n->id]->mark == 3){
            n = n->next;
        }
        if(n == nullptr){
            S.pop();
            continue;
        }
        else{
            visitOrder[order++] = n->id;
            edgeSet[edgecount][0] = serach;
            edgeSet[edgecount][1] = n->id;
            edgecount++;
            addEdgeToTree(serach,n->id,DFSTree);
            city[n->id]->mark = 3;
            S.push(n->id);
        }
    }
    for(int i = 0; i < 26; i++){
        if(DFSTree[i] == nullptr){
            DFSTree[i] = new Acity(i,cityname[i]);
        }
    }
    QString vord;
    for(int i = 0; i < order; i++){
        //cout<<visitOrder[i]<<" ";
        vord += QString::number(visitOrder[i]);
        vord += QString::fromStdString(" ");
    }
    ui->textBrowser->setText(vord);
    QString eord;
    int row = 0;
    for(int i = 0; i < edgecount; i++){
        //cout<<edgeSet[i][0]<<"->"<<edgeSet[i][1]<<" ,";
        model->setItem(row,0,new QStandardItem(QString::number(edgeSet[i][0])));
        model->setItem(row,1,new QStandardItem(QString::number(edgeSet[i][1])));
        row++;
    }
    mytree = " ";
    //cout<<"以下是生成树"<<endl;
    RecursivePrintTree(vertex,0,DFSTree);
    ui->textBrowser_2->setText(mytree);
}
void graph::nonRecursiveDFS(int vertex){
    clearFormerDFS();
    clearMark();
    int visitOrder[SIZE];
    int order = 0;
    int edgeSet[SIZE*SIZE][2];
    int edgecount = 0;
    stack<int> S;
    S.push(vertex);
    int serach;
    edge* e;
    bool findnext = 0;
    visitOrder[order++] = vertex;
    while(!S.empty()){
        serach = S.top();
        city_mul[serach]->mark = 3;
        e = city_mul[serach]->firstedge;
        findnext = 0;
        while(e != nullptr && !findnext){
            if(e->ivex == serach){
                if(city_mul[e->jvex]->mark != 3){
                    edgeSet[edgecount][0] = serach;
                    edgeSet[edgecount][1] = e->jvex;
                    edgecount++;
                    addEdgeToTree(serach,e->jvex,DFSTree);
                    city_mul[e->jvex]->mark = 3;
                    S.push(e->jvex);
                    visitOrder[order++] = e->jvex;
                    findnext = 1;
                }
                else
                    e = e->ilink;
            }
            else if(e->jvex == serach){
                if(city_mul[e->ivex]->mark != 3){
                    edgeSet[edgecount][0] = serach;
                    edgeSet[edgecount][1] = e->ivex;
                    edgecount++;
                    addEdgeToTree(serach,e->ivex,DFSTree);
                    city_mul[e->ivex]->mark = 3;
                    S.push(e->ivex);
                    visitOrder[order++] = e->ivex;
                    findnext = 1;
                }
                else
                    e = e->jlink;
            }
        }
        if(!findnext){
            S.pop();
        }
    }
    for(int i = 0; i < 26; i++){
        if(DFSTree[i] == nullptr){
            DFSTree[i]  = new Acity(i,cityname[i]);
        }
    }
    QString vord;
    for(int i = 0; i < order; i++){
        //cout<<visitOrder[i]<<" ";
        vord += QString::number(visitOrder[i]);
        vord += QString::fromStdString(" ");
    }
    ui->textBrowser->setText(vord);
    QString eord;
    int row = 0;
    for(int i = 0; i < edgecount; i++){
        //cout<<edgeSet[i][0]<<"->"<<edgeSet[i][1]<<" ,";
        model->setItem(row,0,new QStandardItem(QString::number(edgeSet[i][0])));
        model->setItem(row,1,new QStandardItem(QString::number(edgeSet[i][1])));
        row++;
    }
    mytree = "";
    RecursivePrintTree(vertex,0,DFSTree);
    ui->textBrowser_2->setText(mytree);
}
void graph::on_BFS_clicked(){
    int v = ui->spinBox->value();
    if(v <= 0 || v > 25){
        ui->textBrowser->setText(QString::fromStdString("Invalid input!"));
        ui->textBrowser_2->setText(QString::fromStdString(""));
        model->clear();
        model->setColumnCount(2);
        model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("起点"));
        model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("终点"));
        ui->tableView->setColumnWidth(0,100);
        ui->tableView->setColumnWidth(1,100);
    }
    else{
        BFS2(v);
    }
}
void graph::on_DFS_clicked(){
    int v = ui->spinBox->value();
    if(v <= 0 || v > 25){
        ui->textBrowser->setText(QString::fromStdString("Invalid input!"));
        ui->textBrowser_2->setText(QString::fromStdString(""));
        model->clear();
        model->setColumnCount(2);
        model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("起点"));
        model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("终点"));
        ui->tableView->setColumnWidth(0,100);
        ui->tableView->setColumnWidth(1,100);
    }
    else{
        nonRecursiveDFS2(v);
    }
}
void graph::on_BFSmul_clicked(){
    int v = ui->spinBox->value();
    if(v <= 0 || v >25){
        ui->textBrowser->setText(QString::fromStdString("Invalid input!"));
        ui->textBrowser_2->setText(QString::fromStdString(""));
        model->clear();
        model->setColumnCount(2);
        model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("起点"));
        model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("终点"));
        ui->tableView->setColumnWidth(0,100);
        ui->tableView->setColumnWidth(1,100);
    }
    else{
        BFS(v);
    }

}
void graph::on_DFSmul_clicked(){
    int v = ui->spinBox->value();
    if(v <= 0 || v > 25){
        ui->textBrowser->setText(QString::fromStdString("Invalid input!"));
        ui->textBrowser_2->setText(QString::fromStdString(""));
        model->clear();
        model->setColumnCount(2);
        model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("起点"));
        model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("终点"));
        ui->tableView->setColumnWidth(0,100);
        ui->tableView->setColumnWidth(1,100);
    }
    else{
        nonRecursiveDFS(v);
    }
}
