/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
static char sccsid[] = "@(#)query.c	5.4 (Berkeley) %G%";
#endif /* not lint */

# include	"robots.h"

/*
 * query:
 *	Ask a question and get a yes or no answer.  Default is "no".
 */
query(prompt)
char	*prompt;
{
	register int	c, retval;
	register int	y, x;

	getyx(stdscr, y, x);
	move(Y_PROMPT, X_PROMPT);
	addstr(prompt);
	clrtoeol();
	refresh();
	retval = ((c = getchar()) == 'y' || c == 'Y');
	move(Y_PROMPT, X_PROMPT);
	clrtoeol();
	move(y, x);
	return retval;
}
