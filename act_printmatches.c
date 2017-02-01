/* Print matched file sets
 * This file is part of jdupes; see jdupes.c for license information */

#include <stdio.h>
#include "jdupes.h"
#include "jody_win_unicode.h"
#include "act_printmatches.h"

extern void printmatches(file_t * restrict files)
{
  file_t * restrict tmpfile;
  int printed = 0;

  while (files != NULL) {
    if (ISFLAG(files->flags, F_HAS_DUPES)) {
      printed = 1;
      if (!ISFLAG(flags, F_OMITFIRST)) {
        if (ISFLAG(flags, F_SHOWSIZE)) printf("%jd byte%c each:\n", (intmax_t)files->size,
         (files->size != 1) ? 's' : ' ');
        fwprint(stdout, files->d_name, 1);
      }
      tmpfile = files->duplicates;
      while (tmpfile != NULL) {
        fwprint(stdout, tmpfile->d_name, 1);
        tmpfile = tmpfile->duplicates;
      }
      if (files->next != NULL) printf("\n");

    }

    files = files->next;
  }

  if (printed == 0) fprintf(stderr, "No duplicates found.\n");

  return;
}
