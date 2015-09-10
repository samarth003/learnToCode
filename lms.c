#include <stdio.h>
#include<conio.h>
#include<ctype.h>

#define ENTER_KEY 13 //13 is the ascii code for enter key

struct user{
	char uname[30];
	char pwd[10];
}details;

int sick_leave = 6;
int annual_leave = 14;
int leaves_applied = 0;
int sick_leave_applied = 0;

int *p_applyleaves = &leaves_applied;
int *p_slapply = &sick_leave_applied;

void log_screen(struct user details0);
void app_out(struct user details);
//void view_leave(int leaves_applied, int *p_applyleaves, int sick_leave_applied, int *p_slapply);
void view_leave(struct user details2);
void apply_leave(struct user details1);
void update_leave(int *p_applyleaves, int *p_slapply);
void options(struct user rec_user);
void username(struct user details);
void password(struct user details3);

int main(){
	struct user user_record;
	log_screen(user_record);
	return 0;
}
void log_screen(struct user details0){
	username(details0);
	password(details0);
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
			//options(rec_user); //sometimes goes to infinite loop, runs out of memory and crashes
			break;
	}
}
void username(struct user details){
	int counter;
	printf("\nuser name: ");
	for(counter=0; counter<sizeof(details.uname); counter++){
		details.uname[counter] = getch();
		if((details.uname[counter] == ENTER_KEY) && (counter >=7)){ 
			break;
		}
		else if((details.uname[counter] == ENTER_KEY) && (counter <7)){
			printf("\nusername length is a minimum of 7 characters!");
			username(details);
			break;
		}
		else if((!isalnum(details.uname[counter])) && (details.uname[counter] != ENTER_KEY)){
			printf("\nInvalid read!");
			username(details);
			break;
		}
		else{
			printf("%c", details.uname[counter]);
		}
	}
	//scanf("%s", &details.uname);*/
}
void password(struct user details3){
	int counter1; 
	printf("\npassword: ");
	for(counter1=0; counter1<sizeof(details3.pwd); counter1++){
		details3.pwd[counter1] = getch();
			if((details3.pwd[counter1] == ENTER_KEY) && (counter1 >= 5)){ 
				break;
			}
			else if((details3.pwd[counter1] == ENTER_KEY) && (counter1 < 5)){
				printf("\nPassword length not met!");
				//a call to get the password field again
				password(details3);
				break;
			}
			else if((!isalnum(details3.pwd[counter1])) && (details3.pwd[counter1] != ENTER_KEY)){
				printf("Only alphanumeric characters allowed!");
				password(details3);
				break;
			}
			else{
				printf("*");
			}
	}
}