/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:08 by noam              #+#    #+#             */
/*   Updated: 2024/02/29 17:18:03 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static char *skiptonext(char *s, char sep)
{
    while (*s && *s == sep)
        s++;
    return (s);
}


static	int	wordcount(char *s, char sep){
    int count;

    count = 0;
    s = skiptonext(s, sep);
    while (*s)
    {
        count++;
        while (*s && *s != sep)
            s++;
        s = skiptonext(s, sep);
    }
    return (count);
}
    
static	char	*word_to_string(char *s, char sep)
{
	// int		index;
	char	*str;
    char *return_str;
    char *word;
    int word_len;
    
    word_len = 0;
    word = skiptonext(s, sep);
    s = word;
    while (*s && *s != sep)
    {
		s++;
        word_len++;
    }
    return_str = (char *)malloc(sizeof(char) * word_len + 1);
    s = word;
    str = return_str;
    while (*s && (*s != sep))
    {
		*str = *s;
        str++;
        s++;
    }
    *str = '\0';
	return (return_str);
}
/*
char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (wordcount((char *)s, c) + 2));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			tab[j] = wordcopy((char *)s, c, i);
			j++;
		}
		while (s[i] && (s[i] != c))
			i++;
	}
	tab[j] = 0;
	return (tab);
}
*/
/* ************************************************************************** */

int	main(void)
{
	printf("wordcount %d\n", wordcount(" ", ' '));
	printf("word_to_string %s\n", word_to_string("   world", ' '));
}
