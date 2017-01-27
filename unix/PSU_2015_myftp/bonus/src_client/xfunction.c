/*
** xfunction.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Wed May	11 15:05:40 2016 Christophe Ploujoux
** Last update	Wed May	11 15:05:40 2016 Christophe Ploujoux
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "client.h"

void	xbind(int fd, const struct sockaddr *s, size_t size)
{
  if (bind(fd, s, size) == -1)
    {
      printf(BIND_ERROR);
      if (close(fd) == -1)
	printf(CLOSE_ERROR);
      exit(EXIT_FAILURE);
    }
}

void	xlisten(int fd, int backlog)
{
  if (listen(fd, backlog) == -1) {
    printf(LISTEN_ERROR);
    if (close(fd) ==  -1)
      printf(CLOSE_ERROR);
    exit(EXIT_FAILURE);
  }
}

int	xsocket(int domain, int type, int protocol)
{
  int	ret;

  if ((ret = socket(domain, type, protocol)) == -1)
    {
      printf(SOCKET_ERROR);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int	ret;

  if ((ret = accept(sockfd, addr, addrlen)) == -1)
    {
      printf(ACCEPT_ERROR);
      if (close(sockfd) == -1)
	printf(CLOSE_ERROR);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	xconnect(int sockfd, struct sockaddr *addr, size_t size)
{
  if (connect(sockfd, addr, size) == -1)
  {
    printf(CONNECT_ERROR);
    if (close(sockfd) == -1)
      printf(CLOSE_ERROR);
    exit(EXIT_FAILURE);
  }
}
