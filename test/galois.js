var nodeunit = require('nodeunit');
var gf = require('../src/galois.js');

exports.single_multiply = function(test) {
  test.strictEqual(typeof gf.single_multiply, 'function');

  test.throws(
    function() {
      gf.single_multiply('a', 7, 4);
    },
    TypeError, 'No strings');

  test.throws(
    function() {
      gf.single_multiply(null, 7, 4);
    },
    TypeError, 'No null');

  test.strictEqual(gf.single_multiply(3, 7, 4), 9);
  test.strictEqual(gf.single_multiply(1234567, 2345678, 32), 1404360778);

  test.done();
};

exports.single_divide = function(test) {
  test.strictEqual(typeof gf.single_divide, 'function');
  test.strictEqual(gf.single_divide(9, 3, 4), 7);
  test.strictEqual(gf.single_divide(1404360778, 1234567, 32), 2345678);
  test.done();
};

exports.simple_logs = function(test) {
  // Prove that: a * b = ilog[ log[a] + log[b] ]
  var w = 3; //GF8
  var a = 4;
  var b = 5;

  var left;
  var right;

  left = gf.single_multiply(a, b, w);
  test.strictEqual(left, 2, 'Left');

  right = gf.ilog(gf.log(a, w) + gf.log(b, w), w);
  test.strictEqual(right, left, 'Proof');

  test.done();
};

exports.shift_multiply = function(test) {
  var w = 3; //GF8
  var a = 4;
  var b = 5;

  test.strictEqual(
    gf.shift_multiply(a, b, w),
    gf.single_multiply(a, b, w));

  test.done();
};

exports.shift_divide = function(test) {
  var w = 3;
  var a = 2;
  var b = 4;

  test.strictEqual(
    gf.shift_divide(a, b, w),
    gf.single_divide(a, b, w));

  test.done();
};

exports.inverses = function(test) {
  var w = 32;
  var x = 1404360778;
  var y = 106460795;

  test.strictEqual(gf.inverse(x, w), y);
  test.strictEqual(gf.shift_inverse(y, w), x);
  
  test.done();
};
