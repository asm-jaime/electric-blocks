'use strict';

const path = require('path');

const ffi = require('ffi');
const ref = require('ref');
const struct = require('ref-struct');

// ========== blocks

const clarke = struct({
  'As': 'float',
  'Bs': 'float',
  'Alpha': 'float',
  'Beta': 'float'
});
const clarkePtr = ref.refType(clarke);
clarke.defineProperty('exec', ffi.Function('void', [clarkePtr]));

const park = struct({
  'Alpha': 'float',
  'Beta': 'float',
  'Angle': 'float',
  'Ds': 'float',
  'Qs': 'float'
});
const parkPtr = ref.refType(park);
park.defineProperty('exec', ffi.Function('void', [parkPtr]));

const ipark = struct({
  'Alpha': 'float',
  'Beta': 'float',
  'Angle': 'float',
  'Ds': 'float',
  'Qs': 'float'
});
const iparkPtr = ref.refType(ipark);
ipark.defineProperty('exec', ffi.Function('void', [iparkPtr]));

const pid_reg3 = struct({
  'Ref': 'float',
  'Fdb': 'float',
  'Err': 'float',
  'Kp': 'float',
  'Up': 'float',
  'Ui': 'float',
  'Ud': 'float',
  'OutPreSat': 'float',
  'OutMax': 'float',
  'OutMin': 'float',
  'SatErr': 'float',
  'Ki': 'float',
  'Kc': 'float',
  'Kd': 'float',
  'Up1': 'float',
  'Out': 'float',
});
const pid_reg3Ptr = ref.refType(pid_reg3);
pid_reg3.defineProperty('exec', ffi.Function('void', [pid_reg3Ptr]));

const rmp_cntl = struct({
  'TargetValue': 'float',
  'RampDelayMax': 'ulong',
  'RampLowLimit': 'float',
  'RampHighLimit': 'float',
  'RampDelayCount': 'ulong',
  'SetpointValue': 'float',
  'EqualFlag': 'ulong'
});
const rmp_cntlPtr = ref.refType(rmp_cntl);
rmp_cntl.defineProperty('exec', ffi.Function('void', [rmp_cntlPtr]));

const rampgen = struct({
  'Freq': 'float',
  'StepAngleMax': 'float',
  'Angle': 'float',
  'Gain': 'float',
  'Out': 'float',
  'Offset': 'float'
});
const rampgenPtr = ref.refType(rampgen);
rampgen.defineProperty('exec', ffi.Function('void', [rampgenPtr]));

const speed_meas_qep = struct({
  'ElecTheta': 'float',
  'DirectionQep': 'ulong',
  'OldElecTheta': 'float',
  'Speed': 'float',
  'BaseRpm': 'ulong',
  'K1': 'float',
  'K2': 'float',
  'K3': 'float',
  'SpeedRpm': 'long',
});
const speed_meas_qepPtr = ref.refType(speed_meas_qep);
speed_meas_qep.defineProperty('exec', ffi.Function('void', [speed_meas_qepPtr]));

const svgen_dq = struct({
  'Ualpha': 'float',
  'Ubeta': 'float',
  'Ta': 'float',
  'Tb': 'float',
  'Tc': 'float'
});
const svgen_dqPtr = ref.refType(svgen_dq);
svgen_dq.defineProperty('exec', ffi.Function('void', [svgen_dqPtr]));

// ========== libs

module.exports.blocks = ffi.Library(path.join(__dirname, 'build/blocks.so'), {
  'init_clarke': [ clarkePtr, [ ] ],
  'init_rampgen': [ rampgenPtr, [ ] ],
  'init_rmp_cntl': [ rmp_cntlPtr, [ ] ],
  'free_block': ['void', ['void *']]
});
