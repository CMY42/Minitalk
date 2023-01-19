/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:44 by cmansey           #+#    #+#             */
/*   Updated: 2023/01/19 15:42:00 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ENVOYER LE SIGNAL EN L'ENCRYPTANT EN BITS 0 OU 1
//CHAQUE CARACTERE CORRESPOND A 8 BITS
//PAS OUBLIER LE /0 A LA FIN
void	send_signals(int serv_pid, char *string)
{
	size_t	i;
	int		j;

	i = -1;
	j = 7;
	while (++i < ft_strlen(string))
	{
		while (j >= 0)
		{
			if ((string[i] >> j & 1) == 0)
				kill(serv_pid, SIGUSR1);
			else
				kill(serv_pid, SIGUSR2);
			usleep (42);
			j--;
		}
		j = 7;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(serv_pid, SIGUSR1);
		usleep(42);
	}
}

//ON A DEUX ARGUMENTS PID SERV ET LA STRING
int	main(int argc, char **argv)
{
	char	*string;
	int		serv_pid;

	if (argc == 3)
	{
		serv_pid = ft_atoi(argv[1]);
		if (!serv_pid)
		{
			ft_putendl_fd("[ERROR] Invalid PID", 2);
			return (0);
		}
		string = argv[2];
		if (!string)
		{
			ft_putendl_fd("[ERROR] Invalid STRING", 2);
			return (0);
		}
		send_signals(serv_pid, string);
	}
	else
	{
		ft_putendl_fd("[ERROR] Invalid number of arguments.", 2);
		ft_putendl_fd("Correct entry: ./client <PID> <STRING>", 2);
	}
	return (0);
}
