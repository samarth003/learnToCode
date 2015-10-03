#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}node_tag;

struct node *p_list = NULL;
//node_tag *p_list = NULL; only works with typedef struct 
struct node *p_pre = NULL; 

struct node *insertNode(struct node *p_list, struct node *p_pre);

int main(){
	
	p_list = insertNode(&p_list, &p_pre);	
	return 0;
}
struct node *insertNode(struct node *p_list, struct node *p_pre){
	struct node *p_new;
	p_new = (struct node *)malloc(sizeof(struct node));
	
	if(p_new != NULL){
		printf("data in the node is: ");
		scanf("%d", p_new->data);
		if(p_pre == NULL){
			p_new->link = p_list;
			p_list = p_pre = p_new;
		}
		else{	//insert in the middle or at the end
			p_new->link = p_pre->link;
			p_pre->link = p_new;
		}
		return p_list;
	}
}


