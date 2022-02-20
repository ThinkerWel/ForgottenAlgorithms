#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

 char g ;
   char sed [7][7] = {"Marige","Trein","Dust","Inferno","Nuke","Place"};

    FILE *fp;
    fp=fopen("releas.c","a+");

    puts("Enter follow map play\n");
       g=getchar();

char name[100]={"\nYou Lucky programmer !!!\n "};

        switch(g)
        {

             case  'a':fprintf(fp,"%s",sed[0]);
            printf("fteel()=%d\n ",ftell(fp));
            break;

            case  'b': fprintf(fp,"%s",sed[1]);
            printf("fteel()=%d\n ",ftell(fp));
            break;

             case  'v'  : fprintf(fp,"%s",sed[2]);
             printf("fteel()=%d\n ",ftell(fp));
                    break;

            case 'g' : fprintf(fp,"%s",sed[3]);
            printf("fteel()=%d ",ftell(fp));
            break;

            case 'd' : fprintf(fp,"%s",sed[4]);


            printf("fteel()=%d\n",ftell(fp));
            break;


            case 'l' : fprintf(fp,"%s",sed[5]);
            printf("fteel()=%d\n",ftell(fp));
            break;

            default :
                printf("Try again ! ");

                break;
        }

            fputs(name,fp);
            fgets(name,100,fp);
                fprintf(stdout,"%s\n",name);



char password[]="leson";
char ps[20];

        do{
            fprintf(stdout,"\nTo exit the program, enter the password !\n");
            scanf("%s",ps);
        }while(strcmp(password,ps)!=0);

        printf("\n Great, good luck!\n ");
        fclose(fp);


        return 0;
}
