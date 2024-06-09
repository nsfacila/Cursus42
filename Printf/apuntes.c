1)
ft_printf("Tengo que imprimir esta frase sin porcentajes\n");

ft_putchar me tiene que devolver cuántos caracteres imprime (1)

2) Imprimir un %c (carácter)
va_list, va_start, va_arg, va_end
if (... = '%')
me tiene que devolver los caracteres que ha impreso y debe imprimir los caracteres
ft_printf("Tengo que imprimir el carácter %c.\n", 'A');


va_list(a(char)) //Puede incluir numero indefinido de argumentos
va_start(va_list, str) //Inializamos la lista de argumentos que tenemos dentro de nuestro va_list
va_arg(va_list, char) //Elegimos el tipo de argumento que vamos a usar, incluyendo su tipo, char, int etc
va_end(va_list) // eliminamos lo que hay dentro de nuestra estructura de va_list y vuelve a ser indefinida, puede tener cualquier argumento dentro

int ft_printf(char *str)
{
    while (*str != '\0')
    write(1, &str, 1); // ft_putchar(str)
    str++;
}

int main()
{
    ft_printf("Tengo que imprimir esta frase sin porcentajes")
    return(0);
}

int ft_printf(char *str, ...)
{
    va_list cesta;

    va_start(cesta, str)
    while(*str)
    {
        if (*str == %)
        {
            str++;
            if(*str == 'c')
            {
                ft_putchar(va_arg(cesta, int));
                str++;
            }
        }
        else
        {
            ft_putchar(*str);
            str++;
        }
    }
}
