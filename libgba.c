#include "corelib.h"
#include <stdint.h>

#ifndef __wasm32__
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <assert.h>
#endif


UNMANGLE
__attribute__((visibility("default")))
void set_key(size_t key, char val) {
}

UNMANGLE
__attribute__((visibility("default")))
const uint8_t *framebuffer() {
}

UNMANGLE
__attribute__((visibility("default")))
void frame() {
}


UNMANGLE
__attribute__((visibility("default")))
void init(const uint8_t* data, size_t len) {}

UNMANGLE 
__attribute__((visibility("default")))
void dump_state(const char* save_path) {}

UNMANGLE 
__attribute__((visibility("default")))
void load_state(const char* save_path) {}
