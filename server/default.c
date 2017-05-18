//
// Created by thauvi_a on 5/18/17.
//

#include "ftp.h"

void	choice(t_cmd *cmd, void (*func[])())
{
  void		(*funci)();
  int	i;

  i = 0;
  while (cmd->tab[i] != NULL && cmd->cmd[0] != cmd->tab[i])
    i++;
  if (i <= 10)
  {
    funci = func[i];
    (*funci)();
  }
  else
  {
    //todo renvoie de code selon rfc
  }
}

bool 	check_end(char *line)
{
  int	i;

  i = 0;
  while (line)
  {
    if (line[i] == '\n')
      return true;
    i++;
  }
  return false;
}