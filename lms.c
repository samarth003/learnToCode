#include <stdio.h>
#include<conio.h>

struct user{
	char uname[30];
	char pwd[4];
}details;
void login(struct user details){
	int counter;
	printf("user name: ");
	scanf("%s", details.uname);
	printf("\npassword: ");
	//scanf("%s", details.pwd);
	for(counter=0; counter<sizeof(details.pwd); counter++){
		details.pwd[counter] = getch();
		printf("*");		
	}
}
int main(){
	struct user user_record;
	int num_select;
	login(user_record);
	printf("Please key in the number corresponding to what you want to do\n1.View your leave\n2.Apply for leave\n3.Update leave record");
	scanf("%d", num_select);
/*	
	switch(num_select){
		case 1: view_leave();
				break;
		case 2: apply_leave();
				break;
		case 3: update_leave();
				break;
		default: printf("Please try again!");
				break;
	}
*/	
	return 0;
}
