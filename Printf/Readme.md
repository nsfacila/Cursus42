# Printf

## Funciones Variádicas

Las funciones variádicas son aquellas que pueden aceptar un número indeterminado de argumentos. En C, esto se logra utilizando la biblioteca `<stdarg.h>`. Cuatro macros principales se utilizan para manejar los argumentos:

- **`va_list`**: Tipo de dato que se usa para iterar sobre los argumentos.
- **`va_start`**: Inicializa una variable de tipo `va_list` para acceder a los argumentos adicionales.
- **`va_arg`**: Recupera el siguiente argumento en la lista.
- **`va_end`**: Limpia la lista de argumentos cuando se ha terminado de acceder a ellos.

## Uso de `printf` y Funciones Variádicas en C

La función `printf` es una función estándar de C utilizada para imprimir datos formateados a la salida estándar, generalmente la consola. Su prototipo se encuentra en el archivo de cabecera `<stdio.h>`.

## Sintaxis básica de `printf`
```c
int printf(const char *format, ...);
```

El primer parámetro es una cadena de formato que contiene texto y especificadores de formato (como %d, %s, %f, etc.) que indican cómo deben presentarse los valores restantes. Los tres puntos (...) indican que la función puede aceptar un número variable de argumentos.

## Especificadores de formato comunes:
- %d: Imprime un entero con signo.
- %u: Imprime un entero sin signo.
- %f: Imprime un número de punto flotante.
- %c: Imprime un carácter.
- %s: Imprime una cadena de caracteres.
- %x: Imprime un entero en formato hexadecimal (minúsculas).
- %X: Imprime un entero en formato hexadecimal (mayúsculas).
