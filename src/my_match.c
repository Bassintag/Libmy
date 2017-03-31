/*
** my_match.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Mar 28 15:00:44 2017 Antoine Stempfer
** Last update Tue Mar 28 15:01:56 2017 Antoine Stempfer
*/

#include "my.h"

int	my_match(char *s1, char *s2)
{
  if (*s1 == '\0' && *s2 == '\0')
    return (1);
  if (*s2 == '*')
    {
      if (*s1 == '\0')
	return (my_match(s1, s2 + 1));
      return (my_match(s1 + 1, s2) || my_match(s1, s2 + 1));
    }
  if (*s1 != *s2)
    return (0);
  return (my_match(s1 + 1, s2 + 1));
}
