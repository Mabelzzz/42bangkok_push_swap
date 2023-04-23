/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:32:54 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 12:48:58 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_split(t_stc *stack, char *s, char c);
char	**keep_word(char **word, char *s, char c);
char	*keep_alphabet(char *s, char c);
size_t	cnt_alphabet(char *s, char c);
size_t	cnt_word(char *s, char c);

char	**ft_split(t_stc *stack, char *s, char c)
{
	char	**word;
	size_t	cnt;

	cnt = cnt_word(s, c);
	if (cnt == 0)
		error_free(stack);
	if (!s)
		return (NULL);
	word = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!word)
		return (NULL);
	word = keep_word(word, s, c);
	return (word);
}

char	**keep_word(char **word, char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < cnt_word(s, c))
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		word[j] = keep_alphabet(&s[i], c);
		while (s[i] != 0 && s[i] != c)
			i++;
		j++;
	}
	word[j] = NULL;
	return (word);
}

char	*keep_alphabet(char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (cnt_alphabet(s, c) + 1));
	if (!word)
		return (NULL);
	while (s[i] && s[i] != c && i <= cnt_alphabet(s, c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

size_t	cnt_alphabet(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

size_t	cnt_word(char *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
