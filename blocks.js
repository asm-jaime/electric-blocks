'use strict'

const path = require('path');

const ffi = require('ffi');
const ref = require('ref');
const struct = require('ref-struct');

const clarke = struct({
  'As': 'float',
  'Bs': 'float',
  'Alpha': 'float',
  'Beta': 'float'
});
const clarkePtr = ref.refType(clarke);
clarke.defineProperty('exec', ffi.Function('void', [clarkePtr]));

module.exports.blocks = ffi.Library(path.join(__dirname, 'build/blocks.so'), {
  'init_clarke': [ clarkePtr, [ ] ],
  'free_block': ['void', ['void *']]
})
