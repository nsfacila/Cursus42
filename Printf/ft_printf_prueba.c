#include "libftprintf.h"

int	ft_printf_prueba(char *str, ...)
{
	va_list	cesta;
	int		cout;

	cout = 0;
	va_start(cesta, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				cout += ft_putchar(va_arg(cesta, int));
				str++;
			}
			if (*str == 's')
			{
				cout += ft_putstr(va_arg(cesta, char *));
				str++;
			}
			if (*str == 'i' || *str == 'd')
			{
				cout += ft_putnbr(va_arg(cesta, int));
				str++;
			}
			if (*str == 'p')
			{
				cout += ft_putptr(va_arg(cesta, unsigned long long));
				str ++;
			}
			if(*str == 'x')
			{
				cout += ft_puthexa(va_arg(cesta, unsigned int), "0123456789abcdef");
				str++;
			}
			if(*str == 'X')
			{
				cout += ft_puthexa(va_arg(cesta, unsigned int), "0123456789ABCDEF");
				str++;
			}
			
		}
		else
		{
			cout += ft_putchar(*str);
			str++;
		}
	}
	return (cout);
}
/*
int	main(void)
{
	int	num;

	num = ft_printf_prueba("Tengo que imprimir esta frase sin porcentajes\n");
	printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
	num = ft_printf_prueba("Tengo que imprimir la frase mayúscula y es %s\n", 'HOLA');
	printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
	return (0);
}
*/
