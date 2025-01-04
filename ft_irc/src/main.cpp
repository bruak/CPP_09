#include "../inc/Server.hpp"
#include <csignal>
extern int sig;

void handlesig(int signum){
	cout << RED << "\nI got this signal!= [" << signum << "]" << RESET << endl;
	cout << GREEN << "exiting" << RESET << endl;
	usleep(500000);
	cout << GREEN << "exiting." << RESET << endl;
	usleep(500000);
	cout << GREEN << "exiting.." << RESET << endl;
	usleep(500000);
	cout << GREEN << "exiting..." << RESET << endl;
	usleep(500000);
	cout << GREEN << "exiting...." << RESET << endl;
	usleep(500000);
	sig = signum;
}

int main(int ac, char **av)
{
	if (ac != 3)
		return cout << "Format ./ircserv <port> <password>" << endl, 1;

	signal(SIGQUIT,handlesig);
	signal(SIGINT,handlesig);
	try {
		Server srv(av[1], av[2]);
		srv.PollStart();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
