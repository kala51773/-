/*链表反转*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct  node {
	int date;
	node* next;
};

void insertnode(node* head, int tmp)
{
	node* p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = (node*)malloc(sizeof(node));
	p = p->next;
	p->date = tmp;
	p->next = NULL;

}
void re(node* head)
{
	node* cur, * tmp=NULL, * tmp2, * pre;
	
	cur = head->next;
	if (cur == NULL)
		return;
	pre = NULL;
	while (cur)
	{
		tmp = cur;
		tmp2 = cur->next;
		cur->next = pre;
		pre = tmp;
		cur = tmp2;
	}
	head->next = tmp;
	head->date = -1;
}
int main()
{
	node* list = (node*)malloc(sizeof(node));
	list->next = NULL;
	int tmp;
	while (scanf("%d", &tmp) != EOF)
	{
		insertnode(list, tmp);
	}
	re(list);
	node* p = list;
	while(p)
	{ 
	printf("%d", p->date);
	p = p->next;
	}
}
