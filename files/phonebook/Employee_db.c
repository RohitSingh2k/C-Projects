#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
	char emp_Name[30];
	char emp_Country_Code[4];
	char emp_ID_Card[15];
	long int emp_Mobile_No;
	char emp_gender[8];
	char emp_email[100];
};

//Here we define a data type for emplyee
typedef struct employee employee;


//function declarations
void	start();
void wipe_all_employees();
void menu_options();
void add_employee();
void list_emprecords();
void search_employee();
void wipe_employee();
void update_employee();
void accept_input(employee *emp);

int main()
{
	start();
	return 0;
}

//The function that starts our program
void start()
{
	int select;
	while(1)
	{
		menu_options();
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				list_emprecords();
				getchar();
				getchar();
				break;
			case 2:
				add_employee();
				getchar();
				getchar();
				break;
			case 3:
				search_employee();
				getchar();
				getchar();
				break;
			case 4: 
				wipe_employee();
				getchar();
				getchar();
				break;
			case 5: 
				update_employee();
				getchar();
				getchar();
				break;
			case 6: 
				wipe_all_employees();
				getchar();
				getchar();
				break;
			default :
				system("clear");
				printf("Thanks for your corporation : ");
				getchar();
				getchar();
				exit(1);
		}

	
	}

}

//A function to display the main menu options
void menu_options()
{

	system("clear");
	printf("\t\t*******************************************************************\n");
	printf("\t\t* 		Welcome to the Employees Regidtration Page	      *\n");
	printf("\t\t*******************************************************************\n\n");
	printf("\t\t\t1) List Employees Record\n\n");
	printf("\t\t\t2) Add Employee\n\n");
	printf("\t\t\t3) Search Employees Details\n\n");
	printf("\t\t\t4) Delete Employee from DB file\n\n");
	printf("\t\t\t5) Update Employees Detai\n\nl");
	printf("\t\t\t6) Delete All Employees Contact\n\n");
	printf("\t\t\t7) Exit Employees Reg Page\n\n");

	printf("\t\t\t\tEnter your choice as stated above : ");

}


//This function adds employees information into the employees DB file
void add_employee()
{
	system("clear");
	FILE *fptr;
	if((fptr = fopen("employee_db", "ab+")) == NULL)
	{
		printf("Error: The file could not open, try again!\n");
		printf("Type any key to proceed...\n");
		return;

	}
	else
	{
		employee emp;
		accept_input(&emp);

		fwrite(&emp, sizeof(emp), 1, fptr);
		fflush(stdin);
		fclose(fptr);
		system("clear");
		printf("Employees data is entered successfully\n");
		printf("Press any key to continue ...\n");
	}

}

//This function accepts employees information from the add_employee() function above
void accept_input(employee *emp)
{
	system("clear");

	getchar();
	printf("Enter name : ");
	scanf("%[^\n]s",emp->emp_Name);

	printf("Enter Employees country code : ");
	scanf("%s",emp->emp_Country_Code);

	printf("Enter employees ID: ");
	scanf("%s",emp->emp_ID_Card);

	printf("Enter employees Phone No : ");
	scanf("%ld",&emp->emp_Mobile_No);

	printf("Enter employees Gender : ");
	scanf("%s",emp->emp_gender);

	printf("Enter employees email address : ");
	scanf("%s",emp->emp_email);
}

//This function list the records of all the employees
void list_emprecords()
{

	system("clear");
	FILE *fptr;
	if((fptr = fopen("employee_db", "rb")) == NULL)
	{

		printf("Error: Failed to open the file, please try again !\n");
		printf("Press any key to proceed ...\n");
		return;

	}
	else
	{

		employee emp;
		printf("\n\t\t\t\t*****************************************************************************************************\n");
		printf("\t\t\t\t*			    The Records of all XYZ Employees Comapny					*\n");
		printf("\t\t\t\t*******************************************************************************************************\n\n\n");
		printf("	NAME\t\t\t\t	Country Code\t\t	ID NO\t\t	MOBILE NO\t\t	GENDER\t\t	EMAIL\n");
		printf("----------------------------------------------------------------------------------------------------------------");

		while(fread(&emp, sizeof(emp), 1, fptr) == 1)
		{
			int i;
			int emp_Name_Size = 40 - strlen(emp.emp_Name);
			int emp_Country_Size = 19 - strlen(emp.emp_Country_Code);
			int emp_ID_Size = 19 - strlen(emp.emp_ID_Card);
			int emp_Mobile_Size = 15;
			int emp_gender_Size = 21 -strlen(emp.emp_gender);
			int emp_mail_Size = 30 - strlen(emp.emp_email);
	
			printf("%s",emp.emp_Name);
			for (i=0;i<emp_Name_Size;i++); printf("   ");

			printf("%s",emp.emp_Country_Code);
			for (i=0; i<emp_Country_Size; i++); printf("   ");

			printf("%s",emp.emp_ID_Card);
			for (i=0; i<emp_ID_Size; i++); printf("   ");

			printf("%ld",emp.emp_Mobile_No);
			for (i=0; i<emp_Mobile_Size; i++); printf("   ");

			printf("%s",emp.emp_gender);
			for (i=0; i<emp_gender_Size; i++); printf("   ");

			printf("%s",emp.emp_email);
			printf("\n");
			fflush(stdin);

		}
		fflush(stdin);
		fclose(fptr);
		printf("\n\nPress any keys to proceed...\n");


	}
}

