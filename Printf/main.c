#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int num;

    // Test para el especificador de formato %d
    num = ft_printf("Tengo que imprimir el número %d\n", 42);
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir el número %d\n", 42);
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    // Test para el especificador de formato %s
    num = ft_printf("Tengo que imprimir la palabra %s\n", "hola");
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir la palabra %s\n", "hola");
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    // Test para el especificador de formato %x
    num = ft_printf("Tengo que imprimir el número hexadecimal %x\n", 255);
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir el número hexadecimal %x\n", 255);
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    // Test para el especificador de formato %X
    num = ft_printf("Tengo que imprimir el número hexadecimal %X\n", 255);
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir el número hexadecimal %X\n", 255);
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    // Test para el especificador de formato %p
    num = ft_printf("Tengo que imprimir el puntero %p\n", (void*)0x7ffeefbff618);
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir el puntero %p\n", (void*)0x7ffeefbff618);
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    // Test para el especificador de formato %c
    num = ft_printf("Tengo que imprimir el carácter %c\n", 'A');
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir el carácter %c\n", 'A');
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    // Test para el especificador de formato %%
    num = ft_printf("Tengo que imprimir el porcentaje %%\n");
    ft_printf("Me ha devuelto que ha impreso %d caracteres.\n", num);
    num = printf("Tengo que imprimir el porcentaje %%\n");
    printf("Me ha devuelto que ha impreso %d caracteres.\n", num);

    return 0;
}
