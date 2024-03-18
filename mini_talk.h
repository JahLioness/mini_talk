/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:43:10 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/18 17:53:41 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

static int	g_sig = 0;

/* FT_UTILS */
int		ft_strlen_mini(char *str);
char	*ft_strjoin_str(char *s1, char *s2);
char	*ft_strdup_str(char *s);

#endif