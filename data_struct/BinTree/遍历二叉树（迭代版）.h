//����
template <typename T, typename VST> //Ԫ�����͡�������
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) 
{
	while (x) {
		visit(x->data); //ڪ����ǰ�ڵ�
		S.push(x->rChild); //�Һ�����ջ�ݴ棨���Ż���ͨ���`�ϣ�����հm�Һ�����ջ��
		x = x->lChild; //�����֧����һ��
	}
}

template <typename T, typename VST> //Ԫ�����͡�������
void travPre(TreeNodePosi(T) x, VST& visit) { //��������������㷨��������#2��
	Stack<TreeNodePosi(T)> S; //����ջ
	while (true) {
	visitAlongLeftBranch(x, visit, S); //����ǰ�ڵ����������ڪ��
	if (S.empty()) break; //ֱ�bջ��
	x = S.pop(); //������һ���m���
	}
}
//����
template <typename T, typename VST> //Ԫ�����͡�������
static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) 
{
	while (x) { //ڪ����ǰ�ڵ�
		S.push(x); //�Һ�����ջ�ݴ棨���Ż���ͨ���`�ϣ�����հm�Һ�����ջ��
		x = x->lChild; //�����֧����һ��
	}
}

template <typename T, typename VST> //Ԫ�����͡�������
void travIn(TreeNodePosi(T) x, VST& visit) { //��������������㷨��������#2��
	Stack<TreeNodePosi(T)> S; //����ջ
	while (true) {
	goAlongLeftBranch(x,S); 
	if (S.empty()) break; //ֱ�bջ��
	x=S.pop();visit(x->data);
	x = x->rChild; //������һ���m���
	}
}




//����
template <typename T, typename VST> //Ԫ�����͡�������
static void doAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) 
{
	while (x) {
	 //ڪ����ǰ�ڵ�
		S.push(x->rChild); //�Һ�����ջ�ݴ棨���Ż���ͨ���`�ϣ�����հm�Һ�����ջ��
		x = x->lChild; //�����֧����һ��
	}
}

template <typename T, typename VST> //Ԫ�����͡�������
void travPost(TreeNodePosi(T) x, VST& visit) { //��������������㷨��������#2��
	Stack<TreeNodePosi(T)> S; //����ջ
	while (true) {
	visitAlongLeftBranch(x, visit, S); //����ǰ�ڵ����������ڪ��
	if (S.empty()) break; //ֱ�bջ��
	x = S.pop(); //������һ���m���
	}
}

//��α���

template <typename T, typename VST> //Ԫ�����͡�������
void travLevel(TreeNodePosi(T) x, VST& visit) { //��������������㷨��������#2��
	Queue<TreeNodePosi(T)> Q;
	Q.enqueue(this)	//����ջ
	while (!Q.empty()) {
	auto x=Q.dequeue();
	visit(x->data);
	if(HasLChild(*x)) Q.enqueue(x-lChild);
	if(HasRChild(*x)) Q.enqueue(x->rChild);
	}
}