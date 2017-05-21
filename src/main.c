//
// Created by thauvi_a on 5/10/17.
//

#include <stdio.h>
#include "ftp.h"

char		**fill_tab(char **tab)
{
  tab[0] = "USER";
  tab[1] = "PASS";
  tab[2] = "CWD";
  tab[3] = "CDUP";
  tab[4] = "QUIT";
  tab[5] = "DELE";
  tab[6] = "PWD";
  tab[7] = "PASV";
  tab[8] = "PORT";
  tab[9] = "HELP";
  tab[10] = "NOOP";
  tab[11] = "user";
  tab[12] = "pass";
  tab[13] = "cwd";
  tab[14] = "cdup";
  tab[15] = "quit";
  tab[16] = "dele";
  tab[17] = "pwd";
  tab[18] = "pasv";
  tab[19] = "port";
  tab[20] = "help";
  tab[21] = "noop";
  return tab;
}

void 		dele(t_cmd *cmd)
{
  if (unlink(cmd->cmd[1]) == 0)
    dprintf(cmd->client->client_fd, "250 File deleted.\r\n");
  else
    dprintf(cmd->client->client_fd, "550 Permission denied.\r\n");
}

void 		handle_client(t_client *init)
{
  char 		buf[255];
  t_data	dat;
  t_cmd		cmd;

  cmd.client = init;
  dat.isConnect = false;
  cmd.data = &dat;
  cmd.buf_tmp = NULL;
  cmd.tab = ma2d(11, 5);
  cmd.tab = fill_tab(cmd.tab);
  cmd.data->isLogin = false;
  cmd.data->path = init->path;
  cmd.data->up_path = init->path;
  dprintf(cmd.client->client_fd, "220 All rights\r\n");
  while (read(init->client_fd, buf, 255) > 0)
    fill_buff(buf, &cmd);
}

void		init_var(t_client *init, char **av)
{
  init->s_in_size = sizeof(init->s_in_client);
  init->port = atoi(av[1]);
  init->pe = getprotobyname("TCP");
  if (!init->pe)
    exit(1);
  init->s_in.sin_family = AF_INET;
  init->s_in.sin_port = htons(init->port);
  init->s_in.sin_addr.s_addr = INADDR_ANY;
  init->path = (char *)malloc((strlen(av[2]) + 1) * sizeof(char));
  init->path = strcpy(init->path, av[2]);
  if (chdir(init->path) != 0)
  {
    printf("bad path\n");
    exit(1);
  }
  init->fd = socket(AF_INET, SOCK_STREAM, init->pe->p_proto);
  if (init->fd == -1)
    exit(1);
}

int		main(int ac, char **av)
{
  t_client	init;
  pid_t 	fpid;
  
  if (ac != 3)
  {
    printf("Usage: ./server port path\n");
    return 1;
  }
  init_var(&init, av);
  bind(init.fd, (const struct sockaddr *)&init.s_in, sizeof(init.s_in));
  listen (init.fd, 42 == -1);
  while (1)
  {
    init.client_fd = accept(init.fd, (struct sockaddr *) &init.s_in_client, &init.s_in_size);
    if (init.client_fd > 0)
      fpid = fork();
    if (fpid == 0)
	handle_client(&init);
    else
      close(init.client_fd);
  }
  close(init.fd);
}