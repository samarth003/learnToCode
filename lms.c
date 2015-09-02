#include <stdio.h>
#include<conio.h>

struct user{
	char uname[30];
	char pwd[4];
}details;

int sick_leave = 6;
int annual_leave = 14;
int leaves_applied = 0;
int sick_leave_applied = 0;

void log_screen(struct user details);
void app_out(struct user details);
void view_leave(int an_apply, int sl_apply);

int main(){
	struct user user_record;
	log_screen(user_record);
	return 0;
}
void log_screen(struct user details){
	int counter;
	int num_select;
	printf("user name: ");
	scanf("%s", &details.uname);
	printf("\npassword: ");
	//scanf("%s", &details.pwd);
	for(counter=0; counter<sizeof(details.pwd); counter++){
		details.pwd[counter] = getch();
		printf("*");		
	}
	
	printf("\nPlease key in the number corresponding to what you want to do\n1.View your leave\n2.Apply for leave\n3.Update leave record\n4.Exit\n");
	scanf("%d", &num_select);	
	
	switch(num_select){
		case 1:
			view_leave(leaves_applied, sick_leave_applied);
			break;
		case 2: 
			//apply_leave();
			break;
		case 3:
			//update_leave();
			break;
		case 4:
			app_out(details);
			break;
		default:
			printf("Please try again!");
			break;
	}
}
void app_out(struct user detail_repeat){
	printf("You've successfully logged out!\n");
	log_screen(detail_repeat);
}
void view_leave(int an_apply, int sl_apply){
	sick_leave = (sick_leave - sl_apply);	
	annual_leave = (annual_leave - leaves_applied);

	printf("Remaining Annual leaves: %d", annual_leave);
	printf("\nRemaining sick leaves: %d", sick_leave);
}