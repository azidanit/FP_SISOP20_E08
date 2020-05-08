#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>

static int rmdirp __P((char *));
static void usage __P((void));

int
main(argc, argv)
	int argc;
	char **argv;
{
	int errors;
	int ch;
	int delete_parent_directories = 0;

	while ((ch = getopt (argc, argv, "p")) != -1) {
		switch (ch) {
		case 'p':
			delete_parent_directories = 1;
			break;
		case '?':
		default:
			usage();
			/* NOTREACHED */
		}
	}

	if (!*(argv += optind)) {
		usage ();
		/* NOTREACHED */
	}

	for (errors = 0; *argv; argv++) {
		if (!delete_parent_directories) {
			if (rmdir(*argv)) {
				warn ("%s", *argv);
				errors = 1;
			}
		} else {
			if (rmdirp(*argv)) {
				errors = 1;
			}
		}
	}

	exit(errors);
}

static int
rmdirp (path)
	char *path;
{
	char *slash;

	if (rmdir (path)) {
		warn ("%s", path);
		return -1;
	}

	for (;;) {
		slash = strrchr (path, '/');
		if (slash == NULL) {
			return 0;
		}

		/* skip trailing slash characters */
		while (slash > path && *slash == '/')
			slash--;
		if (*slash == '/')      /* don't attempt to remove root */
			return 0;
		*++slash = '\0';

		if (rmdir (path)) {
			warn ("%s", path);
			return -1;
		}
	}

	/* NOTREACHED */
}

static void
usage()
{
	fprintf(stderr, "usage: rmdir [-p] directory ...\n");
	exit(1);
}















// by california university
