//
// Created by thauvi_a on 5/16/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"

void		default_buff(t_cmd *cmd, char * buf)
{
  if (cmd->buf_tmp == NULL)
  {
    cmd->buf_tmp = (char *) malloc((strlen(buf) + 1) * sizeof(char));
    cmd->buf_tmp = strcpy(cmd->buf_tmp, buf);
  }
  else
    cmd->buf_tmp = strcat(cmd->buf_tmp, buf);
}

void		fill_buff(char *buf, t_cmd *cmd, void (*func[])())
{
  if (check_end(buf))
  {
    if (cmd->buf_tmp == NULL)
    {
      cmd->nb_w = nb_word(buf);
      cmd->cmd = ma2d(cmd->nb_w + 1, 30);
      cmd->cmd = cmd_to_tab(buf, cmd->cmd);
    }
    else
    {
      cmd->buf_tmp = strcat(cmd->buf_tmp, buf);
      cmd->nb_w = nb_word(cmd->buf_tmp);
      cmd->cmd = ma2d(cmd->nb_w + 1, 30);
      cmd->cmd = cmd_to_tab(cmd->buf_tmp, cmd->cmd);
      cmd->buf_tmp = NULL;

    }
    choice(cmd, func);
  }
  else
    default_buff(cmd, buf);
}

int 	nb_word(char *line)
{
  int 	i;
  int 	nb;

  i = 0;
  nb = 0;
  while (line)
  {
    if (line[i] != ' ' && line[i] != '\0' && line[i] != '\r' && line[i] != '\n')
      nb++;
    while (line && line[i] != ' ')
      i++;
    while (line && line[i] == ' ')
      i++;
  }
  return nb;
}

char 	**cmd_to_tab(char *line, char **tab)
{
  int i;
  int j;
  int z;

  i = 0;
  j = 0;
  z = 0;
  while (line)
  {
    tab[i][j] = line[z];
    if (line[j] == ' ')
    {
      i++;
      j = 0;
    }
    z++;
  }
  return tab;
}

char 	**ma2d(int line, int col)
{
  int	i;
  char	**tab;

  i = 0;
  tab = (char **)malloc(line * sizeof(char *));
  while (i < 11)
  {
    tab[i] = (char *)malloc(col * sizeof(char));
    i++;
  }
  tab[i] = NULL;
  return tab;
}