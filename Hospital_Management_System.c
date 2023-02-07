#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct date
{
	int day;
	int month;
	int year;
};



struct patient
{
	int id;
	char first_name[50];
	char last_name[50];
	int age;
	char gender[2];
	struct date dob;
	struct date admit_date;
	char problem[50];
};



struct patient p;
char choice[5];



void welcomescreen();
void title();
void login();
void mainmenu();



void create_rec();
void search_rec();
void delete_rec();
void display_rec();
void ex_it();



void main()
{
	welcomescreen();
	
	title();
	
	login();
}


void welcomescreen()
{
	printf("\t \t--------------------------------------------------------------------------------------\n");
	printf("\n \n \t \t \t \t \t * Welcome To Hospital Management System * \n \n");
	printf("\n \t \t--------------------------------------------------------------------------------------\n");
	
	printf("\n \n \t \t \t \t \t     Press any key to continue... ");
	
	getch();
	
	system("cls");
}


void title()
{
	printf("\t \t---------------------------------------------------------------------------------\n");
	printf("\n \n \t \t \t \t \t * Welcome To City Hospital, Pune * \n \n");
	printf("\n \t \t---------------------------------------------------------------------------------\n");
}


void login()
{
	int a=0;
	
	char username[20];
	char password[20];
	
	char myusername[20]="admin";
	char mypassword[20]="9766";
	
	do
	{
		printf("\n \n \n \t \t \t \t \t \t Username :: ");
		scanf("%s",&username);
		
		printf("\n \t \t \t \t \t \t Password :: ");
		scanf("%s",&password);
		
		
		if(strcmp(username,myusername)==0 && strcmp(password,mypassword)==0)
		{
			printf("\n \n \n \t \t \t \t \t \t Login Successfully...");
			
			getch();
			
			printf("\n \n \n \n \t \t \t \t \t    Press any key to continue... ");
			
			getch();
			
			mainmenu();
			
			break;
		}
		
		else
		{
			printf("\n \n \n \t \t \t \t Username or Password is Incorrect : Please Try Again... ");
			
			a++;
			
			getch();
		}
	}
	
	while(a<=2);
	
	if(a>2)
	{
		printf("\n \n \n \t \t \t \t \t You have cross the limit, you cannot login... ");
		
		getch();
		
		ex_it();
	}
}


void mainmenu()
{	
	T:
		
	system("cls");
	
	int c;
	
	title();
	
	
	printf("\n \t \t---------------------------------------------------------------------------------\n");
	printf("\n \n \t \t \t \t \t ###### * WELCOME TO DATABASE * ###### \n");
	printf("\n \n \t \t---------------------------------------------------------------------------------\n");
	
	
	printf("\n \n \n \t \t \t \t \t 1. Create New Patient Reocrd ");         
	printf("\n \n \t \t \t \t \t 2. Search Patient Record ");
	printf("\n \n \t \t \t \t \t 3. Delete Patient Record ");
	printf("\n \n \t \t \t \t \t 4. Display All Patients Record ");
	printf("\n \n \t \t \t \t \t 5. Exit");
	
	
	printf("\n \n \n \n \t \t \t \t * Please Enter Your Choice From 1 to 5 * \n");
	
	
	printf("\n \n \n \t \t \t \t \t   Your Choice Is :: ");
	scanf("%d",&c);
	
	
	switch(c)
	{
		case 1:
			create_rec();
		break;
				
		case 2:
			search_rec();
		break;
					
		case 3:
			delete_rec();
		break;
			
		case 4:
			display_rec();
		break;
			
		case 5:
			ex_it();
		break;
		
		default:
			printf("\n \n \t \t \t \t Invalid Option. Please Select Correct Option. \n");
			
			getch();
			
			goto T;	
	}
}



