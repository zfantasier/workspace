/*
2015-5-7 20:40:39 
递归的方法实现二叉树
*/
template <class T ,class VST>//元素类型和操作器
void travPre_R(TreeNode<T>* x,VST& visit){
if(!x) return;
visit(x->data);
travPre_R(x->lChild,visit);
travPre_R(x->rChild,visit);
}

template <class T ,class VST>//元素类型和操作器
void travPre_(TreeNode<T>* x,VST& visit){
if(!x) return;
travPre_R(x->lChild,visit);
visit(x->data);
travPre_R(x->rChild,visit);
}

template <class T ,class VST>//元素类型和操作器
void travPre_R(TreeNode<T>* x,VST& visit){
if(!x) return;
visit(x->data);
travPre_R(x->lChild,visit);
travPre_R(x->rChild,visit);
}