/*
 * wycat.c
 * Author: Jared Spaulding
 * Date: Feb 20, 2020
 *
 * COSC 3750, Homework 4
 *
 * This is a simple version of the cat utility. It is designed to
 * concatinate files and print on standard output.
 *
 */

#include<stdio.h>

void standardInput(char *buffer)
{
  while (!feof(stdin)) {
    char *out = fgets(buffer, sizeof buffer, stdin);
    if (out != NULL)
      printf("%s", buffer);
  } 
  clearerr(stdin);
}

int main(int argc, char **argv)
{
  char buffer[4096];
  char *dash = "-";
  int i;

  // Check number of args
  if (argc > 1) {

    // Loop through args
    for(i=1;i<argc;i++) {

      // Check arg for dash
      if (*argv[i] == *dash) 
        standardInput(buffer);
      else {

        FILE *fp;
        fp = fopen(argv[i], "r");

        if (fp != NULL) {

          // Get num bytes of file
          fseek(fp, 0L, SEEK_END);
          long numbytes = ftell(fp);

          // reset file indicator to start of file
          fseek(fp, 0L, SEEK_SET);

          // check if buffer is big enough
          if (numbytes / sizeof buffer < 1){
            fread(buffer, sizeof buffer, numbytes, fp);
            fwrite(buffer, 1, numbytes, stdout);
          } else {
            int i;
            long size = numbytes / sizeof buffer;

            for (i = 0; i < size +1; i++) {
              long nmemb;
              const size_t readOut = fread(buffer, sizeof buffer, 1, fp);

              if (readOut == 0) {
                if (feof(fp)) 
                  nmemb = (numbytes) - (i*sizeof buffer);
                else 
                  perror("Read Error ");
              } else
                nmemb = sizeof buffer;

              const size_t writeOut = fwrite(buffer, 1, nmemb, stdout);
              if (writeOut == 0 && !feof(fp)) 
                perror("Write Error ");
            }
          }

          fclose(fp);
        } else 
          perror("Wycat");
      }
    }
  } else {
    standardInput(buffer);
  }
  return 0;
}
