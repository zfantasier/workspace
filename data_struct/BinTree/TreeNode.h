#define nullptr 0
#define TreeNodePosi(T) TreeNode<T>*
#ifndef TREENODE_H
#define TREENODE_H

template <typename T> struct TreeNode{
//	成员
	TreeNodePosi(T) parent;
	TreeNodePosi(T) lChild;
	TreeNodePosi(T) rChild;
	T data; 
	int height;//高度 
//	构造函数
	TreeNode():
		parent(nullptr),lChild(nullptr),rChild(nullptr),height(0){}
	TreeNode(T e,TreeNodePosi(T) p=nullptr,TreeNode* lChild=nullptr,TreeNode* rChild=nullptr,int height=0):
		data(e),parent(p),lChild(lChild),rChild(rChild),height(height){}
//	操作接口
	int size();//子树规模
	TreeNodePosi(T) insertAsLC( T const &);
	TreeNodePosi(T) insertAsRC( T const &);//作为左右孩子插入新的节点
	TreeNodePosi(T) succ();//中序遍历下的直接后继
	template <typename VST> void travLevel(VST &);//子树层次遍历
	template <typename VST> void travPre(VST &);//先
	template <typename VST> void travIn(VST &);//中
	template <typename VST> void travPost(VST &);//后序遍历
// 比较器 , 判断器
	bool operator< (TreeNode const& bn){return data<bn.data;}
	bool operator== (TreeNode const& bn){return data==bn.data;}
};
template <typename T> TreeNodePosi(T) TreeNode<T>::insertAsLC( T const &e){return this->lChild = new TreeNode(e,this);}
template <typename T> TreeNodePosi(T) TreeNode<T>::insertAsRC( T const &e){return this->rChild = new TreeNode(e,this);}
template <typename T> int TreeNode<T>::size(){int s = 1;if (this->lChild) s += lChild->size();if (this->rChild) s += rChild->size();return s;}

template <typename T, typename VST> //元素类型、操作器
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) 
{
	while (x) {
		visit(x->data); //讵问弼前节点
		S.push(x->rChild); //右孩子入栈暂存（可优化：通过刞断，避免空癿右孩子入栈）
		x = x->lChild; //沿左分支深入一局
	}
}

template <typename T, typename VST> //元素类型、操作器
void travPre(TreeNodePosi(T) x, VST& visit) { //二叉树先序遍历算法（迭代版#2）
	Stack<TreeNodePosi(T)> S; //辅劣栈
	while (true) {
	visitAlongLeftBranch(x, visit, S); //从弼前节点出収，逐批讵问
	if (S.empty()) break; //直刡栈空
	x = S.pop(); //弹出下一批癿起点
	}
}
#endif
