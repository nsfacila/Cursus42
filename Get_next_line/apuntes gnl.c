leo del fichero, meto en el saco y si hay un \n saco una parte del saco y dejo la parte restante.
en pseudocodigo:

get_next_line(fd):
    static stored = ""
    buffer = leer fd
    mientras haya algo para leer:
        stored = ft_strjoin(stored, buffer)
        si ft_strchr(stored, '\n'):
            line = extraer hasta '\n' de stored
            actualizar stored sin la parte extraída
            retornar line
    retornar lo que queda en stored si no hay '\n'


    paso a paso:
    1 extraer hasta '\n' de stored

    función extract_line(stored):
    i = 0
    mientras stored[i] no sea '\n' y stored[i] no sea fin de cadena:
        incrementar i
    si stored[i] es '\n':
        incrementar i
    line = nueva cadena con longitud i + 1
    copiar los primeros i caracteres de stored a line
    line[i] = fin de cadena
    retornar line

    2 actualizar stored sin la parte extraída

    función update_stored(stored, line):
    nueva_longitud = longitud(stored) - longitud(line)
    nueva_stored = nueva cadena con longitud nueva_longitud
    copiar desde stored[longitud(line)] hasta el final en nueva_stored
    liberar stored
    stored = nueva_stored
    retornar stored

    static char	*ft_update_stored(char *stored)
{
    int		i;
    int		j;
    char	*new_stored;

    i = 0;
    while (stored[i] != '\n' && stored[i] != '\0')
        i++;
    if (stored[i] == '\0') // Si no hay un salto de línea, no hay nada que actualizar.
        return (NULL);
    new_stored = malloc(sizeof(char) * (ft_strlen(stored) - i));
    if (!new_stored)
        return (NULL);
    j = 0;
    if (stored[i] != '\0')
    {
        i++; // Comenzar después del salto de línea.
        while (stored[i] != '\0')
        {
            new_stored[j++] = stored[i++];
        }
    }
    new_stored[j] = '\0';
    free(stored); // Asegúrate de que 'stored' no se use después de este punto en el código que llama.
    return (new_stored);
}

función read_to_stored(fd, stored):
    buffer = nueva cadena con tamaño BUFFER_SIZE + 1
    leídos = leer(fd, buffer, BUFFER_SIZE)
    mientras leídos > 0:
        buffer[leídos] = fin de cadena
        stored = ft_strjoin(stored, buffer)
        si ft_strchr(buffer, '\n') no es NULL:
            liberar buffer
            retornar stored
        leídos = leer(fd, buffer, BUFFER_SIZE)
    liberar buffer
    si leídos es -1:
        retornar NULL
    retornar stored

pointer_n = char *ft_strchr(saco, '\n');
ft_substr(saco, pointer_saco, pointer_n - pointer_saco + 1);
tmp = &SACO;
SACO = ft_strdup(pointer_n + 1)
free(tmp)

rc = read(fd, str, BUFFER_SIZE);
rc < BUFFER_SIZE => final de fichero

SACO
aldfkas\nl23333
^       ^
|       |
return aldfkas\n

FICHERO
aldfkas\nlksfdaskdf\n


leo con un BUFFER_SIZE 3


int hazloquesea()
{
    int c;
    c = 42;
    printf("la estática vale %d", c);
    //
    c = 23
}
hazloquesea(); // 42 
hazloquesea(); // 42 


int hazloqueseaestatico()
{
    static int c = 42; // SACO
    printf("la estática vale %d", c);
    //
    c = 23
}

hazloqueseaestatico(); // 42
hazloqueseaestatico(); // 23


1\n\n\n244