var nodeunit = require('nodeunit');
var galois = require('../src/galois.js');

exports.bwah = function(test) {
  test.strictEqual(galois.bwah(), 'bwack');
  test.done();
};

exports.single_multiply = function(test) {
  test.strictEqual(typeof galois.single_multiply, 'function');

  test.throws(
    function() {
      galois.single_multiply('a', 7, 4);
    },
    TypeError, 'No strings');

  test.throws(
    function() {
      galois.single_multiply(null, 7, 4);
    },
    TypeError, 'No null');

  test.strictEqual(galois.single_multiply(3, 7, 4), 9);
  test.strictEqual(galois.single_multiply(1234567, 2345678, 32), 1404360778);

  test.done();
};
