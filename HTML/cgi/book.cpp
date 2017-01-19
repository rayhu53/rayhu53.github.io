#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void covtostd( char *str )
{
   char * strtemp ;
   int length, loop, i = 0;

   length = strlen( str ) ;
   strtemp = (char *) malloc( length+1 ) ;

   for( loop = 0 ; loop < length ; loop++ )
   {
      if( str[loop] == '+' )
         strtemp[i] = ' ' ;
      else if( str[loop] == '%' )
      {
         strtemp[i] = ( str[loop+1] >= 'A' ? ( str[loop+1] - 55 ) * 16
                                           : ( str[loop+1] - 48 ) * 16 )
                    + ( str[loop+2] >= 'A' ? ( str[loop+2] - 55 )
                                           : ( str[loop+2] - 48 )) ;
         loop += 2 ;
      }
      else
         strtemp[i] = str[loop] ;

      i++ ;
   }

   strtemp[i] = 0 ;
   strcpy( str, strtemp ) ;
   free( strtemp ) ;
}

void main()
{
   char str[200] ;

   struct bookStru
   {
       char  var[20],
             value[100];
   } book[5];

   puts( "Content-type: text/html" ) ;
   puts("") ;
   gets( str ) ; /* 取得參數 */

/* printf( "參數長度為    ： %d<br>\n", length ) ;
   printf( "重整前 %s<br>\n", str ) ;
   covtostd( str ) ;
   printf( "重整後 %s<br>\n", str ) ;
   puts( "</h1>" ) ;
*/
   covtostd( str ) ;

   char var[20], value[100];
   int  i = 0, j = 0, n = 0;

   while (str[i] != NULL)
   {
       j = 0;
       while (str[i] != '=')
           book[n].var[j++] = str[i++];
       book[n].var[j] = NULL;
       i++;
       j = 0;
       while (str[i] != '&' && str[i] != NULL)
           book[n].value[j++] = str[i++];
       book[n].value[j] = NULL;
       if (str[i] == '&') i++;
       n++;
   }

   puts( "<h1>" ) ;
   printf("\n你的輸入結果為<br>");
   puts( "<HR><BR>" ) ;
   printf("\n姓名：%s<br>", book[0].value);
   printf("\n地址：%s<br>", book[1].value);
   if (book[2].value[0] == 'm')
      printf("\n性別：男<br>");
   else
      printf("\n性別：女<br>");
   printf("\n購買：%s<br>", book[3].value);
   printf("\n建議：%s<br>", book[4].value);
   puts( "</h1>" ) ;
}
