#include "minitalk.h"

void	send_bytes(int pid, char *c)
{
	int	i;
	int	j;

	j = 0;
	while ((size_t)j < ft_strlen(c))
	{
		i = 0;
		while (i <= 7)
		{
			if (((c[j] >> i) & 0x01) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(20);
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	send_bytes(pid, av[2]);
	send_bytes(pid, "\n");
	exit(EXIT_SUCCESS);
}
