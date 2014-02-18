NODE_GYP := node-gyp

TEST_DIR := ./test

all: build

build:
	${NODE_GYP} rebuild

check: build
	make -C ${TEST_DIR} check

clean:
	${NODE_GYP} clean

.PHONY: build check clean
