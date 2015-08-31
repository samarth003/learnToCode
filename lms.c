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
	login(user_record);
	return 0;
}
