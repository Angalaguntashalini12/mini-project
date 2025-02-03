#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
char TITLE[100];
char AUTHOR[100];
int ID;
};
void addbook()
{
    struct book b;
    FILE*file=fopen("library.txt","ab");
    if(!file)
    {
        printf("error opening file!\n");
        return;
    } 
    printf("enter book ID:");
    scanf("%d",&b.ID);
    printf("enter TITLE:");
    scanf("%[^\n]",b.TITLE);
    printf("enter AUTHOR:");
    scanf("%[^\n]",b.AUTHOR);
    fwrite(&b,sizeof(b),1,file);
    fclose(file);
    printf("book added successfully\n");
}
void DisplayBooks()
{
    struct book b;
    FILE*file=fopen("library.txt","rb");
    if(!file){
        printf("no book is available!\n");
        return;
    
    }
    printf("\nID\tTITLE\tAUTHOR\n");
    while(fread(&b,sizeof(b),1,file))
{
    printf("%d\t%s\t%s\n",b.ID,b.TITLE,b.AUTHOR);
}
    fclose(file);
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n 1.addbook\n 2.DisplayBooks\n 3.Exit\n Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addbook();break;
            case 2: DisplayBooks();break;
            case 3: exit(0);
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;    
}
