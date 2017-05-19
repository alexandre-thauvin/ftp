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

void		fill_buff(char *buf, t_cmd *cmd)
{
  if (check_end(buf))
  {
    if (cmd->buf_tmp == NULL)
    {
      cmd->nb_w = nb_word(buf);
      cmd->cmd = ma2d(cmd->nb_w + 1, 30);
      cmd->cmd = cmd_to_tab(buf, cmd->cmd, cmd->nb_w);
    }
    else
    {
      cmd->buf_tmp = strcat(cmd->buf_tmp, buf);
      cmd->nb_w = nb_word(cmd->buf_tmp);
      cmd->cmd = ma2d(cmd->nb_w + 1, 30);
      cmd->cmd = cmd_to_tab(cmd->buf_tmp, cmd->cmd, cmd->nb_w);
      cmd->buf_tmp = NULL;

    }
    choice(cmd);
  }
  else
    default_buff(cmd, buf);
}

int 	nb_word(char *line)
{
  int word_count = 0;
  char * pos = (char *) line;
  while (* pos) {
    if (word_count == 0) {
      word_count = 1;
    }
    if (* pos == ' ') {
      word_count++;
    }
    pos++;
  }
  return word_count;
}

char 	**cmd_to_tab(char *str, char **tab, int nb_word)
{
  int	i;
  int	j;
  int	a;

  i = 0;
  a = 0;
  j = 0;
  if (str == NULL)
    return (0);
  while (i < nb_word)
  {
    while (str[a] != ' ' && str[a] != '\0' && str[a] != '\n')
      tab[i][j++] = str[a++];
    tab[i][j] = '\0';
    j = 0;
    a++;
    i++;
  }
  tab[i] = 0;
  return (tab);
}

char 	**ma2d(int line, int col)
{
  int	i;
  char	**tab;

  i = 0;
  tab = (char **)malloc((line + 1) * sizeof(char *));
  while (i < line)
  {
    tab[i] = (char *)malloc(col * sizeof(char));
    i++;
  }
  tab[i] = NULL;
  return tab;
}