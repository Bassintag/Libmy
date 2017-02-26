/*
** my_replace.c for libmy in /home/bassintag/delivery/Libmy
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Jan 18 14:38:22 2017 Antoine Stempfer
** Last update Wed Jan 18 14:42:31 2017 Antoine Stempfer
*/

char	*my_replace(char *str, char target, char new)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == target)
	str[i] = new;
      i++;
    }
  return (str);
}
