
// int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }

// int	ft_isspace(int c)
// {
// 	return (c == ' ' || c == '\t' || c == '\n'
// 		|| c == '\v' || c == '\f' || c == '\r');
// }

// int	ft_strisnumeric(const char *str)
// {
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	if (!*str)
// 		return (0);
// 	while (ft_isdigit(*str))
// 		str++;
// 	return (!*str);
// }

// int	ft_atoi(const char *str)
// {
// 	int	sign;
// 	int	nbr;

// 	sign = 1;
// 	nbr = 0;
// 	while (ft_isspace(*str))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 		if (*str++ == '-')
// 			sign = -1;
// 	while (ft_isdigit(*str))
// 		nbr = (nbr * 10) + (*str++ - '0');
// 	return (nbr * sign);
// }
