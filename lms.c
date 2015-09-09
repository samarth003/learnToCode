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

int *p_applyleaves = &leaves_applied;
int *p_slapply = &sick_leave_applied;

void log_screen(struct user details);
void app_out(struct user details);
//void view_leave(int leaves_applied, int *p_applyleaves, int sick_leave_applied, int *p_slapply);
void view_leave(struct user details2);
void apply_leave(struct user details1);
void update_leave(int *p_applyleaves, int *p_slapply);
void options(struct user rec_user);

int main(){
	struct user user_record;
	log_screen(user_record);
	return 0;
}
void log_screen(struct user details){
	int counter;
	printf("user name: ");
	for(counter=0; counter<sizeof(details.uname); counter++){
		details.uname[counter] = getch();
		printf("%c", details.uname[counter]);
		if(details.uname[counter] == 13){ //13 is the ascii code for enter key
			break;
		}
	}
	//scanf("%s", &details.uname);
	printf("\npassword: ");
	//scanf("%s", &details.pwd);
	for(counter=0; counter<sizeof(details.pwd); counter++){
		details.pwd[counter] = getch();
		printf("*");		
	}
	options(details);	
}
void app_out(struct user detail_repeat){
	printf("You've successfully logged out!\n");
	log_screen(detail_repeat);
}
void view_leave(struct user details2){
	//sick_leave = (sick_leave - *p_slapply);	
	//annual_leave = (annual_leave - *p_applyleaves);

	printf("Remaining Annual leaves: %d", annual_leave);
	printf("\nRemaining sick leaves: %d", sick_leave);
	options(details2);
}

void apply_leave(struct user details1){
	//apply leave and call update once applied
	int choose_leave;
	printf("\nWhich leave you want to apply\n1.Sick leave\n2.Annual leave\n");
	scanf("%d", &choose_leave);
	if(choose_leave == 1){
		printf("\nNo. of days you were sick: ");
		scanf("%d", &sick_leave_applied);
		update_leave(&leaves_applied, &sick_leave_applied); //update leave
		options(details1);
	}
	else{
		printf("\nNo. of days of vacation: ");
		scanf("%d", &leaves_applied);
		update_leave(&leaves_applied, &sick_leave_applied); //update leave
		options(details1);
	}
}
void update_leave(int *p_applyleaves, int *p_slapply){
	sick_leave = (sick_leave - *p_slapply);	
	annual_leave = (annual_leave - *p_applyleaves);
}
void options(struct user rec_user){
	int num_select;
	printf("\nPlease key in the number corresponding to what you want to do\n1.View your leave\n2.Apply for leave\n3.Exit\n");
	scanf("%d", &num_select);	
	
	switch(num_select){
		case 1:
			view_leave(rec_user);
			break;
		case 2: 
			apply_leave(rec_user);
			break;
		/*case 3:
			update_leave(&leaves_applied, &sick_leave_applied);
			break;*/
		case 3:
			app_out(rec_user);
			break;
		default:
			printf("Please try again!");
			break;
	}
}