//A function to query employee details from the employees DB file
void search_employee()
{

	system("clear");
	long int mobile;
	printf("Kindly enter the mobile number of the person that you want to query: ");
	scanf("%ld",&mobile);

	FILE *fptr;
	if((fptr = fopen("employee_db", "rb")) == NULL)
	{

		printf("Error: the file could not open. Try again please !");
		printf("Press any key to proceed...\n");
		return;
	}
	else
	{

		int MAX = 0;
		employee emp;
		while (fread(&emp, sizeof(emp), 1, fptr) == 1)
		{
				

			if(emp.emp_Mobile_No == mobile)
			{

				 printf("\t\t\t\t******************************************************************************************************* \n");
                		 printf("        NAME\t\t\t\t     Country Code\t\t        ID NO.\t\t      MOBILE NO.\t\t  GENDER\t\t      EMAIL\t\t\n\n");
               			 printf("----------------------------------------------------------------------------------------------------------------");
				 int i; 
				 int emp_Name_Size = 40 - strlen(emp.emp_Name);
                       		 int emp_Country_Size = 19 - strlen(emp.emp_Country_Code);
                     	         int emp_ID_Size = 19 - strlen(emp.emp_ID_Card);
                                 int emp_Mobile_Size = 15;
                                 int emp_gender_Size = 21 -strlen(emp.emp_gender);
                                 int emp_mail_Size = 30 - strlen(emp.emp_email);
				 printf("%s",emp.emp_Name);
   	                         for (i=0;i<emp_Name_Size;i++); printf("   ");

            	                 printf("%s",emp.emp_Country_Code);
                     	         for (i=0; i<emp_Country_Size; i++); printf("   ");

                     	         printf("%s",emp.emp_ID_Card);
                       		 for (i=0; i<emp_ID_Size; i++); printf("   ");

                   	         printf("%ld",emp.emp_Mobile_No);
                       		 for (i=0; i<emp_Mobile_Size; i++); printf("   ");

                   	         printf("%s",emp.emp_gender);
                      	         for (i=0; i<emp_gender_Size; i++); printf("   ");

                       		 printf("%s",emp.emp_email);
                        	 printf("\n");
                     	         
				 MAX = 1;
				 break;

			}
			//else continue;
			//fflush(stdin);
		}
		if (MAX == 0)
		{

			system("clear");
			printf("Employee is not in the Database File\n");
		}
		fflush(stdin);
		fclose(fptr);
		printf("\n\nKindly press any key to continue...\n");

	}

}



//A function to delete employee's record/details
void wipe_employee()
{

	system("clear");
	long int mobile;
	printf("PLease enter the employees number you want to delete: ");
	scanf("%ld", &mobile);

	FILE *fptr,*temporary;
	temporary = fopen("temporary","wb+");
	if((fptr = fopen("employee_db", "rb")) ==NULL)
	{

		printf("Error: Could not open the file...!\n");
		printf("press any key to proceed\n");
		return;
	}
	else
	{

		employee emp;
		int MAX = 0;
		while(fread(&emp, sizeof(emp), 1, fptr) == 1)
		{

			if (emp.emp_Mobile_No == mobile)
			{

				system("clear");
				printf("Employee is removed succesfully\n");
				MAX = 1;

			}
			else
				fwrite(&emp, sizeof(emp),1,temporary);
				fflush(stdin);
			

		}
		if(MAX == 0)
		{

			system("clear");
			printf("No records f.ound for %ld mobile number\n",mobile);
		}
		fclose(fptr);
		fclose(temporary);
		remove("employee_db");
		rename("temporary","employee_db");
		fflush(stdin);
		printf("press any key to proceed...\n");

	}

}


//A function to update employee's details
void update_employee()
{

        system("clear");
        long int mobile;
        printf("PLease enter the employees number you want to delete: ");
        scanf("%ld", &mobile);

        FILE *fptr,*temporary;
        temporary = fopen("temporary","wb+");
        if((fptr = fopen("employee_db", "rb")) ==NULL)
        {

                printf("Error: Could not open the file...!\n");
                printf("press any key to proceed\n");
                return;
        }
        else
        {

               
                int MAX = 0;
		employee emp;
                while(fread(&emp, sizeof(emp), 1, fptr) == 1)
                {

			if(emp.emp_Mobile_No == mobile)
			{

				accept_input(&emp);
				fwrite(&emp,sizeof(emp),1,temporary);
				system("clear");
				printf("Data updated successfully\n");
				MAX = 1;

			}

			else
				fwrite(&emp,sizeof(emp),1,temporary);
				fflush(stdin);
		}
			if(MAX == 0)
			{
				system("clear");
				printf("No record found for %ld employee mobile number\n",mobile);

			}
			fclose(fptr);
			fclose(temporary);
			remove("employee_db");
			rename("temporary","employee_db");
			fflush(stdin);
			printf("Press any key to continue...\n");
		}

}



//A function to purge all employees from the database file
void wipe_all_employees()
{
	char select;
	system("clear");
	remove("./employee_db");
	// printf("Do you really want to delete all employees records? [Y/N]");
	// scanf("%c",&select);
	// if(select == 'y' || select == 'Y')
	// else return;
	printf("All data in the DB deleted succesfully\n");
	printf("Press any key to proceed ...\n");
}
