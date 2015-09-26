template <typename Tv, typename Te> //�����������BFS�㷨��ȫͼ��Breadth First Search
void Graph<Tv, Te>::bfs(int s) { //assert: 0 <= s < n
reset(); int clock = 0; int v = s; //�_ʼ��
do //��һ������ж���
if (UNDISCOVERED == status(v)) //һ�����b��δ���ְm����
BFS(v, clock); //����ڹ���������۽һ��BFS
while (s != (v = (++v % n))); //����ż�飬��آ©آ��
}
template <typename Tv, typename Te> //�����������BFS�㷨��������ͨ��
void Graph<Tv, Te>::BFS(int v, int& clock) { //assert: 0 <= v < n
Queue<int> Q; //���븨�Ӷ���
status(v) = DISCOVERED; Q.enqueue(v); //�_ʼ�����
while (!Q.empty()) { //��Q���ՁTǰ��آ��
int v = Q.dequeue(); dTime(v) = ++clock; //�������׶���v
for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //���Sv�m������ƨu
if (UNDISCOVERED == status(u)) { //��u��δ�����֣���
status(u) = DISCOVERED; Q.enqueue(u); //����ڹ����
status(v, u) = TREE; parent(u) = v; //����������չ֧����
} else { //��u�ѱ����֣�����������ڪ����ϣ���
status(v, u) = CROSS; //��(v, u)����ء���
}
status(v) = VISITED; //���ˣ���ǰ����ڪ�����
}
}