
//
// Created by thauvi_a on 5/16/17.
//

#include "ftp.h"

void 		user(t_cmd *cmd)
{
  if (nb_line(cmd->cmd) < 2 && !cmd->data->isConnect)
    dprintf(cmd->client->client_fd, "530 Permission denied.\r\n");
  else if (cmd->data->isConnect)
    dprintf(cmd->client->client_fd, "530 Can't change from guest user.\r\n");
  else
  {
    dprintf(cmd->client->client_fd, "331 Please specify the password.\r\n");
    if (nb_line(cmd->cmd) > 2)
    {
      cmd->data->pseudo = (char *)malloc(3 * sizeof(char));
      cmd->data->pseudo = "lol";
    }
    else
    {
      cmd->data->pseudo = (char *) malloc(strlen((cmd->cmd[1]) + 1) * sizeof(char));
      cmd->data->pseudo = strcpy(cmd->data->pseudo, cmd->cmd[1]);
    }
    cmd->data->isLogin = true;
  }
}

void 		pass(t_cmd *cmd)
{
  if (strcmp(cmd->data->pseudo, "anonymous") == 0)
  {
    dprintf(cmd->client->client_fd, "230 Login Successful.\r\n");
    cmd->data->isConnect = true;
  }
  else
    dprintf(cmd->client->client_fd, "530 Login incorrect.\r\n");
}

void 		quit(t_cmd *cmd)
{
  dprintf(cmd->client->client_fd, "221 Gros rageux.\r\n");
  exit(0);
}

void 		help(t_cmd *cmd)
{
  dprintf(cmd->client->client_fd, "214-The following commands are recognized.\r\n");
  dprintf(cmd->client->client_fd, "USER PASS CWD CDUP QUIT\n");
  dprintf(cmd->client->client_fd, "DELE PWD PASV PORT HELP NOOP\r\n");
}

void 		noop(t_cmd *cmd)
{
  dprintf(cmd->client->client_fd, "200 Ludonoop.\r\n");
}
