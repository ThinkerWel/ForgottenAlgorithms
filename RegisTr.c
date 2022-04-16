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
