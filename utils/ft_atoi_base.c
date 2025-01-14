int	ft_atoi_base(char *nptr, int base)
{
	int	value;
	int	minus;
	int	digit;

	if (base < 2 || base > 36)
		return (0);
	value = 0;
	minus = 1;
	while (*nptr == '0' || *nptr == 'x')
		nptr++;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr)
	{
		if ('0' <= *nptr && *nptr <= '9')
			digit = *nptr - '0';
		else if ('a' <= *nptr && *nptr <= 'z')
			digit = *nptr - 'a' + 10;
		else if ('A' <= *nptr && *nptr <= 'Z')
			digit = *nptr - 'A' + 10;
		else
			break;
		if (digit >= base)
			break;
		value = value * base + digit;
		nptr++;
	}
	return (minus * value);
}
