#include "../includes/alphavim.h"

/*
 * String utility module for Alphavim
 *
 * Provides compact and fast string manipulation functions.
 *
 * Functions:
 *   - my_strlen(const char *s): Returns length of string.
 *   - my_strcpy(char *dest, const char *src): Copies string.
 *   - my_strncpy(char *dest, const char *src, int n): Copies up to n chars.
 *   - my_strcmp(const char *a, const char *b): Compares strings.
 *   - my_strncmp(const char *a, const char *b, int n): Compares up to n chars.
 */

/*
 * Returns the length of string 's'.
 */
int my_strlen(const char *s);

/*
 * Copies string 'src' to 'dest'.
 */
void my_strcpy(char *dest, const char *src);

/*
 * Copies up to 'n' characters from 'src' to 'dest'.
 */
void my_strncpy(char *dest, const char *src, int n);

/*
 * Compares two strings, returns 0 if equal.
 */
int my_strcmp(const char *a, const char *b);

/*
 * Compares up to 'n' characters of two strings.
 */
int my_strncmp(const char *a, const char *b, int n);

int my_strlen(const char *s) { int l=0; while(s[l])++l; return l; }
void my_strcpy(char *d, const char *s) { int i=0; while((d[i]=s[i]))++i; }
void my_strncpy(char *d, const char *s, int n) { int i=0; while(i<n && (d[i]=s[i]))++i; if(i<n) d[i]=0; }
int my_strcmp(const char *a, const char *b) { int i=0; while(a[i]&&b[i]&&a[i]==b[i])++i; return a[i]-b[i]; }
int my_strncmp(const char *a, const char *b, int n) { int i=0; while(i<n&&a[i]&&b[i]&&a[i]==b[i])++i; return i==n?0:a[i]-b[i]; }
