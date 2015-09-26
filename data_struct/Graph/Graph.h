typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //����״̬
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EStatus; //��״̬

template <typename Tv, typename Te> //�������͡�������
class Graph { //ͼGraphģ����
private:
		void reset() { //���ж��㡢�߰m������Ϣ��λ
			for (int i = 0; i < n; i++) { //���ж���m
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1; //״̬��ʱ���ǩ
			parent(i) = -1; priority(i) = INT_MAX; //���ڱ������аm�����ڵ㣬���ȼ���
			for (int j = 0; j < n; j++) //���б߰m
			if (exists(i, j)) status(i, j) = UNDETERMINED; //״̬
			}
		}
		void BFS(int, int&); //����ͨ�򣩹�����������㷨
		void DFS(int, int&); //����ͨ��������������㷨
		void BCC(int, int&, Stack<int>&); //����ͨ�򣩻�ءDFS�m˫��ͨ�����ֽ��㷨
		bool TSort(int, int&, Stack<Tv>*); //����ͨ�򣩻�ءDFS�m���������㷨
		template <typename PU> void PFS(int, PU); //����ͨ�����ȼ��������
public:
// ����
		int n; //��������
		virtual int insert(Tv const&) = 0; //�I�붥�㣬ކ�ر��
		virtual Tv remove(int) = 0; //�������㼰������ߣ�ކ��ڹ������Ϣ
		virtual Tv& vertex(int) = 0; //����v�m���ݣ�ڹ����mȷ���ڣ�
		virtual int inDegree(int) = 0; //����v�m��ȣ�ڹ����mȷ���ڣ�
		virtual int outDegree(int) = 0; //����v�m���ȣ�ڹ����mȷ���ڣ�
		virtual int firstNbr(int) = 0; //����v�m�׸��ڽӶ���
		virtual int nextNbr(int, int) = 0; //����v�m�����ء����j�m����һ�ڽӶ���
		virtual VStatus& status(int) = 0; //����v�m״̬
		virtual int& dTime(int) = 0; //����v�mʱ���ǩdTime
		virtual int& fTime(int) = 0; //����v�mʱ���ǩfTime
		virtual int& parent(int) = 0; //����v�ڱ������аm����
		virtual int& priority(int) = 0; //����v�ڱ������аm���ȼ���
// �ߣ�����Լ��������߾�ͳһת��Ϊ������mһ������ߣ��Ӷ�������ͼ��������ͼ�m����
		int e; //������
		virtual bool exists(int, int) = 0; //��(v, u)�Ƿ����
		virtual void insert(Te const&, int, int, int) = 0; //�ڶ���v��u�T��I��Ȩ��Ϊw�m��e
		virtual Te remove(int, int) = 0; //��������v��u�T��m��e��ކ��ڹ����Ϣ
		virtual EStatus& status(int, int) = 0; //��(v, u)�m״̬
		virtual Te& edge(int, int) = 0; //��(v, u)�m���ݣ�ڹ�߰mȷ���ڣ�
		virtual int& weight(int, int) = 0; //��(v, u)�mȨ��
// �㷨
		void bfs(int); //������������㷨
		void dfs(int); //������������㷨
		void bcc(int); //��ءDFS�m˫��ͨ�����ֽ��㷨
		Stack<Tv>* tSort(int); //��ءDFS�m���������㷨
		void prim(int); //��С֧����Prim�㷨
		void dijkstra(int); //���·��Dijkstra�㷨
		template <typename PU> void pfs(int, PU); //���ȼ��������
};