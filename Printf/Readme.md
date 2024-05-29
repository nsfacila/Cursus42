
## Funciones Variádicas

Las funciones variádicas son aquellas que pueden aceptar un número indeterminado de argumentos. En C, esto se logra utilizando la biblioteca `<stdarg.h>`. Cuatro macros principales se utilizan para manejar los argumentos:

- **`va_list`**: Tipo de dato que se usa para iterar sobre los argumentos.
- **`va_start`**: Inicializa una variable de tipo `va_list` para acceder a los argumentos adicionales.
- **`va_arg`**: Recupera el siguiente argumento en la lista.
- **`va_end`**: Limpia la lista de argumentos cuando se ha terminado de acceder a ellos.
