int main(void)
{
    char str[30];
    printf("Enter string : ");
    scanf("%s",str);
    per(&str);

}
char per(char *str)
{
   char *p=str;
    while(*p)
   {
   if(islower(*p)) *p=toupper (*p); // преобразует в заглавные буквы

       else if(isupper(*p)) *p=tolower (*p); // преобразует в строчные буквы
                  p++;
    }
    printf("%s",str);
    return str;
}



// удаляет все гласные буквы в строке ! //

char *disemvowel(const char *str)
{
  char *ans = malloc(sizeof(char) * strlen(str) + 1);
  int j = 0;
  for(int i = 0; i < strlen(str); ++i){
    switch(str[i]){
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        break;
      default:
        ans[j++] = str[i]; 
    }
  }
   ans[j] = '\0';
printf("N= %s",ans);
  return ans;
}
int main(void)
{
    char str[100];
    scanf("%s",str);
    disemvowel(&str);
}






// third program


enum dispect_er {BLUE,RED,GREEN};

typedef struct{
char *name;
enum dispect_er type;
}dispect;

void blue(dispect rt)
{
    printf("%s  цвет Неба \n ",rt.name);

}
void red(dispect rt)
{
    printf("%s цвет крови \n",rt.name);
}
void green(dispect rt)
{
    printf("%s цвет травы \n",rt.name);
}


int main(void){
dispect choice[]={
    {"Голубой",BLUE},{"Красный",RED},{"Зеленый",GREEN}
};
    for(int i=0;i<3;i++){
        switch(choice[i].type)
    {
    case BLUE:
        blue(choice[i]);
        break;
    case RED:
        red(choice[i]);
        break;
    case GREEN:
        green(choice[i]);
        break;
    }
        }
    return 0;
}
