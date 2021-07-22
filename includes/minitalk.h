#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
void	find_char(void);
void	printf_pid(void);
void	sigusr_handler(int sig);
void	send_bytes(int pid, char *c);

#endif
