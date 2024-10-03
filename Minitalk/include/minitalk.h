#ifndef MINITALK_H
# define MINITALK_H

# define SIGUSR1 10
# define SIGUSR2 12

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <aio.h>
# include "../Printf/ft_printf.h"

void 			signal_handler(int sign);
void			char_to_bit(int pid, int c);
void			send_str(int pid, char *str);
void			siguser_handler(int signal, siginfo_t *info, void *context);
int				ft_atoi(char *str);

#endif