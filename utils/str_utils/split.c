/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:08 by noam              #+#    #+#             */
/*   Updated: 2024/03/01 12:57:33 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static char	*advance_to_next_word(char *s, char sep)
{
	while (*s && *s == sep)
		s++;
	return (s);
}


static	int	wordcount(char *s, char sep)
{
	int	count;

	count = 0;
	s = advance_to_next_word(s, sep);
	while (*s)
	{
		count++;
		while (*s && *s != sep)
			s++;
		s = advance_to_next_word(s, sep);
	}
	return (count);
}

static	char	*word_to_string(char *s, char sep)
{
	char	*str;
	char	*return_str;
	char	*word;
	int		word_len;

	word_len = 0;
	word = advance_to_next_word(s, sep);
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

char	**split(char *str_words, char sep)
{
	char	*s;
	char	**arr_words;
	int		i;

	arr_words = (char **)malloc(sizeof(char *) * (wordcount(str_words, sep)));
	if (arr_words == NULL)
		return (NULL);
	s = advance_to_next_word(str_words, sep);
	i = 0;
	while (*s)
	{
		arr_words[i] = word_to_string(s, sep);
		while (*s && *s != sep)
			s++;
		i++;
		s = advance_to_next_word(s, sep);
	}
	return (arr_words);
}

/* ************************************************************************** */
/*
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
*/
