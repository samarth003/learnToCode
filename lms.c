#include <stdio.h>
#include<conio.h>

struct user{
	char uname[30];
	char pwd[4];
}details;

void log_screen(struct user details);
void app_out(struct user details);

int main(){
	struct user user_record;
	int num_select;
	log_screen(user_record);
	printf("\nPlease key in the number corresponding to what you want to do\n1.View your leave\n2.Apply for leave\n3.Update leave record\n4.Exit\n");
	scanf("%d", num_select);
	//app_out(user_record);
	
	switch(num_select){
		case 1:
			printf("testing case1.. ");
			//view_leave();
			break;
		case 2: 
			printf("testing case2.. ");
			//apply_leave();
			break;
		case 3:
			printf("testing case3.. ");
			//update_leave();
			break;
		case 4:
			app_out(user_record);
			break;
		default:
			printf("Please try again!");
			break;
	}	
	return 0;
}
void log_screen(struct user details){
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
void app_out(struct user details){
	log_screen(details);
}