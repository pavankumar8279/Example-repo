#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};


int detectLoop(struct node* head)
{
	struct node* slow = head;
	struct node* fast = head;

	while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			return 1;
		}

	}

	return 0;

}

struct node* insert_front(struct node* head,int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;

	newNode->next = head;
	head = newNode;

	return head;
}

void display(struct node *head)
{
	for(int i=0;head!=NULL;i++)
	{
		printf("data[%d]:%d\n",i,head->data);
		head = head->next;
	}

}

int main()
{
    struct node* head = NULL;
 
    head = insert_front(head, 32);
    head = insert_front(head, 8);
    head = insert_front(head, 5);
    head = insert_front(head, 10);
    display(head);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        printf("Loop found");
    else
        printf("No Loop");
 
    return 0;
}