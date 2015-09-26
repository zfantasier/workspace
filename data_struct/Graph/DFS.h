template <typename Tv, typename Te> //�����������DFS�㷨��ȫͼ��Depth-First-Search
void Graph<Tv, Te>::dfs(int s) { //assert: 0 <= s < n
reset(); int clock = 0; int v = s; //�_ʼ��
do //��һ������ж���
if (UNDISCOVERED == status(v)) //һ�����b��δ���ְm����
DFS(v, clock); //����ڹ���������۽һ��DFS
while (s != (v = (++v % n))); //����ż�飬��آ©آ��
}
template <typename Tv, typename Te> //�����������DFS�㷨��������ͨ��
void Graph<Tv, Te>::DFS(int v, int& clock) { //assert: 0 <= v < n
dTime(v) = ++clock; status(v) = DISCOVERED; //������ǰ����v
for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //���Sv�m������ƨu
switch (status(u)) { //�Թ���״̬��ɾ����
case UNDISCOVERED: //u��δ���֣���ζ��֧�������ڴ���չ
status(v, u) = TREE; parent(u) = v; DFS(u, clock); break;
case DISCOVERED: //u�ѱ����ֵ���δڪ����ϣ�Ӧ�������ָ��m����
status(v, u) = BACKWARD; break;
default: //u��ڪ����ϣ�VISITED������ͼ��������Ϯ��ϵ��Ϊǰ��߽���
status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;
}
status(v) = VISITED; fTime(v) = ++clock; //���ˣ���ǰ����v�ڸ�ڪ�����
}