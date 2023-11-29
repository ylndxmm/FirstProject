#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node_type {
    struct node_type* next;
    int val;
}node_type;
typedef struct ListNode {
    int length;
    node_type* next;
    node_type* head;
}ListNode;


void createlist(ListNode* p)
{
	node_type* new_node, * s;
	p->length =0;
	p->head = NULL;
	s = p->head;
	for (int i = 0;; i++)
	{
		int x;
		scanf_s("%d",&x);
		if (x == 0)
			break;
		new_node = (node_type*)malloc(sizeof(node_type));
	    new_node->val = x;
	    new_node->next = NULL;
		if (p->head == NULL)
		{
			p->head = new_node;
			s = p->head;
		}
		
		else		
        {	
			s->next = new_node;
			s = s->next;
		}
		p->length++;
	}
}
struct ListNode* insertionSortList(struct ListNode* lp) {
   node_type* p = lp->head->next;
   node_type* L = lp->head;
   node_type* pre;
    L->next = NULL;
    while (p != NULL) {
        struct node_type* temp = (struct node_type*)malloc(sizeof(node_type));
        pre = L;
        while (pre != NULL) {
            if (pre->val > p->val) {
                temp->val = pre->val;
                temp->next = pre->next;
                pre->val = p->val;
                pre->next = temp;
                break;
            }
            else if (pre->next == NULL) {
                temp->val = p->val;
                temp->next = pre->next;
                pre->next = temp;
                break;
            }
            else
                pre = pre->next;
        }
        p = p->next;
    }
    return lp;
}

int main(void)
{
    ListNode* head;
    head = (ListNode*)malloc(sizeof(ListNode));
    createlist(head);

    insertionSortList(head);
}
