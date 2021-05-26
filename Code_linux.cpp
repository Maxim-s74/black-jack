#ifndef __MINGW32__

#include "main.h"
#include "code_linux.h"

// get a single char from stdin

int getch(void)
{
   struct termios oldattr;
   struct termios newattr;
   int ch;
   tcgetattr(0, &oldattr);
   newattr=oldattr;
   newattr.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( 0, TCSANOW, &newattr);
   ch=getchar();
   tcsetattr(0, TCSANOW, &oldattr);
   return(ch);
}


void strupr (char *str) {
//	while(*str) *str++ = toupper(*str);
	int i=0;

	while (str[i]!=0) {
		str[i]=toupper(str[i]);
		i++;
	}
}
#endif
