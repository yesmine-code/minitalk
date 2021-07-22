#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "minitalk.h"

static int size;
static char c;

void find_char()
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

void sigusr_handler(int sig, siginfo_t *siginfo, void *context)
{
  int i;
  
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
    write(1, "error", 5);
    size = 0;
    c = 0;
  }
}

int main()
{
  int pid;

  c = 0;
  size = 0;
  pid = getpid();
  printf_pid();

  struct sigaction act;
  act.sa_sigaction = &sigusr_handler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
 
	sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
 
  while(1)
    pause();
  return 0;
}
