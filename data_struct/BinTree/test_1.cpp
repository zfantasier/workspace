//用于测试、子树分离操作Tree<T>::secede   是否与原二叉树共享同一个内存空间
#include "Tree.h"
#include <iostream>
int main(){

Tree<int> test_1;
test_1.insertAsRoot(888)->insertAsLC(777)->parent->insertAsRC(666);
test_1.root()->lChild->insertAsLC(555)->parent->insertAsRC(444);
test_1.root()->rChild->insertAsLC(333)->parent->insertAsRC(222);
Tree<int>* resultTree = test_1.secede(test_1.root()->rChild);
std::cout<<test_1.root()->data<<std::endl;
std::cout<<resultTree->root()->data<<std::endl<<resultTree->root()->lChild->data<<std::endl<<resultTree->root()->rChild->data;
return 0;
}a