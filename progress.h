/* jdupes argument functions
 * This file is part of jdupes; see jdupes.c for license information */

#ifndef JDUPES_PROGRESS_H
#define JDUPES_PROGRESS_H

#ifdef __cplusplus
extern "C" {
#endif

extern void update_phase1_progress(const uintmax_t flag, const char * const restrict type);
extern void update_phase2_progress(const char * const restrict msg, const int file_percent);

#ifdef __cplusplus
}
#endif

#endif /* JDUPES_PROGRESS_H */
