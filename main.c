/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:02:37 by sjang             #+#    #+#             */
/*   Updated: 2016/11/05 11:02:38 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
	char *str = NULL;
	int size[3];

	size[0] = ft_printf("Bla bla %#-+03*.o", 0, 0);
	printf("%s\n", "");
	size[1] = printf("Bla bla %#-+03*.o", 0, 0);
	printf("%s\n", "");
	// size[3] = printf("Bla bla %.*d\n", -45, 0);
	printf("my size: %d\n", size[0]);
	printf("sy size: %d\n", size[1]);
	return (0);
}
