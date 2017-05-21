/*
** default.c for  in /home/thauvi_a/rendu/psu/PSU_2016_myftp/src
**
** Made by Alexandre Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun May 21 17:16:32 2017 Alexandre Thauvin
** Last update Sun May 21 17:16:35 2017 Alexandre Thauvin
*/

#include "ftp.h"

int	nb_line(char **tab)
{
  int i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	choice(t_cmd *cmd)
{
  void		(*func[11])(t_cmd *) = {user, pass, cwd, cdup,
				       quit, dele, pwd, pasv, port, help, noop};
  void		(*funci)(t_cmd *);
  int	i;

  i = 0;
  while (cmd->tab[i] != NULL && strcmp(cmd->cmd[0], cmd->tab[i]) != 0)
    i++;
  if (i <= 21)
  {
    if (i >= 11)
      i -= 11;
    funci = func[i];
    (*funci)(cmd);
  }
  else
    dprintf(cmd->client->client_fd, "500 Unknown command.\r\n");
}

bool 	check_end(char *line)
{
  int	i;

  i = 0;
  while (line)
  {
    if (line[i] == '\n')
      return (true);
    i++;
  }
  return (false);
}
