#include <stdio.h>

struct user{
	char uname[30];
	char pwd[4];
}details;
void login(struct user details){
	printf("user name: ");
	scanf("%s", details.uname);
	printf("\npassword: ");
	scanf("%s", details.pwd);
}
int main(){
	struct user user_record;
	login(user_record);
	return 0;
}
