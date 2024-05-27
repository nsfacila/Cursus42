# 🌟 INTRODUCCIÓN
Este proyecto tiene como objetivo entender cómo se abren, leen y cierran los archivos en un SO, y cómo se interpretran por medio de un lenguaje de programación para su posterior análisis. Esta tarea es crucial entender para un futuro programador ya que gran parte de nuestro tiempo se basa en manipular archivos para la gestión y persistencia de datos.


# 🎯 OBJETIVO
Escribir una función que devuelva una línea dentro de un archivo de texto que termine con un salto de línea char = '\n', leída desde un descriptor de archivos.


ℹ️ Para más información: [PDF](https://github.com/nsfacila/Cursus42/files/15454687/es.subject.pdf)



# 🐾 DESARROLLO
Para desarrollar este proyecto, debemos entender una serie de conceptos:

1. ¿Cómo funciona `read()`, `open()`, `close()`?
2. ¿Qué son y cómo se utilizan los descriptores de archivo?
3. ¿Qué son las variables estáticas static y cuál es su uso en el proyecto?

## 1. ¿Cómo funciona `read()`, `open()`, `close()`?
Para un mayor entendimiento, referirse a sus respectivos manuales en el terminal: 🔶 e.g: man 2 open | man 2 read | man 2 close

O consultar en estos enlaces: 👉 [read](https://linux.die.net/man/3/read) 👉 [open](https://linux.die.net/man/3/open) 👉 [close](https://linux.die.net/man/3/close)



### Pasos básicos para operar con un archivo.

1. Debemos de abrir el archivo y sus permisos y asignarle el fd correspondiente. 🔶 E.g `int fd = open('/usr/nsfacila/file.txt', O_RDWR);`.
   
- Si `fd = -1`, el archivo no existe el archivo o no se ha podido abrir correctamente.
- Si `fd > 2`, el archivo ha sido abierto correctamente.
  
2. Procedemos a leer el archivo con `int num_bytes = read(fd, buf, nbyte);`.
   
- si `num_bytes < 0`, el archivo no tiene permisos de lectura.
- si `num_bytes > 0`, el archivo ha leído num_bytes de bytes.

3. Tras haber leído num_bytes de caracteres y almacenado temporalmente en buf realizamos la tarea necesaria con los datos leídos y procedemos a cerrar nuestro archivo con close(fd).

## 2. ¿Qué son y cómo se utilizan los descriptores de archivo?
En **Unix** y **sistemas operativos** de computadora relacionados , **un descriptor de archivo** `FD` es un indicador abstracto (identificador) que se usa para acceder a **un archivo u otro recurso de entrada / salida**, como una tubería o un conector de red.

Los descriptores de archivo forman parte de la interfaz de programación de la aplicación POSIX .

**Un descriptor de archivo es un número entero no negativo**, generalmente representado en el lenguaje de programación C como el tipo int (_los valores negativos se reservan para indicar "sin valor" o una condición de error_).

| Valor entero | Nombre                | Constante simbólica `<unistd.h>` | Flujo de archivo Descriptor de archivo `<stdio.h>` |
|--------------|-----------------------|----------------------------------|----------------------------------------------------|
| 0            | Entrada estándar      | STDIN_FILENO                     | stdin                                              |
| 1            | Salida estándar       | STDOUT_FILENO                    | stdout                                             |
| 2            | Error estándar        | STDERR_FILENO                    | stderr                                             |
| > 2          | Indica el valor entero que le pertenece al archivo que está abierto | ➖              | ➖                                                  |


👉 [Fuente](https://es.abcdef.wiki/wiki/File_descriptor) 👈

Los descriptores de archivo podemos utilizarlos y obtenerlos en funciones básicas como:

* `int open(const char path, int oflag, ...)`: `path` puntero a la ruta dónde se encuentra el archivo, `oflags` cómo queremos abrir nuestro archivo. e.g:
  * solo lectura: `O_RDONLY`
  * sólo escritura: `O_WRONLY`
  * ambos: `O_RDWR`

  Librerías necesarias: `<fcntl.h>`.

* `ssize_t read(int fd, void buf, size_t nbyte)`: `fd` file descriptor, `buf` puntero de caracteres que almacena los caracteres leídos, `nbyte` número de bytes que se pretende leer por cada `read()`.

  Librerías necesarias: `<sys/types.h>`, `<sys/uio.h>`, `<unistd.h>`.

* `int close(int fd)`: `fd` file descriptor. Retorna `-1` si el archivo no se ha cerrado correctamente.

  Librerías necesarias: `<fcntl.h>`.


## 3. ¿Qué son las variables estáticas `static` y cuál es su uso en el proyecto?
Al tener restricciones en el uso de variables globales dentro de nuestro proyecto, debemos aprender lo que son las variables estáticas y para qué nos sirven. En resumen, una variable estática nos permite la persistencia de información aunque la función que la contenga se haya terminado de ejecutar. (recordemos que el ámbito de una variable nos limita desde dónde se puede acceder y manipular su contenido).

`Get_next_line()` (abreveviado: `gnl()`) es una función que nos retornará una línea por cada vez que llamemos a la función, pero debido a las instrucciones de este proyecto, el número de bytes `BUFFER_SIZE` que leamos por cada vez que llamemos a `gnl()` será determinado por el evaluador. Es decir que `BUFFER_SIZE` podrá ser un número negativo hasta un número inmensamente grande ♾️.

Por lo tanto, si pretendemos leer un archivo con 1000 líneas de texto y nuestro `BUFFER_SIZE` > Número de bytes del archivo, la lectura del archivo será en una sola llamada de `read()`, por lo que debemos hacer que nuestras líneas de texto persistan en una sola variable tras múltiples llamadas de `gnl()`.



