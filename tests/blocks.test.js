'use strict';
const chai = require('chai');
const path = require('path');
const blocks = require('../blocks.js').blocks;
const logger = require('d3-vilog').logger;

describe('blocks', function() {
  it.skip('exec clarke', function() {
    const r_clarke = blocks.init_clarke().deref();
    console.log(r_clarke);
    r_clarke.As = 1;
    r_clarke.Bs = 1;
    r_clarke.exec(r_clarke.ref());
    chai.expect(r_clarke.Beta).to.be.within(1.7, 1.8);
    //console.log(`Alpha: ${r_clarke.Alpha} Beta: ${r_clarke.Beta}`);
    blocks.free_block(r_clarke.ref());
  });

  it.skip('exec rmp_cntl', function() {
    this.timeout(5000);

    function rc_data() {
      const gen_data = [];
      const r_rmp_cntl = blocks.init_rmp_cntl().deref();
      //r_rmp_cntl.RampDelayMax = 10;
      r_rmp_cntl.TargetValue = -0.001;

      for(let i = 0; i < 2000; ++i){
        r_rmp_cntl.exec(r_rmp_cntl.ref());
        gen_data.push([i, r_rmp_cntl.SetpointValue]);
      }
      blocks.free_block(r_rmp_cntl.ref());

      return [
        { data: gen_data, label: 'rmp_cntl generator' },
      ]
    }
    logger({ data: rc_data(), dest: __dirname, type: 'line' });
  });

  it('exec rampgen', function() {
    function rg_data() {
      const gen_data = [];
      const r_rampgen = blocks.init_rampgen().deref();
      r_rampgen.Freq = 0.5;
      r_rampgen.StepAngleMax = 0.01;

      for(let i = 0; i < 2000; ++i){
        r_rampgen.exec(r_rampgen.ref());
        gen_data.push([i, r_rampgen.Out]);
      }
      blocks.free_block(r_rampgen.ref());

      return [
        { data: gen_data, label: 'rampgen generator' },
      ]
    }
    logger({ data: rg_data(), dest: __dirname, type: 'line' });
  });
});
