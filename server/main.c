//
// Created by thauvi_a on 5/10/17.
//

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
  return tab;
}

void 		dele(t_cmd *tab)
{
 //unlink(fichier) cf code erreur
}

void 		handle_client(t_client *init)
{
  char 		buf[255];
  t_data	dat;
  t_cmd		cmd;

  cmd.client = init;
  dat.isConnect = false;
  dat.isLogin = false;
  cmd.data = &dat;
  cmd.buf_tmp = NULL;
  cmd.tab = ma2d(12, 5);
  cmd.tab = fill_tab(cmd.tab);
  write(cmd.client->client_fd, "220 All rights\r\n", strlen("220 All rights\r\n"));
  while (read(init->client_fd, buf, 255) > 0)
  {
    fill_buff(buf, &cmd);
    if (cmd.data->code == 221)
    {
      write(cmd.client->client_fd, "221 Cya\r\n", strlen("221 Cya\r\n"));
      return ;
    }
  }
}

void		init_var(t_client *init, char *av)
{
  init->s_in_size = sizeof(init->s_in_client);
  init->port = atoi(av);
  init->pe = getprotobyname("TCP");
  init->s_in.sin_family = AF_INET;
  init->s_in.sin_port = htons(init->port);
  init->s_in.sin_addr.s_addr = INADDR_ANY;
}

int		main(int ac, char **av)
{
  t_client	init;
  pid_t 	fpid;
  
  if (ac != 2)
    return 1;
  init_var(&init, av[1]);
  if (!init.pe)
    return 1;
  init.fd = socket(AF_INET, SOCK_STREAM, init.pe->p_proto);
  if (init.fd == -1)
    return 1;
  bind(init.fd, (const struct sockaddr *)&init.s_in, sizeof(init.s_in));
  listen (init.fd, 42 == -1);
  while (1)
  {
    init.client_fd = accept(init.fd, (struct sockaddr *) &init.s_in_client, &init.s_in_size);
    if (init.client_fd == 1)
      fpid = fork();
    if (fpid == 0)
	handle_client(&init);
    else
      close(init.client_fd);
    }
  close(init.fd);
}