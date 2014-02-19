node-galois
===========

This Node.js module wraps James S. Plank's Galois.c code
(http://web.eecs.utk.edu/~plank/plank/papers/CS-07-593/), making all of the
functionality available in Node.js. Please refer to that page for documentation
about the functions and non-JS bits.

This package also adds a little more protection when creating tables to prevent
segfaults.

Examples
--------

```javascript
var gf = require('galois');

var w = 8; //2^8 = GF256

gf.single_multiply(2, 3, w); //6
gf.single_divide(6, 3, w); //2
```

License
-------

Due to the original Galois code being released under GPL v2, this module is
released under GPL v3.
