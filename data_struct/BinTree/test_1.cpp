//���ڲ��ԡ������������Tree<T>::secede   �Ƿ���ԭ����������ͬһ���ڴ�ռ�
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