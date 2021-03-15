#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void Insert_Data(char *name)
{
    char data;
     FILE *fptr=NULL;

    fptr=fopen(name,"a");
    if(fptr==NULL)
        {
            printf("\nError in opening the file.\n");
            return ;
        }

    printf("\n\nStart your content here(To end the file you can enter *(asterisk) in new line)\n\n");
    printf("\u2192");

    data=getchar();  //to remove blank line from the top of the text file
    while(1)
    {
        data=getchar();
        if(data=='*')
            break;
        else
            fputc(data,fptr);
    }

    fclose(fptr);
}

void New_File()        //To create a new file
{
    char name[30];
    printf("\t\tEnter a filename : ");
    scanf("%s",name);
    strcat(name,".txt");  //to only open text file
    FILE *fptr=NULL;

    fptr=fopen(name,"w");
    if(fptr==NULL)
        {
            printf("\nError in creating the file.\n");
            return ;
        }

    fclose(fptr);

    Insert_Data(name);


}

void Old_File()
{
    printf("1. To read\n2. To append\nEnter choice : ");
    int choice;
    scanf("%d",&choice);

    char name[30];
    printf("\t\tEnter a filename : ");
    scanf("%s",name);
    strcat(name,".txt");  //to only open text file
    FILE *fptr=NULL;

    if(choice==1)
    {
        fptr=fopen(name,"r");
        if(fptr==NULL)
        {
            printf("Error in opening the file.");
        }
        else
        {
            char data;
        printf("Opening the %s file ....\n\n",name);

        while((data=fgetc(fptr))!=EOF)
        {
            printf("%c",data);
        }
        }
    }
    else
    {
        fptr=fopen(name,"a");
        Insert_Data(name);
    }


    fclose(fptr);

}

void Delete_File()
{
    char name[30];
    printf("\t\tEnter a filename : ");
    scanf("%s",name);
    strcat(name,".txt");

    if (remove(name) == 0)
      printf("Deleted successfully");
   else
      printf("Unable to delete the file");
}
int main()
{
    int choice;

    while(1)
    {
        printf("\n\n\t\t\t\t==== Selection Menu ====\n\n");
        printf("1. Create a File\n2. Open a File\n3. Delete a File\n4. Exit\n\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : New_File();
            break;
            case 2 : Old_File();
            break;
            case 3 : Delete_File();
            break;
            case 4 : printf("\n\n\t\t\tGood Bye\n\n\t\t\tExiting the program....\n\n");
            sleep(3);
            exit(0);
            default : printf("\n\nInvalid Input\n\n");

        }
    }
    return 0;
}
