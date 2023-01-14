/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:44 by cmansey           #+#    #+#             */
/*   Updated: 2023/01/12 18:05:44 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ENVOYER LE SIGNAL EN L'ENCRYPTANT EN BITS 0 OU 1
//CHAQUE CARACTERE CORRESPOND A 8 BITS
void	send_signals(int serv_pid, char *string)
{
	int len;
	char *bits;
	int i;
	int j;

	len = strlen(string);
	*bits = (char *)malloc(len*8 + 1);
	bits[len*8] = '\0';
	i=0,
	j=7;
	while(i<len)
	{
		while(j>=0)
		{
			bits[i*8 + (7-j)] = ((str[i] >> j) & 1);
			if (bits == 0)
				kill(pid, SIGUSR1);
			else if (bits == 1)
				kill (pid, SIGUSR2);
			usleep (42);
			j--;
		}
		i++;
		j=7;
	}
	return;
}

//ON A DEUX ARGUMENTS PID SERV ET LA STRING
int main(int argc, char **argv)
{
	char	*string;
	int		serv_pid;

	if (argc == 3)
	{
		serv_pid = ft_atoi(argv[1]);
		if (!serv_pid)
		{
			ft_putendl_fd("[ERROR] Invalid PID", 2);
			return;
		}
		string = argv[2];
		if (!string)
		{
			ft_putendl_fd("[ERROR] Invalid STRING", 2);
			return;
		}
		send_signals(serv_pid, string);
	}
	else
		ft_putendl_fd("[ERROR] Invalid number of arguments.\n Correct entry: ./client <PID> <STRING>", 2);
	return;
}
