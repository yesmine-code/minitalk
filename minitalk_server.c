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
  {
    exit(EXIT_FAILURE);
  }
}

int main()
{
  struct sigaction act;

  c = 0;
  size = 0;
  printf_pid();
  act.sa_handler = sigusr_handler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  while(1)
    pause();
	exit(EXIT_SUCCESS);
}
