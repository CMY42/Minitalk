/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:44 by cmansey           #+#    #+#             */
/*   Updated: 2023/01/16 11:46:05 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ENVOYER LE SIGNAL EN L'ENCRYPTANT EN BITS 0 OU 1
//CHAQUE CARACTERE CORRESPOND A 8 BITS
void	send_signals(int serv_pid, char *string)
{
	int	len;
	int	i;
	int	j;

	len = strlen(string);
	i = -1;
	j = 7;
	while (++i < len)
	{
		while (j >= 0)
		{
			if ((string[i] >> j & 1) == 0)
				kill(serv_pid, SIGUSR1);
			else
				kill (serv_pid, SIGUSR2);
			usleep (42);
			j--;
		}
		j = 7;
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