void create_rec()
{
	system("cls");
	
	title();
	
	
	FILE* fp;
	
	fp = fopen("original.doc","a");
	
		
	printf("\n \n \t \t \t \t \t ***** Create new patient reocrd ***** ");
	
		 
	printf("\n \n \n \t Enter Your ID :: ");
	scanf("%d",&p.id);
				
	printf("\n \t Enter Your First Name :: ");
	scanf("%s",&p.first_name);
				
	printf("\n \t Enter Your Last Name :: ");
	scanf("%s",&p.last_name);
				
	printf("\n \t Enter Your Age :: ");
	scanf("%d",&p.age);
				
	printf("\n \t Enter Your Gender (M/F) :: ");
	scanf("%s",&p.gender);
				
	printf("\n \t Enter Your Date of Birth [dd/mm/yyyy] :: ");
	scanf("%d/%d/%d",&p.dob.day,&p.dob.month,&p.dob.year);
				
	printf("\n \t Enter Your Date of Admit [dd/mm/yyyy] :: ");
	scanf("%d/%d/%d",&p.admit_date.day,&p.admit_date.month,&p.admit_date.year);
				
	printf("\n \t Specify Your Problem :: ");
	scanf("%s",&p.problem);
	
	
	fwrite(&p,sizeof(struct patient),1,fp);
	
	
	printf("\n \n \n \t...Information Added Successfully...");
	
	
	fclose(fp);
	
		
	getch();
	
	
	char choice1[5]="yes";
	char choice2[5]="no";
	
	
	sd:
			
	printf("\n \n \n \n \t You Want To Add More...? [YES/NO] :: ");
	scanf("%s",&choice);
		
	getch();
	
		
	if(strcmp(choice1,choice)==0)
	{
		create_rec();
	}
	
	
	else if(strcmp(choice2,choice)==0)
	{
		printf("\n \n \n \t Thank You...");
		getch();
		mainmenu();
	}
	
	else
	{
		printf("\n \n \n \t Please Choose Correct Option.");
		getch();
		
		goto sd;
	}
}



void search_rec()
{
	system("cls");
	
	title();
	
	int c;
	int id1;
	char nm1[30];
	int found=0;
	
	F:
	
	printf("\n \n \t \t \t \t \t ***** Search patient reocrd ***** ");
	 
	printf("\n \n \n \t Please Enter your choice :- \n");
	
	printf("\n \n \t 1. To Search Record By Using ID : \n");
	printf("\n \t 2. To Search Record By Using Name : \n");
	
	printf("\n \n \t Your Choice is :: ");
	scanf("%d",&c);
	
	
	if(c==1)
		
	{
		A:
			
		system("cls");
	
		title();
		
		
		FILE* fp;
		
		fp = fopen("original.doc","r");
		
		
		printf("\n \n \t \t \t \t \t ***** Search patient reocrd ***** ");
		
		
			
		printf("\n \n \n \t Enter ID To Be Search :: ");
		scanf("%d",&id1);
		
		
		while(fread(&p,sizeof(struct patient),1,fp))
		{
			if(p.id==id1)
			{
				found=1;
				
				printf("\n \n \t  Patient's ID :: %d",p.id);
				printf("\n \t  Patient's First Name :: %s",p.first_name);
				printf("\n \t  Patient's Last Name :: %s",p.last_name);
				printf("\n \t  Patient's Age :: %d",p.age);
				printf("\n \t  Patient's Gender :: %s",p.gender);
				printf("\n \t  Patient's Birth date :: %d/%d/%d",p.dob.day,p.dob.month,p.dob.year);
				printf("\n \t  Patient's Admit Date :: %d/%d/%d",p.admit_date.day,p.admit_date.month,p.admit_date.year);
				printf("\n \t  Patient's Problem :: %s",p.problem);
				
				getch();
			}
		}
		
		
		if(!found)
		{
			printf("\n \n \t Record Not Found. Please Try again...");
			getch();
			
			goto A;
		}
	
		
		char choice1[5]="yes";
		char choice2[5]="no";
				
		sd:
									
			printf("\n \n \n \t You Want To Search More...? [YES/NO] :: ");
			scanf("%s",&choice);
								
			getch();
							
								
			if(strcmp(choice1,choice)==0)
			{
				search_rec();
				
				getch();
			}
		
							
			else if(strcmp(choice2,choice)==0)
			{
				printf("\n \n \t Thank You...");
				
				getch();
				
				mainmenu();
			}
							
			else
			{
				printf("\n \n \t \t \t Please Choose Correct Option.");
				
				getch();
								
				goto sd;
			}
				
				
		fclose(fp);
		
		getch();
	}
	
	
	if(c==2)
	{
		B:
			
		system("cls");
	
		title();
		
		
		FILE* fp;
		
		fp = fopen("original.doc","r");
		
		
		printf("\n \n \t \t \t \t \t ***** Search patient reocrd ***** ");
		
			
		printf("\n \n \n \t Enter Name To Be Search :: ");
		scanf("%s",&nm1);
		
		
		while(fread(&p,sizeof(struct patient),1,fp))
		{
			if(strcmp(p.first_name,nm1)==0)
			{
				found=1;
				
				printf("\n \n \t  Patient's ID :: %d",p.id);
				printf("\n \t  Patient's First Name :: %s",p.first_name);
				printf("\n \t  Patient's Last Name :: %s",p.last_name);
				printf("\n \t  Patient's Age :: %d",p.age);
				printf("\n \t  Patient's Gender :: %s",p.gender);
				printf("\n \t  Patient's Birth date :: %d/%d/%d",p.dob.day,p.dob.month,p.dob.year);
				printf("\n \t  Patient's Admit Date :: %d/%d/%d",p.admit_date.day,p.admit_date.month,p.admit_date.year);
				printf("\n \t  Patient's Problem :: %s",p.problem);
				
				getch();
			}
		}
			
		
		if(!found)
		{
			printf("\n \n \t Record Not Found. Please Try again...");
			getch();
			
			goto B;
		}		
			
		
		char choice1[5]="yes";
		char choice2[5]="no";
				
				
		E:
						
		printf("\n \n \n \t You Want To Search More...? [YES/NO] :: ");
		scanf("%s",&choice);
				
		getch();
				
					
		if(strcmp(choice1,choice)==0)
		{
			search_rec();
			
			getch();
		}
				
				
		else if(strcmp(choice2,choice)==0)
		{
			printf("\n \n \t Thank You...");
			
			getch();
			
			mainmenu();
		}
				
		else
		{
			printf("\n \n \t \t Please Choose Correct Option.");
			
			getch();
					
			goto E;
		}
		
		fclose(fp);
		
		getch();
	}

}



