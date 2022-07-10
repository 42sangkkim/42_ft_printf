/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:20:50 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 20:22:22 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_BONUS_H
# define PRINT_BONUS_H

typedef struct s_print_info
{
	char	padding;
	int		padding_len;
	char	prefix[3];
	int		zero_len;
}	t_print_info;

#endif