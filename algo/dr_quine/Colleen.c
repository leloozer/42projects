#include <stdio.h>

/*
	Salut,
*/
int ft_function(void)
{
	int i = 12;
	return (i);
}

int	main(void)
{
/*
	Ca va?
*/
	int i;
	char	*str = "#include <stdio.h>%c%c/*%c	Salut,%c*/%cint ft_function(void)%c{%c	int i = 12;%c	return (i);%c}%c%cint	main(void)%c{%c/*%c	Ca va?%c*/%c	int i;%c	char	*str = %c%s%c;%c	i = ft_function();%c	printf(str, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10);%c	return (0);%c}%c";
	i = ft_function();
	printf(str, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10);
	return (0);
}
