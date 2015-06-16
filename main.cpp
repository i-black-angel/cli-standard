/**
 * @file   main.cpp
 * @author Shusheng Shao <iblackangel@163.com>
 * @date   Tue Jun 16 11:28:05 2015
 * 
 * @brief  Standards for Command Line Interfaces
 *
 * 
 */
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <config.h>

using namespace std;

#define USAGE "\
Usage: %s [OPTION]...\n\
demonstration CLI standards.\n\
\n\
    -h, --help        display this help and exit\n\
    -V, --version     display version information and exit\n\
    -n, --name=NAME   show welcome for NAME\n\
	  \n\
Report bugs to: %s\n"

static void print_version(void) {
	printf("%s (%s) %s\n", PACKAGE, PACKAGE_NAME, VERSION);
	printf("Copyright (C) 2015 Shusheng Shao\n");
}

static void print_help(void) {
	printf(USAGE, PACKAGE, PACKAGE_BUGREPORT);
}

static const struct option longopts[] = {
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'V'},
	{"name", required_argument, NULL, 'n'},
	{NULL, 0, NULL, 0}
};

int getopt_long_test(int argc, char *argv[]) {
	int opt = -1;
	int longind = 0;
	while ((opt = getopt_long(argc, argv, "hVn:", longopts, &longind)) != -1) {		
		switch (opt) {
		case 'h':
			print_help();
			exit(EXIT_SUCCESS);
		case 'V':
			print_version();
			exit(EXIT_SUCCESS);
		case 'n':
			printf("welcome '%s'\n", optarg);
			break;
		case '?':
			// option error, or argument error
			break;
		default:
			break;
		}
	}

}

int main(int argc, char *argv[])
{
	getopt_long_test(argc, argv);
    return 0;
}
