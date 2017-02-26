/*
** my_strlen.c for my_strlen in /home/antoine.stempfer/delivery/CPool_Day04
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Oct  6 08:35:11 2016 Antoine Stempfer
** Last update Thu Oct  6 08:37:08 2016 Antoine Stempfer
*/

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (*str != '\0')
    {
      str += 1;
      len += 1;
    }
  return (len);
}
