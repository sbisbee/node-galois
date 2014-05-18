/*
 * node-galois
 * Copyright (C) 2014 Sam Bisbee
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

exports.create_mult_tables = function(test) {
  test.strictEqual(gf.create_mult_tables(3), true, 'Valid table');
  test.strictEqual(gf.create_mult_tables(3), true, 'Valid table, retry');

  test.throws(function() {
    gf.create_mult_tables(0);
  }, Error, 'Throw if w is too small');

  test.throws(function() {
    gf.create_mult_tables(14);
  }, Error, 'Throw if w is too large');

  test.done();
};

exports.multtable_math = function(test) {
  var w = 3;
  var a = 4;
  var b = 5;

  test.ok(gf.create_mult_tables(w), 'Got a table');

  test.strictEqual(
    gf.multtable_multiply(a, b, w),
    gf.single_multiply(a, b, w),
    'Multiply');

  test.strictEqual(
    gf.multtable_divide(a, b, w),
    gf.single_divide(a, b, w),
    'Divide');

  test.done();
};

exports.create_log_tables = function(test) {
  test.strictEqual(gf.create_log_tables(3), true, 'Valid table');
  test.strictEqual(gf.create_log_tables(3), true, 'Valid table, retry');

  test.throws(function() {
    gf.create_log_tables(0);
  }, Error, 'Throw if w is too small');

  test.throws(function() {
    gf.create_log_tables(31);
  }, Error, 'Throw if w is too large');

  test.done();
};

exports.logtable_math = function(test) {
  var w = 3;
  var a = 4;
  var b = 5;

  test.ok(gf.create_mult_tables(w), 'Got a table');

  test.strictEqual(
    gf.logtable_multiply(a, b, w),
    gf.single_multiply(a, b, w),
    'Multiply');

  test.strictEqual(
    gf.logtable_divide(a, b, w),
    gf.single_divide(a, b, w),
    'Divide');

  test.done();
};

exports.split_w8_tables = function(test) {
  var w = 32;
  var a = 45;
  var b = 46;

  test.ok(gf.create_split_w8_tables, 'Got a table');

  test.strictEqual(
    gf.split_w8_multiply(a, b),
    gf.single_multiply(a, b, w),
    'Multiply');

  test.done();
};

exports.add = function(test) {
  test.strictEqual(gf.add(0, 1, 1), 1);
  test.strictEqual(gf.add(1, 0, 1), 1);
  test.strictEqual(gf.add(1, 1, 1), 0);

  test.done();
};

exports.subtract = function(test) {
  test.strictEqual(gf.subtract(0, 1, 1), 1);
  test.strictEqual(gf.subtract(1, 0, 1), 1);
  test.strictEqual(gf.subtract(1, 1, 1), 0);

  test.done();
};

