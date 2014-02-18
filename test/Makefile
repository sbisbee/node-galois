NODE_UNIT := ../node_modules/nodeunit/bin/nodeunit

all: check

check:
	for file in *.js; do $(NODE_UNIT) "$$file"; done

.PHONY: check
