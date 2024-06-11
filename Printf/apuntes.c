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


Explicación
Inclusión de la biblioteca y prototipos de funciones:

Se incluye stdarg.h para usar va_list y funciones relacionadas.
Se declara un prototipo para cada función utilizada en ft_check_format.
Definición de funciones auxiliares:

ft_putchar: Escribe un carácter en la salida estándar.
ft_putstr: Escribe una cadena de caracteres en la salida estándar.
ft_putnbr: Escribe un número entero en la salida estándar.
ft_putunsigned: Escribe un número entero sin signo en la salida estándar.
ft_puthexa: Convierte un número entero sin signo a hexadecimal y lo escribe en la salida estándar.
ft_putptr: Convierte un puntero a una representación hexadecimal y lo escribe en la salida estándar con el prefijo 0x.
Función ft_check_format:

Verifica el carácter de formato y llama a la función apropiada para manejar ese formato.
Se corrige la cadena de base para el formato %X.
Función ft_printf:

Itera sobre la cadena de entrada str.
Si encuentra un %, llama a ft_check_format con el siguiente carácter.
Si no, simplemente escribe el carácter actual.
Al final, retorna el conteo total de caracteres escritos.
Con estas correcciones, el código debe funcionar correctamente para todos los formatos especificados.


    #include <stdarg.h>
#include <unistd.h>

// Prototipos de funciones necesarias
int ft_putchar(char c);
int ft_putstr(const char *s);
int ft_putnbr(int n);
int ft_putunsigned(unsigned int n);
int ft_puthexa(unsigned int nb, const char *base);
int ft_putptr(unsigned long long ptr);

// Definición de las funciones auxiliares
int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(const char *s) {
    int count = 0;
    while (*s) {
        count += ft_putchar(*s);
        s++;
    }
    return count;
}

int ft_putnbr(int n) {
    int count = 0;
    if (n == -2147483648) {
        count += ft_putstr("-2147483648");
        return count;
    }
    if (n < 0) {
        count += ft_putchar('-');
        count += ft_putnbr(-n);
    }
    if (n >= 10) {
        count += ft_putnbr(n / 10);
    }
    count += ft_putchar((n % 10) + '0');
    return count;
}

int ft_putunsigned(unsigned int n) {
    int count = 0;
    if (n >= 10) {
        count += ft_putunsigned(n / 10);
    }
    count += ft_putchar((n % 10) + '0');
    return count;
}

int ft_puthexa(unsigned int nb, const char *base) {
    int count = 0;
    if (nb < 16) {
        count += ft_putchar(base[nb]);
    } else {
        count += ft_puthexa(nb / 16, base);
        count += ft_putchar(base[nb % 16]);
    }
    return count;
}

int ft_putptr(unsigned long long ptr) {
    int count = 0;
    count += ft_putstr("0x");
    count += ft_puthexa(ptr, "0123456789abcdef");
    return count;
}

// Función ft_check_format
int ft_check_format(const char *format, va_list args) {
    int count = 0;
    if (*format == '%')
        count += ft_putchar('%');
    else if (*format == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (*format == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (*format == 'd' || *format == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if(*format == 'u')
        count += ft_putunsigned(va_arg(args, unsigned int));
    else if (*format == 'x')
        count += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
    else if (*format == 'X')
        count += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if (*format == 'p')
        count += ft_putptr(va_arg(args, unsigned long long));
    return count;
}

// Función ft_printf
int ft_printf(const char *str, ...) {
    va_list args;
    int count = 0;

    va_start(args, str);
    while (*str != '\0') {
        if (*str == '%') {
            str++;
            count += ft_check_format(str, args);
            str++;
        } else {
            count += ft_putchar(*str);
            str++;
        }
    }
    va_end(args);
    return count;
}

