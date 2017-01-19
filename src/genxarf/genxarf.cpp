/* This file is part of X-ARF tools.
 *
 * X-ARF tools is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * X-ARF tools is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see
 *
 *  http://www.gnu.org/licenses/
 *
 *
 * Copyright (c)
 *   2015-2017 Alexander Haase <ahaase@mksec.de>
 */


#include <iostream>
#include <cstdlib>
#include <getopt.h>

#include <xarf.hpp>


int
main(int argc, char **argv)
{
	// create new XARF report
	XARF report;


	/*
	 * parse command line arguments
	 */
	static struct option long_options[] = {
		{"from", required_argument, 0, 'f'},
		{"to", required_argument, 0, 't'},
		{"message", required_argument, 0, 'm'},
		{0}
	};

	int c, option_index;
	while (true) {
		// evaluate current argument
		c = getopt_long(argc, argv, "f:m:t:", long_options, &option_index);

		// break at end of arguments
		if (c == -1)
			break;

		switch (c) {
			case 'f':
				// set from header for report
				report.set_from(optarg);
				break;

			case 'm':
				// set message body for report
				report.set_message_body(optarg);
				break;

			case 't':
				// set to header for report
				report.set_to(optarg);
				break;


			/* An error occured.
			 * getopt already printed an error, so we don't need to print a
			 * second error message.
			 */
			case '?':
				exit(EXIT_FAILURE);
				break;

			/* The default region should *NEVER* be reached. If it is reached,
			 * there is an error in getopt implementation and we should abort
			 * here.
			 */
			default:
				abort();
		}
	}


	// print report
	std::cout << report << std::endl;


	// exit
	return EXIT_SUCCESS;
}
