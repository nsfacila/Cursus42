int	main()
{
	const char	str[] = "Mofeta";
	int			letter = 't';
	char *result;
	
	printf("Mi string busca una %c", letter);
	result = ft_strchr (str, letter);
	printf("devuelve la %c resultante, con la letra %s", letter, result);
	return (0);
}