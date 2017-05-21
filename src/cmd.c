//
// Created by thauvi_a on 5/16/17.
//

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
  //getcwd
 //chdir tout path
  (void)cmd;
  /*else
  dprintf(cmd->client->client_fd, "530 Please login with USER and PASS\r\n");*/
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