#ifndef CLI_H
#define CLI_H

/** Parses command-line arguments and runs the chosen cipher.
 *  @param argc Argument count
 *  @param argv Argument vector
 *  @return 0 on success, non-zero on error
 */
int run_cli(int argc, char **argv);

#endif // CLI_H
