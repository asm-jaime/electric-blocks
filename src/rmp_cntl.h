#ifndef __RMP_CNTL_H__
#define __RMP_CNTL_H__


#include "iqmathlib.h"
#include "dmctype.h"

typedef struct rmpcntl {
         _iq    TargetValue;    // Input: Target input (pu)
         Uint32 RampDelayMax;   // Parameter: Max delay (Q0) independently with global Q
         _iq    RampLowLimit;   // Parameter: Minimum limit (pu)
         _iq    RampHighLimit;  // Parameter: Maximum limit (pu)
         Uint32 RampDelayCount; // Variable: Increm delay (Q0) independently with global Q
         _iq    SetpointValue;  // Output: Target output (pu)
         Uint32 EqualFlag;      // Output: Flag output (Q0) - independently with global Q
         void (*init)();        // Pointer to init function
         void (*exec)();        // Pointer to calculation function
        } rmpcntl;

#define rmpcntl_def { 0, \
                      40, \
                      _IQ(-1), \
                      _IQ(1), \
                      0, \
                      0, \
                      0, \
                     (void (*)(Uint32))Init, \
                     (void (*)(Uint32))Exec, \
}

void Init(rmpcntl *v);
void Exec(rmpcntl *v);

#endif // __RMP_CNTL_H__
