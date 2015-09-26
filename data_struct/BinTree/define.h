/*TreeNode 中节点状态的快捷方式*/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (! IsRoot(x)&&(&(x)==(x).parent->lChild))
#define IsRChild(x) (! IsRoot(x)&&(&(x)==(x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define	HasChild(x) (HasLChild(x)||HasRChild(x))
#define	HasBothChild(x) (HasLChild(x)&&HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
//与node具有特定关系的节点及指针
#define sibling(p) (IsLChild(*(p))?(p)->parent-lChild:(p)->parent-rChild)
#define uncle(x) (IsLChild(*((x)->parent))?(x)->parent->parent->rChild:(x)->parent->parent->lChild)
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild))