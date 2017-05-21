/*
** cmd.c for  in /home/thauvi_a/rendu/psu/PSU_2016_myftp/src
**
** Made by Alexandre Thauvin
** Login   <thauvi_a@epitech.net>
**
** Started on  Sun May 21 17:16:20 2017 Alexandre Thauvin
** Last update Sun May 21 17:16:22 2017 Alexandre Thauvin
*/

#include "ftp.h"

void 		cwd(t_cmd *cmd)
{
  if (chdir(cmd->cmd[1]) != 0)
    dprintf(cmd->client->client_fd, "550 Failed to change directory.\r\n");
  else
  {
    cmd->data->path = (char *)malloc(1024 * sizeof(char));
    getcwd(cmd->data->path, sizeof(cwd));
    dprintf(cmd->client->client_fd, "250 Success.\r\n");
  }
}

void 		cdup(t_cmd *cmd)
{
  char	*final_path;
  unsigned int 	i;
  size_t 	nb;

  nb = strlen(cmd->data->path) - 1;
  i = 0;
  final_path = (char *)malloc(strlen(cmd->data->path) * sizeof(char));
  while (cmd->data->path[nb] != '/')
    nb--;
  while (i < nb + 1)
  {
    final_path[i] = cmd->data->path[i];
    i++;
  }
  final_path[i] = '\0';
  chdir(final_path);
  free(final_path);
  getcwd(cmd->data->path, sizeof(cwd));
  dprintf(cmd->client->client_fd, "250 Success.\r\n");
}

void 		pwd(t_cmd *cmd)
{
  char cwd[1024];

  if (cmd->data->isConnect)
  {
    getcwd(cwd, sizeof(cwd));
    dprintf(cmd->client->client_fd, "257 %s\r\n", cwd);
  }
  else
    dprintf(cmd->client->client_fd, "530 Please login with USER and PASS\r\n");
}

void 		pasv(t_cmd *cmd)
{
  if (!cmd->data->isConnect)
    dprintf(cmd->client->client_fd, "530 Please login with USER and PASS\r\n");
}

void 		port(t_cmd *cmd)
{
  if (!cmd->data->isConnect)
    dprintf(cmd->client->client_fd, "530 Please login with USER and PASS\r\n");
}
