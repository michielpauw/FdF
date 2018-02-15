#include "libft.h"

void	ft_realloc(void *s, size_t old_size, size_t new_size)
{
	size_t			i;
	unsigned char	*m;

	if (!(m = (unsigned char *)malloc(sizeof(unsigned char) * new_size)))
		return ;
	i = 0;
	while (i < old_size)
	{
		m[i] = ((unsigned char *)s)[i];
		i++;
	}
	free(s);
	s = m;
}
