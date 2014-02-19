node-galois
===========

[![Build Status](https://travis-ci.org/sbisbee/node-galois.png?branch=master)](https://travis-ci.org/sbisbee/node-galois)

This is a native Node.js module (C/C++) that wraps James S. Plank's Galois.c
code (http://web.eecs.utk.edu/~plank/plank/papers/CS-07-593/), making all of
the functionality available in Node.js. Please refer to that page for
documentation about the non-JS bits (function documentation, optimization of
single vs table calls, etc.).

This package also adds a little more protection when creating tables to prevent
segfaults. However, it's still possible to run into segfaults. For example,
calling `multtable_multiply(a, b, w)` before `create_mult_tables(w)` will be
allowed and cause a segfault.

Examples
--------

```javascript
var gf = require('galois');

var w = 8; //2^8 = GF256

//slower way
gf.single_multiply(2, 3, w); //6
gf.single_divide(6, 3, w); //2

//faster way - calc and store the table in RAM, so arithmetic is simple lookups
gf.create_mult_tables(w); 
gf.multtable_multiply(2, 3, w); //6
gf.multtable_divide(6, 3, w); //2
```

Install
-------

node-galois is available in NPM, so simply `npm install galois` to get it in
your application.

If you're looking to develop, `make build` will compile everything (does a
node-gyp rebuild) and `make check` will run the tests (this is was `npm test`
invokes).

License
-------

Due to the original Galois code being released under GPL v2, this module is
released under GPL v3.
