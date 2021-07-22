#include "minitalk.h"

static int size;
static char c;

void find_char(void)
{  
  char bit;

  bit = 1;
  c |= (bit << (size));
}

void		printf_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

void sigusr_handler(int sig)
{
  if(sig == SIGUSR1)
    find_char();
  size++;
  
  if(size == 8)
  {
    write(1, &c, 1);
    size = 0;
    c = 0;
  }
  else if(size > 8)
    exit(EXIT_FAILURE);
}

int main()
{
  printf_pid();
	signal(SIGUSR1, sigusr_handler);
  signal(SIGUSR2, sigusr_handler);
  while(1)
    pause();
	exit(EXIT_SUCCESS);
}