void delete_rec()
{
	system("cls");
	
	title();
	
	int id1;
	int found=0;
	
	
	FILE* fp;
	
	FILE* fp1;
		
	fp = fopen("original.doc","r");
	
	fp1 = fopen("duplicate.doc","w");
		
		
	printf("\n \n \t \t \t \t \t ***** Delete patient reocrd ***** ");
		
		
			
	printf("\n \n \n \t Enter ID To Be Delete :: ");
	scanf("%d",&id1);
		
		
	while(fread(&p,sizeof(struct patient),1,fp))
	{
		if(p.id==id1)
		{
			found=1;
						
			getch();
		}
		
		else
		{
			fwrite(&p,sizeof(struct patient),1,fp1);
		}
	}
	
	
	fclose(fp);
	
	fclose(fp1);
	
	
	if(found)
	{
		fp1=fopen("duplicate.doc","r");
		
		fp=fopen("original.doc","w");
		
		
		while(fread(&p,sizeof(struct patient),1,fp1))
		{
			fwrite(&p,sizeof(struct patient),1,fp);
		}
		
		fclose(fp);
		
		fclose(fp1);
	}
	
	
	printf("\n \n \n \n \t ...Information Deleted Successfully... ");
		
	getch();
	
	printf("\n \n \n \n \n \t \t \t \t \t    Press any key to Back to Mainmenu... ");
	
	getch();
	
	mainmenu();
}



void display_rec()
{
	system("cls");
	
	title();
	
	
	FILE* fp;
	
	fp = fopen("original.doc","r");
	
	
	printf("\n \n \t \t \t \t \t ***** Display all patients reocrd ***** ");
	
	
	while(fread(&p,sizeof(struct patient),1,fp))
	{
		printf("\n \n \n \t  Patient's ID :: %d",p.id);
		printf("\n \t  Patient's First Name :: %s",p.first_name);
		printf("\n \t  Patient's Last Name :: %s",p.last_name);
		printf("\n \t  Patient's Age :: %d",p.age);
		printf("\n \t  Patient's Gender :: %s",p.gender);
		printf("\n \t  Patient's Birth date :: %d/%d/%d",p.dob.day,p.dob.month,p.dob.year);
		printf("\n \t  Patient's Admit Date :: %d/%d/%d",p.admit_date.day,p.admit_date.month,p.admit_date.year);
		printf("\n \t  Patient's Problem :: %s",p.problem);
	}
	
	
	fclose(fp);
	
	
	getch();
	
	printf("\n \n \n \n \t \t \t \t \t    Press any key to Back to Mainmenu... ");
	
	getch();
	
	mainmenu();
}



void ex_it()
{
	ex_it(0);
}
