/*
** my_memset.c for libmy in /home/bassintag
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec  7 13:23:47 2016 Antoine Stempfer
** Last update Wed Dec  7 13:26:18 2016 Antoine Stempfer
*/

void	my_memset(char *addr, char c, int size)
{
  while (--size >= 0)
    addr[size] = c;
}
