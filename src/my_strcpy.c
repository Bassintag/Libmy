/*
** my_strcpy.c for my_strcpy in /home/antoine.stempfer/delivery/CPool_Day06
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Oct 10 07:54:45 2016 Antoine Stempfer
** Last update Mon Oct 10 18:11:51 2016 Antoine Stempfer
*/

char	*my_strcpy(char *dest, char *src)
{
  int	index;

  index = 0;
  while (src[index] != '\0')
    {
      dest[index] = src[index];
      index++;
    }
  return (dest);
}
