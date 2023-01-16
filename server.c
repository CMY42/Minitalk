/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:47:09 by cmansey           #+#    #+#             */
/*   Updated: 2023/01/16 16:11:05 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//AFFICHER LE PID DU PROCESS SUR STDOUT
void	show_pid(void)
{
	pid_t	pid;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
	{
		ft_putendl_fd("[Error]", 2);
		return ;
	}
	ft_putendl_fd(pid_str, 1);
	free(pid_str);
}

//FONCTION DE LA PISCINE RENVOIE PUISSANCE D'UN NOMBRE
int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

char *new_string
{
}

//PRINTF PEUT FAIRE CRASHER SIGNAL HANDLER PAS RECOMMANDE
//MIEUX DE FAIRE UN WRITE PLUS SAFE
void handler(int signum)
{
	static int result;
	static char	*final;
	static int	index;

	result = 0;
	index = 7;
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (ft_recursive_power(2, 7 - index));
	index--;
	if (index == 0)
	{
		final = new_string(final ,result);
		if (result == '\0')
		{
			ft_putendl_fd(final, 1);
			final = NULL;
		}
		index = 0;
		result = 0;
	}
}

//WHILE BOUCLE INFINIE POUR ATTENDRE UN SIGNAL,
//EN PAUSE TANT QUE PAS DE SIGNAL RECU
//SA_HANDLER SERA L'ACTION A PRENDRE QUAND RECOIT SIGUSR1 OU SIGUSR2
//SIGUSR1 ET 2 USER-DEFINED SIGNAL
//SA_FLAGS A 0 DEFINIT LE SIGNAL PAR DEFAUT A 0
int	main(void)
{
	struct sigaction	s_sigaction;

	show_pid();
	s_sigaction.sa_handler = handler;
	s_sigaction.sa_flags = SA_NODEFER;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
