//
// Created by thauvi_a on 5/10/17.
//

#include <stdio.h>
#include "ftp.h"

int		main(int ac, char **av) {
  t_client	init;
  char		*ip;
  
  if (ac != 3) {

    return 1;
  }

  ip = av[1];
  init.port = atoi(av[2]);
  init.pe = getprotobyname("TCP");
  if (!init.pe) {
    return 1;
  }

  init.fd = socket(AF_INET, SOCK_STREAM, init.pe->p_proto);
  init.s_in.sin_family = AF_INET;
  init.s_in.sin_port = htons(init.port);
  init.s_in.sin_addr.s_addr = inet_addr(ip);
  if (connect(init.fd, (struct sockaddr *)&init.s_in, sizeof(init.s_in)) == -1){
    printf("ici");
    if (close(init.fd) == -1) {
      return 1;
    }
    return 1;
  }
  write(1, "Hello World\n", strlen("Hello World\n"));

  if (close(init.fd) == -1)
    return 1;
  return 0;
}