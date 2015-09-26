#define nullptr 0
#define TreeNodePosi(T) TreeNode<T>*
#ifndef TREENODE_H
#define TREENODE_H

template <typename T> struct TreeNode{
//	��Ա
	TreeNodePosi(T) parent;
	TreeNodePosi(T) lChild;
	TreeNodePosi(T) rChild;
	T data; 
	int height;//�߶� 
//	���캯��
	TreeNode():
		parent(nullptr),lChild(nullptr),rChild(nullptr),height(0){}
	TreeNode(T e,TreeNodePosi(T) p=nullptr,TreeNode* lChild=nullptr,TreeNode* rChild=nullptr,int height=0):
		data(e),parent(p),lChild(lChild),rChild(rChild),height(height){}
//	�����ӿ�
	int size();//������ģ
	TreeNodePosi(T) insertAsLC( T const &);
	TreeNodePosi(T) insertAsRC( T const &);//��Ϊ���Һ��Ӳ����µĽڵ�
	TreeNodePosi(T) succ();//��������µ�ֱ�Ӻ��
	template <typename VST> void travLevel(VST &);//������α���
	template <typename VST> void travPre(VST &);//��
	template <typename VST> void travIn(VST &);//��
	template <typename VST> void travPost(VST &);//�������
// �Ƚ��� , �ж���
	bool operator< (TreeNode const& bn){return data<bn.data;}
	bool operator== (TreeNode const& bn){return data==bn.data;}
};
template <typename T> TreeNodePosi(T) TreeNode<T>::insertAsLC( T const &e){return this->lChild = new TreeNode(e,this);}
template <typename T> TreeNodePosi(T) TreeNode<T>::insertAsRC( T const &e){return this->rChild = new TreeNode(e,this);}
template <typename T> int TreeNode<T>::size(){int s = 1;if (this->lChild) s += lChild->size();if (this->rChild) s += rChild->size();return s;}

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
#endif
