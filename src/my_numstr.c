/*
** my_numstr.c for Libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Nov 29 16:58:09 2016 Antoine Stempfer
** Last update Fri Mar 31 15:56:13 2017 Antoine Stempfer
*/

#include "my.h"
#include <stdlib.h>

char	*my_numstr(int n)
{
  char	*res;
  int	len;
  int	i;

  len = my_numlen(ABS(n), 10) + (n < 0 ? 1 : 0);
  if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  res[len] = '\0';
  if (n < 0)
    res[0] = '-';
  i = 0;
  while (ABS(n) > 0 || i == 0)
    {
      res[len - 1 - i] = ABS(n) % 10 + '0';
      n /= 10;
      i++;
    }
  return (res);
}

char	*my_unumstr(unsigned int n)
{
  char	*res;
  int	len;
  int	i;

  len = my_unumlen(n, 10);
  if ((res = malloc(len + 1)) == NULL)
    return (NULL);
  res[len] = '\0';
  i = 0;
  while (n > 0 || i == 0)
    {
      res[len - 1 - i] = n % 10 + '0';
      n /= 10;
      i++;
    }
  return (res);
}

char	*my_unumstr_base(unsigned int n, char *base)
{
  char	*res;
  int	len;
  int	b_len;
  int	i;

  b_len = my_strlen(base);
  len = my_unumlen(n, b_len);
  if ((res = malloc(len + 1)) == NULL)
    return (NULL);
  res[len] = '\0';
  i = 0;
  while (n > 0 || i == 0)
    {
      res[len - 1 - i] = base[n % b_len];
      n /= b_len;
      i++;
    }
  return (res);
}
