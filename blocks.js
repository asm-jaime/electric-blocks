'use strict'

const ffi = require('ffi');
const ref = require('ref');
const struct = require('ref-struct');

const clarke = struct({
  'As': 'float',
  'Bs': 'float',
  'Alpha': 'float',
  'Beta': 'float'
});
clarke.defineProperty('exec', ffi.Function('void', [ref.refType(clarke)]));

const clarkePtr = ref.refType(clarke);

const blocks = ffi.Library('./build/blocks.so', {
  'init_clarke': [ clarkePtr, [ ] ],
  'free_block': ['void', ['void *']]
})

const r_clarke = blocks.init_clarke().deref();

r_clarke.As = 100;
r_clarke.Bs = 100;
console.log(`Alpha: ${r_clarke.Alpha} Beta: ${r_clarke.Beta}`);

r_clarke.exec(r_clarke.ref());
console.log(`Alpha: ${r_clarke.Alpha} Beta: ${r_clarke.Beta}`);

blocks.free_block(r_clarke.ref());
