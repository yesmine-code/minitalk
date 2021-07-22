#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	const char	*ptr;
	size_t		i;

	ptr = str;
	i = 0;
	while (ptr[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	long	nbr;

	j = ft_count(n);
	nbr = n;
	str = malloc(sizeof(char) * (ft_count(n) + 1));
	if (str != NULL)
	{
		if (nbr < 0)
		{
			str[0] = '-';
			nbr = nbr * -1;
		}
		while (nbr / 10 != 0 && j >= 0)
		{
			str[j - 1] = (nbr % 10) + '0';
			nbr = nbr / 10;
			j--;
		}
		str[j - 1] = nbr + '0';
		str[ft_count(n)] = '\0';
	}
	return (str);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' ||
	c == '\v' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	long long int	result;
	int				index;

	sign = 1;
	result = 0;
	index = 0;
	while (ft_isspace(nptr[index]) == 1)
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
		if (result > 2147483648 && sign == 1)
			return (-1);
		else if (result > 2147483648 && sign == -1)
			return (0);
	}
	return (sign * result);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_local;
	char	*src_local;

	i = 0;
	dest_local = (char *)dest;
	src_local = (char *)src;
	if (!dest && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		dest_local[i] = src_local[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str != NULL)
	{
		while (i < ft_strlen(s1))
		{
			str[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
	return (str);
}