#include <stdio.h>
#include <string.h>
#define FT() int main()
#define fil fichier
#define rtn() return(0)

FT()
{
	FILE* fil = NULL;
	int	nb = 5;
	char name[11];
	sprintf(name, "Sully_%d.c", nb);
	fil = fopen(name, "w");
	if (fil != NULL)
	{
		char *str = "#include <stdio.h>%c#include <string.h>%c#define FT() int main()%c#define fil	fichier%c#define rtn()	return(0)%c%cFT()%c{%c	FILE* fil = NULL;%c	int nb = %d;%c	char name[11];%c	sprintf(name, %cSully_%%d.c%c, nb);%c	fil = fopen(name, %cw%c);%c	if (fil != NULL)%c	{%c		char *str = %c%s%c;%c		fprintf(fil, str, 10, 10, 10, 10, 10, 10, 10, 10, 10, (nb-1), 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10);%c		fclose(fil);%c	}%c	rtn();%c}%c";
		fprintf(fil, str, 10, 10, 10, 10, 10, 10, 10, 10, 10, (nb-1), 10, 10, 34, 34, 10, 34, 34, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10);
		fclose(fil);
	}
	rtn();
}
/// Faire une macro de preproc qui compile et execute le prog jusqu a tant que nb == 0 <<<<<<<<<
