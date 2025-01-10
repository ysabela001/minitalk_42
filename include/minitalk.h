/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:13:51 by ytavares          #+#    #+#             */
/*   Updated: 2025/01/10 14:55:46 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h> 
# include "libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_client_message
{
	unsigned char	c;
	int				i;
}t_client_message;

#endif