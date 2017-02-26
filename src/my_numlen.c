/*
** my_numlen.c for libmy in /home/bassintag/delivery/PSU_2016/PSU_2016_my_printf/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov  9 16:45:11 2016 Antoine Stempfer
** Last update Sun Nov 13 15:38:25 2016 Antoine Stempfer
*/

int	my_numlen(int nb, int base)
{
  int	len;

  len = 1;
  while ((nb /= base) != 0)
    len++;
  return (len);
}

int	my_unumlen(unsigned int nb, int base)
{
  int	len;

  len = 1;
  while ((nb /= base) > 0)
    len++;
  return (len);
}

int	my_ulnumlen(unsigned long nb, int base)
{
  int	len;

  len = 1;
  while ((nb /= base) > 0)
    len++;
  return (len);
}
