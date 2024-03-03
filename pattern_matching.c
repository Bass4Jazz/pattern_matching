#include<stdio.h>

_Bool star_match(char*, char*);

_Bool match(char* str, char* ptn)
{
   switch(*ptn)
   {
      case 0:
         return *str == 0;

      case '?':
	if(*str)
	   return match(str + 1, ptn + 1);
	return 0;

      case '*':
	 return star_match(str, ptn + 1);

      default:
	 if(*str == *ptn) 
	    return match(str + 1, ptn + 1);
	 return 0;
   }
}

_Bool star_match(char* str, char* ptn)
{
   for(int i = 0; ; i++)
   {
      _Bool res = match(str + i, ptn);
      if(res)
         return 1;
      if(!str[i])
	 return 0;     
   }
}

int main(void)
{
   char* str = "Hello!";
   char* ptn = "*el*";

   printf("%s\n", match(str, ptn) ? "Yes" : "No");

   return 0;
}
