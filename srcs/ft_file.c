/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:08:40 by jlepere           #+#    #+#             */
/*   Updated: 2017/01/11 14:43:42 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

t_file		*ft_open_file(char *filename)
{
	t_file	*file;

	if (!filename || !(file = ft_memalloc(sizeof(struct s_file))))
		return (NULL);
	if ((file->fd = open(filename, O_RDONLY)) == -1)
		return (ft_free_file(file));
	file->read = NULL;
	file->buffer = NULL;
	return (file);
}

void		*ft_free_file(t_file *file)
{
	if (!file)
		return (NULL);
	if (file->fd > 0)
		close(file->fd);
	if (file->read)
		ft_strdel(&file->read);
	if (file->buffer)
		ft_strdel(&file->buffer);
	ft_memdel((void**)&file);
	return ((file = NULL));
}

static int	ft_read_file(t_file *file)
{
	char	*tmp;

	if (!file->read)
		file->read = ft_strnew(BUFF_SIZE);
	if (read(file->fd, file->read, BUFF_SIZE) == 0)
		return (0);
	tmp = file->buffer;
	file->buffer = ft_strjoin(file->buffer, file->read);
	ft_strdel(&tmp);
	return (1);
}

int			ft_next_line(t_file *file, char **line)
{
	int		size;
	char	*data;

	if (!file || !line)
		return (-1);
	if (!file->buffer && !ft_read_file(file))
		return (0);
	while (file->buffer[file->index])
	{
		if (file->buffer[file->index] == '\n')
		{
			data = file->buffer;
			*line = ft_strsub(file->buffer, 0, file->index);
			if ((size = ft_strlen(file->buffer) - file->index) > 1)
				file->buffer = ft_strsub(file->buffer, file->index + 1, size);
			else
				file->buffer = NULL;
			ft_strdel(&data);
			return ((file->index = 0) + 1);
		}
		if (++file->index == (int)ft_strlen(file->buffer))
			ft_read_file(file);
	}
	return (0);
}
