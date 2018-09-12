#include <iostream>
truct RandomListNode{
    int label;
    struct RandomListNode *next,*random;
    RandomListNode(int x);
    label(x),next(NULL),random(NULL){
    };
    */
        class Solution{
        public:
            RandomListNode* Clone(RandomListNode* pHead){
                if(pHead == NULL)
                {
                    return NULL;
                }
                andomListNode* node = pHead;
                while(node != NULL)
                {
                    RandomListNode* cloneNode = new RandomListNode(0);
                    cloneNode->label = node->label;
                    cloneNode->next = node->next;
                    node->next = cloneNode;
                    node = cloneNode->next;
                }

                //第二步：设置复制出来的random
                RandomListNode* node1 = pHead;
                while(node1 != NULL)
                {
                    RandomListNode* cloneNode1 = node1->next;
                    if(node1->random != NULL)
                    {
                        cloneNode1->random = node1->random->next;
                    }
                    node1 = cloneNode1->next;
                }
                //第三部：把长链表拆开成两个链表，偶数位置的为复制链表
                RandomListNode* nodeEven = NULL;
                RandomListNode* nodeEvenHead = NULL;
                RandomListNode* node2 = pHead;
                if(node2 != NULL)
                {
                    nodeEven = nodeEvenHead = node2->next;
                    node2->next = nodeEven->next;
                    node2 = node2->next;
                }
                while(node2 != NULL)
                {
                    nodeEven->next = node2->next;
                    nodeEven = nodeEven->next;
                    node2->next = nodeEven->next;
                    node2 = node2->next;
                }
                return nodeEvenHead;
            }
        };

