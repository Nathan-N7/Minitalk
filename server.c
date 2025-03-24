/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:52:11 by natrodri          #+#    #+#             */
/*   Updated: 2025/02/01 10:44:58 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "printf/ft_printf.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int	g_c = 0;

void	stoc(int signum)
{
	static int	i = 0;

	g_c = g_c << 1;
	if (signum == SIGUSR1)
		g_c = g_c + 1;
	i++;
	if (i == 8)
	{
		write(1, &g_c, 1);
		if (g_c == '\0')
			write(1, "\n", 1);
		i = 0;
		g_c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, stoc);
	signal(SIGUSR2, stoc);
	ft_printf("\033[31m███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗\033[0m\n");
	ft_printf("\033[31m██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\033[0m\n");
	ft_printf("\033[31m███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\033[0m\n");
	ft_printf("\033[31m╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\033[0m\n");
	ft_printf("\033[31m███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\033[0m\n");
	ft_printf("\033[31m╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\033[0m\n\n");
	ft_printf("\033[37mServer PID = %d\033[0m\n", getpid());
	while (1)
		pause();
	return (0);
}
