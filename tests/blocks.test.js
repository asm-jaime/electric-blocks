'use strict';
const chai = require('chai');
const blocks = require('../blocks.js').blocks;


describe('blocks', function() {
  it('exec clarke', function() {
    const r_clarke = blocks.init_clarke().deref();
    r_clarke.As = 1;
    r_clarke.Bs = 1;
    r_clarke.exec(r_clarke.ref());
    chai.expect(r_clarke.Beta).to.be.within(1.7, 1.8);
    //console.log(`Alpha: ${r_clarke.Alpha} Beta: ${r_clarke.Beta}`);

    blocks.free_block(r_clarke.ref());
  });
});
