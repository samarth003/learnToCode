#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}node_tag;

#define LOOP_COUNT 6
struct node *p_list = NULL;
//node_tag *p_list = NULL; only works with typedef struct 
struct node *p_pre = NULL; 

struct node *insertNode(struct node *p_list, struct node *p_pre);
void printList(struct node *p_list);

int main(){
	int count;
	for(count=0; count<LOOP_COUNT; count++){
		p_list = insertNode(p_list, p_pre);
	}	
	printList(p_list);
	return 0;
}
struct node *insertNode(struct node *p_list, struct node *p_pre){
	struct node *p_new;
	p_new = (struct node *)malloc(sizeof(struct node));
	
	if(p_new != NULL){
		printf("data in the node is: ");
		scanf("%d", &p_new->data);
		p_new->link = NULL;
		if(p_pre == NULL){
		//if(p_list == NULL){
			p_new->link = p_list;
			//p_list = p_pre = p_new;
			p_list = p_new;
		}
		else{	//insert in the middle or at the end
			printf("inserting in the middle..");
			p_new->link = p_pre->link;
			p_pre->link = p_new;
		}
		return p_list;
	}
}
void printList(struct node *p_list){
	struct node *p_walk;
	printf("Linked list is: \n");
	p_walk = p_list;
	
	while(p_walk != NULL){
		printf("%d--->", p_walk->data);
		p_walk = p_walk->link;
	}
	printf("\n");
	return;
}

