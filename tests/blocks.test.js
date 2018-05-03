'use strict';
const chai = require('chai');
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

  it.skip('exec ipark', function() {
    this.timeout(5000);

    function ipark_data() {
      const alpha = [];
      const beta = [];

      const r_rampgen = blocks.init_rampgen().deref();
      r_rampgen.Freq = 0.5;
      r_rampgen.StepAngleMax = 0.01;

      const r_ipark = blocks.init_ipark().deref();
      r_ipark.Qs = 0.18;
      r_ipark.Ds = 0;

      for(let i = 0; i < 500; ++i){
        r_rampgen.exec(r_rampgen.ref());

        r_ipark.Angle = r_rampgen.Out;
        r_ipark.exec(r_ipark.ref());

        alpha.push([i, r_ipark.Alpha]);
        beta.push([i, r_ipark.Beta]);
      }
      blocks.free_block(r_ipark.ref());
      blocks.free_block(r_rampgen.ref());

      return [
        { data: alpha, label: 'ipark.Alpha' },
        { data: beta, label: 'ipark.Beta' },
      ];
    }
    logger({ data: ipark_data(), dest: __dirname, type: 'line' });
  });

  it.skip('exec rmp_cntl', function() {
    this.timeout(5000);

    function rc_data() {
      const gen_data = [];
      const r_rmp_cntl = blocks.init_rmp_cntl().deref();
      r_rmp_cntl.RampDelayMax = 40;
      r_rmp_cntl.SetpointValue = 0.45;
      r_rmp_cntl.TargetValue = 0.5;

      for(let i = 0; i < 2000; ++i){
        r_rmp_cntl.exec(r_rmp_cntl.ref());
        gen_data.push([i, r_rmp_cntl.SetpointValue]);
      }
      blocks.free_block(r_rmp_cntl.ref());

      return [
        { data: gen_data, label: 'rmp_cntl generator' },
      ];
    }
    logger({ data: rc_data(), dest: __dirname, type: 'line' });
  });

  it.skip('exec rampgen', function() {
    function rg_data() {
      const gen_data = [];
      const r_rampgen = blocks.init_rampgen().deref();
      r_rampgen.Freq = 0.5;
      r_rampgen.StepAngleMax = 0.01;
      console.log(r_rampgen);

      for(let i = 0; i < 2000; ++i){
        r_rampgen.exec(r_rampgen.ref());
        gen_data.push([i, r_rampgen.Out]);
      }
      blocks.free_block(r_rampgen.ref());

      return [
        { data: gen_data, label: 'rampgen generator' },
      ];
    }
    logger({ data: rg_data(), dest: __dirname, type: 'line' });
  });

  it.skip('exec gen_sin', function() {
    function sin_data() {
      const sin1_data = [];
      const sin2_data = [];

      const r_gen_sin1 = blocks.init_gen_sin().deref();
      r_gen_sin1.Freq = 0.5;
      r_gen_sin1.Angle = 0;
      r_gen_sin1.Ampl = 1;
      r_gen_sin1.StepAngleMax = 0.01;

      const r_gen_sin2 = blocks.init_gen_sin().deref();
      r_gen_sin2.Freq = 0.5;
      r_gen_sin2.Angle = 0.25;
      r_gen_sin2.Ampl = 1;
      r_gen_sin2.StepAngleMax = 0.01;

      //console.log(r_gen_sin1, r_gen_sin2);

      for(let i = 0; i < 500; ++i){
        r_gen_sin1.exec(r_gen_sin1.ref());
        sin1_data.push([i, r_gen_sin1.Out]);

        r_gen_sin2.exec(r_gen_sin2.ref());
        sin2_data.push([i, r_gen_sin2.Out]);
      }
      blocks.free_block(r_gen_sin1.ref());
      blocks.free_block(r_gen_sin2.ref());

      return [
        { data: sin1_data, label: 'sin1' },
        { data: sin2_data, label: 'sin2' },
      ];
    }
    logger({ data: sin_data(), dest: __dirname, type: 'line' });
  });

  it.skip('exec gen_sin+svgen_dq', function() {
    function svgen_data() {
      const Ta = [];
      const Tb = [];
      const Tc = [];

      const r_gen_sin1 = blocks.init_gen_sin().deref();
      r_gen_sin1.Freq = 0.5;
      r_gen_sin1.Angle = 0;
      r_gen_sin1.Ampl = 1;
      r_gen_sin1.StepAngleMax = 0.01;

      const r_gen_sin2 = blocks.init_gen_sin().deref();
      r_gen_sin2.Freq = 0.5;
      r_gen_sin2.Angle = 0.25;
      r_gen_sin2.Ampl = 1;
      r_gen_sin2.StepAngleMax = 0.01;

      const r_svgen_dq = blocks.init_svgen_dq().deref();

      console.log(r_svgen_dq);

      for(let i = 0; i < 500; ++i){
        r_gen_sin1.exec(r_gen_sin1.ref());
        r_gen_sin2.exec(r_gen_sin2.ref());

        r_svgen_dq.Ualpha = r_gen_sin1.Out;
        r_svgen_dq.Ubeta = r_gen_sin2.Out;
        r_svgen_dq.exec(r_svgen_dq.ref());

        Ta.push([i, r_svgen_dq.Ta]);
        Tb.push([i, r_svgen_dq.Tb]);
        Tc.push([i, r_svgen_dq.Tc]);
      }

      blocks.free_block(r_gen_sin1.ref());
      blocks.free_block(r_gen_sin2.ref());
      blocks.free_block(r_svgen_dq.ref());

      return [
        { data: Ta, label: 'Ta' },
        { data: Tb, label: 'Tb' },
        { data: Tc, label: 'Tc' },
      ];
    }
    logger({ data: svgen_data(), dest: __dirname, type: 'line' });
  });

  it('exec ipark+svgen_dq', function() {
    function svgen_data() {
      const Ta = [];
      const Tb = [];
      const Tc = [];

      const r_rmp_cntl = blocks.init_rmp_cntl().deref();
      r_rmp_cntl.RampDelayMax = 10;
      r_rmp_cntl.SetpointValue = 0.45;
      r_rmp_cntl.TargetValue = 0.5;

      const r_rampgen = blocks.init_rampgen().deref();
      r_rampgen.Freq = r_rmp_cntl.SetpointValue;
      r_rampgen.StepAngleMax = 0.01;

      const r_ipark = blocks.init_ipark().deref();
      r_ipark.Qs = 0.18;
      r_ipark.Ds = 0;

      const r_svgen_dq = blocks.init_svgen_dq().deref();
      //console.log(r_svgen_dq);

      for(let i = 0; i < 500; ++i){
        r_rmp_cntl.exec(r_rmp_cntl.ref());

        r_rampgen.Freq = r_rmp_cntl.SetpointValue;
        r_rampgen.exec(r_rampgen.ref());

        r_ipark.Angle = r_rampgen.Out;
        r_ipark.exec(r_ipark.ref());

        r_svgen_dq.Ualpha = r_ipark.Alpha;
        r_svgen_dq.Ubeta = r_ipark.Beta;
        r_svgen_dq.exec(r_svgen_dq.ref());

        Ta.push([i, r_svgen_dq.Ta]);
        Tb.push([i, r_svgen_dq.Tb]);
        Tc.push([i, r_svgen_dq.Tc]);
      }

      blocks.free_block(r_rmp_cntl.ref());
      blocks.free_block(r_rampgen.ref());
      blocks.free_block(r_ipark.ref());
      blocks.free_block(r_svgen_dq.ref());

      return [
        { data: Ta, label: 'Ta' },
        { data: Tb, label: 'Tb' },
        { data: Tc, label: 'Tc' },
      ];
    }
    logger({ data: svgen_data(), dest: __dirname, type: 'line' });
  });
});
