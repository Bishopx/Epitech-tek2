/*
** server.h for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/include
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Wed May	11 12:51:13 2016 Christophe Ploujoux
** Last update	Wed May	11 12:51:13 2016 Christophe Ploujoux
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define BIND_ERROR "Error with bind\n"
# define LISTEN_ERROR "Error with listen\n"
# define GETPROTO_ERROR "Error with getprotobyname\n"
# define SOCKET_ERROR "Error with socket\n"
# define CLOSE_ERROR "Error with close\n"
# define ACCEPT_ERROR "Error with accept\n"
# define SERVER_FAILED "Server failed to load\n"
# define CONNECT_ERROR "Server failed to connect\n"
# define PROTO_ERROR "Prototype name failed\n"
# define USAGE_ERROR "Usage: ./server port path_to_folder\n"

typedef struct		s_transfert
{
  int			socket;
  int			port;
  struct sockaddr_in	addr;
  char			*ip;
  int			transfert;
}			t_transfert;

typedef struct	s_client
{
  int		sock;
  t_transfert	transfert;
  int		status;
  char		*server_ip;
  char		*name;
  char		*path;
  char		**cmd;
  char		**cmd_list;
}		t_client;

void	xbind(int fd, const struct sockaddr *s, size_t size);
void	xlisten(int fd, int backlog);
int	xsocket(int domain, int type, int protocol);
int xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void	xconnect(int sockfd, struct sockaddr *addr, size_t size);

void	my_putstr(int fd, char *str);
char	*get_next_line(int fd);
char	**split_cmd(char *str);
void	change_path(t_client *client);
char	*my_strcat(char *dest, char *src);
void	init_cmd_connected(void (*fct[8])(t_client *));

void	handle_client(t_client *client);
void	execute(t_client *client);
void	execute_loop(t_client *client);
void	execute_transfert(t_client *client);

void	cmd_user(t_client *client);
void	cmd_pass(t_client *client);
void	cmd_dele(t_client *client);
void	cmd_quit(t_client *client);

void	cmd_help(t_client *client);
void	cmd_pwd(t_client *client);
void	cmd_noop(t_client *client);
void	cmd_cwd(t_client *client);
void	cmd_cdup(t_client *client);

void	cmd_port(t_client *client);
void	cmd_retr(t_client *client);
void	cmd_store(t_client *client);
void	cmd_list(t_client *client);

void	print_pasv(t_client *client);
void	cmd_pasv(t_client *client);

int	check_arg(int ac, char **av);
char	**fill_list();

void	init_transfert(t_client *client);

#endif /* !SERVER_H_ */
