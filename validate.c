/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:52:47 by steh              #+#    #+#             */
/*   Updated: 2022/03/28 19:41:30 by steh             ###   ########.fr       */
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
	int		fd;
	int		is_rect;
	size_t	col_len;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0) 
	{ 
		perror("r1");
		exit(1); 
	}
	line = get_next_line(fd);
	col_len = ft_strlen(line);
	/// check len continue
	while (line)
	{
		if (ft_strlen(line) != col_len)
			is_rect = 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (is_rect)
		return (1);
	return (0);
}

int	map_validity(char *file)
{
	if (!is_ber(file) || !is_rectangular(file))
		return (1);
	return (0);
}