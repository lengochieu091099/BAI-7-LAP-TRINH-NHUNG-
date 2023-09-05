#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Infor{
    char name[50];
    int phone;
    char address[100];
};
void addinfor(struct Infor a[],int *number){
    int i;
    struct Infor infor;
    printf("Enter name: ");
    gets(infor.name);
    printf("Enter your phone number: ");
    scanf("%d",&infor.phone);
    while(getchar() != '\n' );
    printf("Enter your address: ");
    gets(infor.address);
    a[*number]=infor;
    (*number)++;
};
void shownlistinfor(struct Infor a[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d. Name: %s\n",i+1,a[i].name);
        printf("Phone: %d\n",a[i].phone);
        printf("Address: %s\n",a[i].address);
        printf("\n");
    }
};
void searchfor(struct Infor a[], int n, char vt[]){
    int i;
    for(i=0; i<n;i++){
        if(strcmp(a[i].name,vt)==0){
            printf("Contact found: \n");
            printf("%d. Name: %s\n",i+1,a[i].name);
        	printf("Phone: %d\n",a[i].phone);
        	printf("Address: %s\n",a[i].address);
        	printf("\n");
        }
        else printf("No information in Contact Manager!");
    }

};
int readfile(struct Infor a[], char filename[]){
    int i=0;
    FILE * fp;
    fp = fopen ("information.txt","r");
     if(fp == NULL)
   {
      printf("File can not open!\n");   
      exit(1);             
   }
    while (fscanf(fp,"%s",a[i].name) !=EOF ){
        i++;
    }
    return i;
    fclose (fp);
};
void writefile(struct Infor a[], int n, char filename[]){
	FILE * fp;
    fp = fopen ("information.txt","w");
    if(fp == NULL)
   {
      printf("File can not open!\n");   
      exit(1);             
   }
    for(int i = 0;i<n;i++){
        fprintf(fp, "%d. Name: %s\n",i+1,a[i].name);
        fprintf(fp,"Phone: %d\n",a[i].phone);
        fprintf(fp,"Address: %s\n",a[i].address);
    }
    fclose (fp);
	};
int main(){
    int key;
    int number=0;
    char search[100];
    char filename[]="information.txt";
    struct Infor a[100];
    number=readfile(a,filename);
    printf("Welcome to the Contact Manager!\n");
    while (1){
    printf("1. Add a new contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d",&key);
    while(getchar() != '\n' );
    switch (key)
    {
    case 1:
        addinfor(a,&number);
        printf("Contact added successfully!\n");
        printf("\n");
        writefile(a,number,filename);
        break;
    case 2:
        if(number>0){
        printf("Contact List:\n");
        shownlistinfor(a,number);}
        else{
            printf("Contact manager is empty\n");
            printf("\n");
        }
        break;
    case 3:
        if(number>0){
            printf("Enter name to search for: ");
            gets(search);
            searchfor(a,number,search);
        }
        else{
            printf("No information in Contact Manager!");
            printf("\n");
        }
        break;
    case 4:
        printf("Good bye!");
        return 0;
    default:
        printf("This function is not available. Please choice the appropriate function !");
        break;
    }
    }
    return 0;
};