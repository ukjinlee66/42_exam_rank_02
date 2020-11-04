/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:31:14 by youlee            #+#    #+#             */
/*   Updated: 2020/11/04 18:38:44 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int check[255];
	int i, j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			check[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !check[(unsigned char)argv[i][j]])
					check[(unsigned char)argv[i][j]] = 1;
				if (i == 1 && check[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					check[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
