# Project4 图的遍历
## 存储结构
- edge：邻接多重表的边
- headnode：邻接多重表的头节点
- AcityNode：邻接表的节点
- Acity：邻接表的头节点
图使用两种存储结构，邻接多重表和邻接表，Acity* city[SIZE]存储的是图的邻接表的各个头节点， headnode* city_mul[SIZE]存储的是图的邻接多重表的各个头节点。
生成的树使用邻接表存储，是出边邻接表，DFSTree存深度优先搜索的结果，BFS存广度优先搜索的结果。
## 主要函数及其功能
- setUpGraph():从文件中读入城市的名称及其对应编号，以及它们之间的连接情况，建立图的邻接表和邻接多重表存储结构。
- clearFormerBFS():清除BFSTree中的内容，以准备建立新的BFSTree
- clearFormerDFS()：清除DFSTree中的内容，以准备建立新的DFSTree
- clearMark()：初始化city和city_mul里的标记，在图遍历开始时的一个初始化。
- nonRecursiveDFS(int vertex)：利用栈实现非递归DFS，在邻接表多重表上进行DFS
- nonRecursiveDFS2(int vertex)：利用栈实现非递归DFS，在邻接表上进行DFS
- BFS(int vertex)：在邻接多重表上进行BFS
- BFS2(int vertex)：在邻接表上进行BFS
- RecursiveDFS(int vertex)：递归DFS
- recursiveVisit(int vertex)：辅助递归DFs
- addEdgeToTree(int a,int b, Acity* array[]):将有向边a->b加到树上。辅助DFS和BFS中树的建立
- RecursivePrintTree(int pr, int offset, Acity* array[]):用递归方法将树以目录结构打印出来