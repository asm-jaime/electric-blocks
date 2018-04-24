#ifndef DLOG4CH_H_
#define DLOG4CH_H_

#define NULL    0

typedef struct {
  long  task;       // Variable:  Task address pointer
  int  *iptr1;      // Input: First input pointer (Q15)
  int  *iptr2;      // Input: Second input pointer (Q15)
  int  *iptr3;      // Input: Third input pointer (Q15)
  int  *iptr4;      // Input: Fourth input pointer (Q15)
  int  trig_value;  // Input: Trigger point (Q15)
  int  prescalar;   // Parameter: Data log prescale
  int  skip_cntr;   // Variable:  Data log skip counter
  int  cntr;        // Variable:  Data log counter
  long write_ptr;   // Variable:  Graph address pointer
  int  size;        // Parameter: Maximum data buffer
  int  (*init)();   // Pointer to init function
  int  (*update)(); // Pointer to update function
} DLOG_4CH;

typedef DLOG_4CH *DLOG_4CH_handle;

void DLOG_4CH_init(void *);
void DLOG_4CH_update(void *);

#define DLOG_4CH_DEFAULTS { 0UL, \
                            NULL, \
                            NULL, \
                            NULL, \
                            NULL, \
                            0, \
                            1, \
                            0, \
                            0, \
                            0UL, \
                            0x400, \
                            (int (*)(int))DLOG_4CH_init, \
                            (int (*)(int))DLOG_4CH_update, \
}

#endif // DLOG4CH_H_
