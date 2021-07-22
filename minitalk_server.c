#include "minitalk.h"

static int		g_size;
static char		g_c;

void	find_char(void)
{
	char	bit;

	bit = 1;
	g_c |= (bit << (g_size));
}

void	printf_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

void	sigusr_handler(int sig)
{
	if (sig == SIGUSR1)
		find_char();
	g_size++;
	if (g_size == 8)
	{
		write(1, &g_c, 1);
		g_size = 0;
		g_c = 0;
	}
	else if (g_size > 8)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	act;

	g_c = 0;
	g_size = 0;
	printf_pid();
	act.sa_handler = sigusr_handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause ();
	exit (EXIT_SUCCESS);
}
