/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:30:15 by dyu               #+#    #+#             */
/*   Updated: 2020/07/25 18:31:15 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_blank	*prepare_blank(void)
{
	t_blank *blank;

	blank = malloc(sizeof(t_blank));
	blank->prcs = NULL;
	blank->width = NULL;
	return (blank);
}

char	*fill_in_blank(int size, char info_padding)
{
	char *blank;

	blank = malloc(sizeof(char) * (size + 1));
	if (blank == NULL)
		return (NULL);
	ft_memset(blank, info_padding, size);
	blank[size] = '\0';
	return (blank);
}

void	free_blank(t_blank *blank)
{
	if (blank->prcs)
		free(blank->prcs);
	if (blank->width)
		free(blank->width);
	free(blank);
}
