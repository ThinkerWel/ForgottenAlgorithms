 #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define DTS 100

struct best{
     char message[DTS];
     char company[DTS];
     float x;
     float dep;
};
char *s_gets(char *st,int n);

int main(void)
{
    int c;
    int a=0,x=0;
    int gotten;
    struct best nt;

    puts("Enter number from 0 to 10 !");
    scanf("%d",&gotten);
    while(c=getchar()!='\n');
    {
    printf("Enter the production company of your favorite car : ");
    s_gets(nt.company,DTS);

    printf("Enter your favorite car of this company :");
    s_gets(nt.message,DTS);

    printf("Enter cost car : $");
                scanf("%f",&nt.x);

                        for(int i=0;i<254;i++){
                if(nt.message[i]>='A' && nt.message[i]<='Z')
                    a++;
                        if(nt.message[i]>='a'&& nt.message[i]<='z')
                            x++;
                            i++;

                        }

                printf("Small = %d Big = %d\n",x,a);
            printf("Company: %s, car -> %s,  cost car -> $%.2f\n ",nt.company,nt.message,nt.x);
            nt.dep=nt.x*10/50;
            printf("Discount car -> $%.2f\n",nt.dep);


    }
    if(gotten<10)
    {
    nt=(struct best) {"\tExcellent car brand !"};
    printf("%s\n",nt.message);
    }
    else
    {
        nt=(struct best) {"\tNot a bad choice !"};
      printf(" %s\n ",nt.message);
    }


}


char *s_gets(char *st,int n)
{


    char *ret_val;
    char *find;

    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
            continue;
    }
    return ret_val;
}
