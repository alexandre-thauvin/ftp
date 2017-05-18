
//
// Created by thauvi_a on 5/16/17.
//

#include "ftp.h"

void 		user(t_cmd *cmd)
{
  if (nb_line(cmd->cmd) < 2 && cmd->data->isConnect == false)
    write(cmd->client->client_fd, "530 Permission denied.\r\n", strlen("530 Permission denied.\r\n"));
  else if (cmd->data->isConnect)
    write(cmd->client->client_fd, "530 Can't change from guest user.\r\n", strlen("530 Can't change from guest user.\r\n"));
  else
    write(cmd->client->client_fd, "331 Please specify the password.\r\n", strlen("530 Can't change from guest user.\r\n"));

}

void 		pass(t_cmd *cmd)
{

}

void 		quit(t_cmd *cmd)
{
//exit
}

void 		help(t_cmd *cmd)
{
 // toutes les cmd
}

void 		noop(t_cmd *cmd)
{
// cf
}
