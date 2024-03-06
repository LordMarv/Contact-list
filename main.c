#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
	char name[60];
	int num;
	int completed;
}Contact;
	
//Global variables to store contacts and length

Contact *contactList=NULL;
int Total=0;
	
	
void addContact(const char * name, int num){
	contactList = realloc(contactList, (Total + 1) * sizeof(Contact));
	if (contactList == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
	//contactList[Total].name= (char *)malloc(strlen(name) + 1);
	strcpy(contactList[Total].name, name); // Copy the name into the name array
	contactList[Total].num=num;
	contactList[Total].completed=0;
	Total++;
	printf("Contact Added\n");
}
		
	
	
	
void listContact(){
	char status;
	int completed;
		
	for(int i=0; i < Total; i++){
		if(contactList[i].completed==1){
			status='d';
		}else {
			status='n';
		}
		printf("%d. %s %d [%c]\n",i + 1, contactList[i].name, contactList[i].num,status );
	}
	
}
		
	
	
void searchContact(const char *name){
	int i;
	int flag=0;
	
	
	
	
	for(i=0; i < Total; i++){
		if(strcmp(contactList[i].name, name)==0){
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		printf("Contact Details: %s %d\n",contactList[i].name,contactList[i].num);
	}else{
		printf("%s is not found",name);
	}
}
	
	
void deleteContact(const char *name){
	int i;
	int found=0;
	
	for(i=0; i<Total; i++){
		if(strcmp(contactList[i].name,name)==0){
			found=1;
			break;
		}
	}
	
	if(found==1){
		int j;
		for(j=i; j< Total-1; j++){
			contactList[j]=contactList[j+1];
		}
		Total--;
		printf("%s has been deleted",name);
	}else{
		printf("%s is not found"),name;
	}

}

void editContact(const char *name){
	int found=0;
	int i;
	
	for(i=0;i< Total; i++){
		if(strcmp(contactList[i].name,name)==0){
			found=1;
			break;
		}
	}
	
	if(found==1){
		char newName[60];
		int newNum;
		
		printf("Enter new Contact Name: \n");
		fgets(newName, sizeof(newName), stdin);
		
		printf("Enter new Contact number: \n");
		scanf("%d",&newNum);
		
		strcpy(contactList[i].name, newName); // Copy the name into the name array
		contactList[i].num=newNum;
		printf("Contact Updated Succesfully\n");
	}else{
		printf("Contact not found");
	}
}
	
int main(){
	int option,num, running=1;
	char name[60];
	
	printf("1. Add a Contact\n");
	printf("2.List all contact\n");
	printf("3. seearch for contact\n");
	printf("4. Edit Contact\n");
	printf("5. Delete Contact\n");
	printf("6. Exit\n");
	
	while(1){
		printf("Enter your option(1-6)\n");
		scanf("%d", &option);
		
		
		switch(option){
			case 1:
				printf("Enter Contact Name: \n");
				scanf("%s",name);

				printf("Enter Contact Number: \n");
				scanf("%d",&num);
				getchar();
				addContact(name,num);
				break;
				
			case 2:
				listContact();
				break;
				
			case 3:
				printf("Enter a name: \n");
				fgets(name, sizeof(name), stdin);
				
				searchContact(name);
				break;
				
			case 4:
				printf("Enter a name: \n");
				fgets(name, sizeof(name), stdin);
				
				deleteContact(name);
				break;
				
			case 5:
				printf("Enter Contact Name: \n");
				fgets(name, sizeof(name), stdin);
				
				printf("Enter Contact number\n");
				scanf("%d",&num);
				getchar();
				editContact(name);
				break;
				
			case 6:
				running =0;
				break;
				
			default:
				printf("Invalid Choice\n");
				break;	
		}
	}
	return 0;
}
