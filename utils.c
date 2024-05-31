#include "cub3d.h"

static int		get_size(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
		if (!ft_strchr(charset, *str++))
			count++;
	return (count);
}

static void		import_str(char **dest, char *src, int start, int end)
{
	if (!(*dest = malloc(((end - start + 1) * sizeof(char)))))
		return ;
	ft_strncpy(*dest, src, end - start);
	(*dest)[end - start] = '\0';
}

char			**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (str == 0)
		return (0);
	if (!(strs = malloc((get_size(str, charset) + 1) * sizeof(char *))))
		return (0);
	while (str[j] != '\0')
	{
		i = j;
		while (!ft_strchr(charset, str[j]) && str[j] != '\0')
			j++;
		if (i != j)
			import_str(&strs[k++], &str[i], i, j);
		else
			j++;
	}
	strs[k] = 0;
	return (strs);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		t;

	i = 0;
	t = 0;
	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[t])
	{
		dest[i] = s2[t];
		t++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (0);
	while (str[i])
	{
		dest[i] = (char)str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
