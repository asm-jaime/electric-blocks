// ========== Speed measurement computation based QEP encoder (rotor angle)

#ifndef __SPEED_MEAS_QEP_H__
#define __SPEED_MEAS_QEP_H__

#include "iqmathlib.h"
#include "dmctype.h"

typedef struct speed_meas_qep {
       _iq ElecTheta;       // Input: Electrical angle (pu)
       Uint32 DirectionQep; // Variable: Direction of rotation (Q0) - indep with global Q
       _iq OldElecTheta;    // History: Electrical angle at previous step (pu)
       _iq Speed;           // Output: Speed in per-unit  (pu)
       Uint32 BaseRpm;      // Parameter: Base speed in rpm (Q0) - indep with global Q
       _iq21 K1;            // Parameter: Const for diff (Q21) - indep with global Q
       _iq K2;              // Parameter: Constant for low-pass filter (pu)
       _iq K3;              // Parameter: Constant for low-pass filter (pu)
       int32 SpeedRpm;      // Output : Speed in rpm  (Q0) - independently with global Q
       void (*calc)();      // Pointer to the calulation function
       void (*init)();      // Pointer to init function
       void (*exec)();      // Pointer to calculation function
      } speed_meas_qep;     // Data type created

#define speed_meas_qep_def { 0, \
                             1, \
                             0, \
                             0, \
                             0, \
                             0, \
                             0, \
                             0, \
                             0, \
                            (void (*)(Uint32))Init, \
                            (void (*)(Uint32))Exec, \
}

void Init(speed_meas_qep *v);
void Exec(speed_meas_qep *v);

#endif // __SPEED_MEAS_QEP_H__
