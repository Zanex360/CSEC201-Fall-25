#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char input[100];
	const char s[2] = " ";

	while (1) {
		printf("\nFML> ");
		gets(&input);

		char* arg1 = strtok(input, s);

		if (arg1 == NULL) {
			// edge case - nothing entered at all
			printf("Please enter a command. If you would like to exit, type 'quit'\n");
		}
		
		else if (strcmp(arg1, "upload") == 0) {

			char* local = strtok(NULL, s);
			char* remote = strtok(NULL, s);
			char* extra = strtok(NULL, s);

			if (local == NULL) {
				// edge case - no arguments entered
				printf("Syntax error:  upload <local filename> <remote filename>\n");
			}
			else {
				if (remote == NULL) {
					// edge case - second argument not entered
					printf("Syntax error:  upload <local filename> <remote filename>\n");
				}
				else if (extra != NULL) {
					// edge case - additional argument entered
					printf("Syntax error: 'upload' only takes two parameters.\n");
				}
				else {
					// TO DO - Implement this feature
					printf("all good!\n");
				}
			}

		}

		else if (strcmp(arg1, "download") == 0) {

			char* remote = strtok(NULL, s);
			char* local = strtok(NULL, s);
			char* extra = strtok(NULL, s);

			if (remote == NULL) {
				// edge case - no arguments entered
				printf("Syntax error:  download <remote filename> <local filename>\n");
			}
			else {
				if (local == NULL) {
					// edge case - second argument not entered
					printf("Syntax error:  download <remote filename> <local filename>\n");
				}
				else if (extra != NULL) {
					// edge case - additional argument entered
					printf("Syntax error: 'download' only takes two parameters.\n");
				}
				else {
					// TO DO - Implement this feature
					printf("all good!\n");
				}
			}
		}

		else if (strcmp(arg1, "delete") == 0) {

			char* arg2 = strtok(NULL, s);

			if (arg2 == NULL) {
				// edge case - no arguments entered
				printf("Syntax error:  delete [local|remote] <filename>\n");
			}
			else if (strcmp(arg2, "local") == 0) {

				char* file = strtok(NULL, s);
				char* extra = strtok(NULL, s);

				if (extra != NULL) {
					// edge case - additional argument entered
					printf("Syntax error: 'delete' only takes two parameters.\n");
				}
				else if (file != NULL) {
					// TO DO - Implement this feature
					printf("all good!\n");
				}
				else {
					// edge case - second argument not entered
					printf("Syntax error: Please enter a file name.\n");
				}

			}
			else if (strcmp(arg2, "remote") == 0) {

				char* file = strtok(NULL, s);
				char* extra = strtok(NULL, s);

				if (extra != NULL) {
					// edge case - additional argument entered
					printf("Syntax error: 'delete' only takes two parameters.\n");
				}
				else if (file != NULL) {
					// TO DO - Implement this feature
					printf("all good!\n");
				}
				else {
					 //edge case - second argument not entered
					printf("Syntax error: Please enter a file name.\n");
				}
			}
			else {
				// edge case - first argument entered, but does not match possible options
				printf("'%s' is not recognized. Valid options for 'delete' are 'local' and 'remote'.\n", arg2);
			}
		}

		else if (strcmp(arg1, "change") == 0) {

			char* arg2 = strtok(NULL, s);

			if (arg2 == NULL) {
				// edge case - no arguments entered
				printf("Syntax error:  change [local|remote] <filepath>\n");
			}
			else if (strcmp(arg2, "local") == 0) {

				char* file = strtok(NULL, s);
				char* extra = strtok(NULL, s);

				if (extra != NULL) {
					// edge case - additional argument entered
					printf("Syntax error: 'change' only takes two parameters.\n");
				}
				else if (file != NULL) {
					// TO DO - Implement this feature
					printf("all good!\n");
				}
				else {
					//edge case - second argument not entered
					printf("Syntax error: Please enter a file path.\n");
				}

			}
			else if (strcmp(arg2, "remote") == 0) {

				char* file = strtok(NULL, s);
				char* extra = strtok(NULL, s);

				if (extra != NULL) {
					// edge case - additional argument entered
					printf("Syntax error: 'change' only takes two parameters.\n");
				}
				else if (file != NULL) {
					// TO DO - Implement this feature
					printf("all good!\n");
				}
				else {
					//edge case - second argument not entered
					printf("Syntax error: Please enter a file path.\n");
				}
			}
			else {
				// edge case - first argument entered, but does not match possible options
				printf("'%s' is not recognized. Valid options for 'change' are 'local' and 'remote'.\n", arg2);
			}
		}

		else if (strcmp(arg1, "show") == 0) {

			char* arg2 = strtok(NULL, s);

			if (arg2 == NULL) {
				// edge case - no arguments entered
				printf("Syntax error:  show [local|remote] [files|folders|path]\n");
			}
			else if (strcmp(arg2, "local") == 0) {

				char* arg3 = strtok(NULL, s);
				char* extra = strtok(NULL, s);

				if (arg3 == NULL) {
					// edge case - second argument not entered
					printf("Syntax error:  show local [files|folders|path]\n");
				}
				else if (extra != NULL) {
					// edge case - fourth parameter
					printf("Syntax error: 'show' only takes three parameters.\n");
				}
				else if (strcmp(arg3, "files") == 0) {
					// TO DO - Implement this feature
					// show local files
					printf("Printing: show local files\n");
				}
				else if (strcmp(arg3, "folders") == 0) {
					// TO DO - Implement this feature
					// show local folders
					printf("Printing: show local folders\n");
				}
				else if (strcmp(arg3, "path") == 0) {
					// TO DO - Implement this feature
					// show local path
					printf("Printing: show local path\n");
				}
				else {
					// edge case - not files, folders, or path
					printf("'%s' is not recognized. Valid options for 'show local' are 'files', 'folders', and 'path'.\n", arg3);
				}

			}
			else if (strcmp(arg2, "remote") == 0) {

				char* arg3 = strtok(NULL, s);
				char* extra = strtok(NULL, s);

				if (arg3 == NULL) {
					// edge case - second argument not entered
					printf("Syntax error:  show remote [files|folders|path]\n");
				}
				else if (extra != NULL) {
					// edge case - fourth parameter
					printf("Syntax error: 'show' only takes three parameters.\n");
				}
				else if (strcmp(arg3, "files") == 0) {
					// TO DO - Implement this feature
					// show remote files
					printf("Printing: show remote files\n");
				}
				else if (strcmp(arg3, "folders") == 0) {
					// TO DO - Implement this feature
					// show remote folders
					printf("Printing: show remote folders\n");
				}
				else if (strcmp(arg3, "path") == 0) {
					// TO DO - Implement this feature
					// show remote path
					printf("Printing: show remote path\n");
				}
				else {
					// edge case - not files, folders, or path
					printf("'%s' is not recognized. Valid options for 'show remote' are 'files', 'folders', and 'path'.\n", arg3);
				}
			}
			else {
				// edge case - not local or remote
				printf("'%s' is not recognized. Valid options for 'show' is 'local' and 'remote'.\n", arg2);
			}
		}

		else if (strcmp(arg1, "history") == 0) {

			char* extra = strtok(NULL, s);

			if (extra != NULL) {
				// edge case - second parameter
				printf("Syntax error: 'history' takes no parameters.\n");
			}
			else {
				// TO DO - Implement this feature
				printf("all good!\n");
			}
		}

		else if (strcmp(arg1, "validate") == 0) {

			char* extra = strtok(NULL, s);

			if (extra != NULL) {
				// edge case - second parameter
				printf("Syntax error: 'validate' takes no parameters.\n");
			}
			else {
				// TO DO - Implement this feature
				printf("all good!\n");
			}
		}

		else if (strcmp(arg1, "quit") == 0) {
			printf("Goodbye!\n");
			return 0;
		}

		else {
			printf("'%s' is not a valid FML command.\n", arg1);
		}

	}

	return 0;
}