/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:08 by noam              #+#    #+#             */
/*   Updated: 2024/02/29 17:52:45 by noam             ###   ########.fr       */
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

char	**split(char *str_of_words, char sep)
{
    char *s;
    char **arr_of_words;
    int i;

	arr_of_words = (char **)malloc(sizeof(char *) * (wordcount(str_of_words, sep)));
	if (arr_of_words == NULL)
		return (NULL);
    s = skiptonext(str_of_words, sep);
    i=0;
	while (*s)
	{
		arr_of_words[i] = word_to_string(s, sep);
        while (*s && *s != sep)
            s++;
		i++;
		s=skiptonext(s, sep);
    }
	return (arr_of_words);
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
			tab[j] = word_to_string((char *)s, c, i);
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
    int i = 0;
    int nbwords;
    char **arr;
    char *str = "asdf";
    
    nbwords = wordcount(str, ' ');
    arr = split(str, ' ');
    while (i < nbwords)
    {
        printf("word %d: %s\n", i, arr[i]);
        i++;
    }
   
    
    
    // printf("wordcount %d\n", wordcount(" ", ' '));
    // printf("word_to_string %s\n", word_to_string("   world", ' '));
	// printf("split %s\n", split("   world", ' '));
	
}
