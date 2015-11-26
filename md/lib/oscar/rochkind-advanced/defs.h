/* p.040 */
typedef enum {FALSE, TRUE} BOOLEAN;

#define lowbyte(w) ((w) & 0377)
#define highbyte(w) lowbyte((w) >> 8)

