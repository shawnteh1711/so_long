/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:52:47 by steh              #+#    #+#             */
/*   Updated: 2022/03/26 19:06:34 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"

// check the extension is .ber -done
// must have 1 e, 1 c, 1 p 
// must be rectangular
// must surround with walls(1)

int	is_ber(char *file)
{
	char	*ext;
	int		len;

	len = ft_strlen(file);
	ext = (char *)ft_memchr(file, '.', len);
	if (!ft_strncmp(ext, ".ber", len))
		return (1);
	return (0);
}


// check map is rectangular by using get_next_line to read
// length of first line and compare length with subsequent
// line. If same length then it is same.
int	is_rectangular(char *file)
{
	const int	fd = open(file, O_RDONLY);
	char	*line;

	if (fd < 0) 
	{ 
		perror("r1");
		exit(1); 
	} 
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("\n\n");
	close(fd);
	return (0);
}

int	map_validity(char *file)
{
	if (!is_ber(file) || !is_rectangular(file))
		return (1);
	(void)(file);
	return (0);
}