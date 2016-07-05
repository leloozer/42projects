#include <stdio.h>
#define FT() int main()
#define fil	fichier
#define rtn() return(0)

FT()
{
	FILE*	fil = NULL;
	fil = fopen("Grace_kid.c", "w");
	if (fil != NULL)
	{
		char	*str = "#include <stdio.h>%c#define FT() int main()%c#define fil	fichier%c#define rtn() return(0)%c%cFT()%c{%c	FILE*	fil = NULL;%c	fil = fopen(%cGrace_kid.c%c, %cw%c);%c	if (fil != NULL)%c	%c%c		char	*str = %c%s%c;%c		fprintf(fil, str, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 10, 10, 123, 10, 34, str, 34, 10, 10, 10, 125, 10, 10, 10);%c		fclose(fil);%c	%c%c	rtn();%c}%c";
		fprintf(fil, str, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 10, 10, 123, 10, 34, str, 34, 10, 10, 10, 125, 10, 10, 10);
		fclose(fil);
	}
	rtn();
}
