#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEN 30
char *s_gets(char *st,int n);

enum spectrum {Mersedes,BMW,Ford,Toyota,Lexus,Bently};
const char *car[]={"Mersedes","BMW", "Ford", "Toyota","Lexus","Bently"};

int main(void)
{
    enum spectrum cars;
    char carting[LEN];
    bool found;
        puts("Enter follower car or empty string !");
        while(s_gets(carting,LEN)!=NULL && carting[0]!='\0')
        {
            for(cars=Mersedes;cars<=Bently;cars++)
            {
                if(strcmp(carting,car[cars])==0)
                {
                    found=true;
                    break;
                }
            }
        if(found)
            switch(cars)
        {
            case Mersedes : puts("Торговая марка и одноимённая компания - производитель легковых автомобилей премиального класса, грузовых автомобилей автобусов и других транспортных средств, входящая в состав немецкого концерна «Daimler AG»");
                                 break;
            case BMW :
                puts("Немецкий производитель автомобилей, мотоциклов, двигателей, а также велосипедов");
            break;

            case Ford : puts("Американская автомобилестроительная компания, производитель автомобилей под маркой Ford");
            break;
            case Toyota :puts("Крупнейшая японская автомобилестроительная корпорация, также предоставляющая финансовые услуги и имеющая несколько дополнительных направлений в бизнесе");
                              break;
                case Lexus : puts("Марка премиальных автомобилей, производимых японской корпорацией Toyota Motor.");
                break;
                case Bently : puts("Британская автомобилестроительная компания, специализирующаяся на производстве автомобилей класса «люкс»");
                break;
        }
        else
            printf("%s Такой машины в лидирующем списке нет !",carting);
        found=false;
        }
        puts("Программа завершена");
        return 0;

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
