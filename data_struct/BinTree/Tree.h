#include "TreeNode.h"
#define nullptr 0
#include "define.h"
#define stature(p) ((p)?(p)->height:-1)
#define MAX(a,b) (a>b?a:b)
template <typename T> class Tree{
protected:
	int _size;TreeNodePosi(T) _root;
	virtual int updateHeight( TreeNodePosi(T) x);//����x�ڵ�ĸ߶�
	void updateHeightAbove(TreeNodePosi(T) x);//����x�ڵ㼰������ĸ߶�
public:
	Tree():_size(0),_root(nullptr){}
	~Tree(){if(0<_size) remove (_root);}
	int size() const {return _size;}
	bool empty() const {return !_root;}
	TreeNodePosi(T) root() const {return _root;}
	TreeNodePosi(T) insertAsRoot(T const & e);
	TreeNodePosi(T) insertAsLC(TreeNodePosi(T) x,T const & e);
	TreeNodePosi(T) insertAsRC(TreeNodePosi(T) x,T const & e);
	TreeNodePosi(T) attachAsLC(TreeNodePosi(T) x, Tree<T>* &); //T��Ϊx����������
	TreeNodePosi(T) attachAsRC(TreeNodePosi(T) x, Tree<T>* &); //T��Ϊx����������
	int remove(TreeNodePosi(T) x); //������λ��x���ڵ�Ϊ���m������ކ��ڹ����ԭ�Ȱm�_ģ
	Tree<T>* secede(TreeNodePosi(T) x); //������x����ǰ����ժ�����Խ���ת��Ϊһ�ö�������
	template <typename VST> //������
	void travLevel(VST& visit) { if (_root) _root->travLevel(visit); } //�ִα���
	template <typename VST> //������
	void travPre(VST& visit) { if (_root) _root->travPre(visit); } //�������
	template <typename VST> //������
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //�������
	template <typename VST> //������
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //�������
// �Ƚ������`������������һ���������в��䣩
	bool operator<(Tree<T> const& t) { return _root && t._root && lt(_root, t._root); }
	bool operator==(Tree<T> const& t) { return _root && t._root && (_root == t._root); }
};

template <typename T> int Tree<T>::updateHeight(TreeNodePosi(T) x){return x->height + MAX(stature(x->lChild),stature(x->rChild));}
template <typename T> void Tree<T>::updateHeightAbove(TreeNodePosi(T) x){while(x){updateHeight(x);x = x->parent;}}//o( n = depth(x) )
template <typename T> TreeNodePosi(T) Tree<T>::insertAsRoot(T const& e) { _size = 1; return _root = new TreeNode<T>(e); } 
template <typename T> TreeNodePosi(T) Tree<T>::insertAsLC(TreeNodePosi(T) x,T const & e){_size++;x->insertAsLC(e);updateHeightAbove(x);return x->lChild;}
template <typename T> TreeNodePosi(T) Tree<T>::insertAsRC(TreeNodePosi(T) x,T const & e){_size++;x->insertAsRC(e);updateHeightAbove(x);return x->rChild;}

template <typename T> //���������������㷨����S�����ڵ�x�m���������룬S�����ÿ�
TreeNodePosi(T) Tree<T>::attachAsLC(TreeNodePosi(T) x, Tree<T>* &S) { //x->lChild == nullptr
	if (x->lChild = S->_root) x->lChild->parent = x; //����
	_size += S->_size; updateHeightAbove(x); 
	S->_root = nullptr; S->_size = 0; delete(S); S = nullptr; return x; //�ͷ�ԭ����ކ�ؽ���λ��
}

 template <typename T> //���������������㷨����S�����ڵ�x�m���������룬S�����ÿ�
 TreeNodePosi(T) Tree<T>::attachAsRC(TreeNodePosi(T) x, Tree<T>* &S) { //x->rChild == nullptr
 if (x->rChild = S->_root) x->rChild->parent = x; //����
 _size += S->_size; updateHeightAbove(x); //����ȫ���_ģ��x�������Ȱm�߶�
 S->_root = nullptr; S->_size = 0; delete(S); S = nullptr; return x; //�ͷ�ԭ����ކ�ؽ���λ��
 }
 
 template <typename T> //������������λ��x���m�ڵ㼰������ކ�ر������ڵ�m��ֵ
 int Tree<T>::remove(TreeNodePosi(T) x) { //assert: xΪ�������аm�Ϸ�λ��
 FromParentTo(*x) = nullptr; //�ж����Ը��ڵ�mָ��
 updateHeightAbove(x->parent); //�������ȸ߶�
 int n = removeAt(x); _size -= n; return n; //��������x�������_ģ��ކ�س����ڵ�����
 }

 template <typename T> //������������λ��x���m�ڵ㼰������ކ�ر������ڵ�m��ֵ
	static int removeAt(TreeNodePosi(T) x) { //assert: xΪ�������аm�Ϸ�λ��
	if (!x) return 0; //�Ϗ���������
	int n = 1 + removeAt(x->lChild) + removeAt(x->rChild); //�Ϗ��ͷ���������
	delete(x); return n;
 }
 template <typename T> //���������������㷨��������x����ǰ����ժ���������װΪһ�ö�������ކ��
	Tree<T>* Tree<T>::secede(TreeNodePosi(T) x) { //assert: xΪ�������аm�Ϸ�λ��
	FromParentTo(*x) = nullptr; //�ж����Ը��ڵ�mָ��
	updateHeightAbove(x->parent); //����ԭ�����������Ȱm�߶�
	Tree<T>* S = new Tree<T>; S->_root = x; x->parent = nullptr; //������xΪ��
	S->_size = x->size(); _size -= S->_size; return S; //
 }
