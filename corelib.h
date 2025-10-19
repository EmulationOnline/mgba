#pragma once

#include <stdint.h>
#include <stddef.h>

enum Keys {
    BTN_A = 0,
    BTN_B,
    BTN_Sel,
    BTN_Start,
    BTN_Up,
    BTN_Down,
    BTN_Left,
    BTN_Right,
    NUM_KEYS
};

#undef EMU_USES_CPP

#ifdef EMU_USES_CPP
#define UNMANGLE extern "C"
#else
#define UNMANGLE
#endif



UNMANGLE void set_key(size_t key, char val);
UNMANGLE void init(const uint8_t* data, size_t len);
UNMANGLE
UNMANGLE const uint8_t *framebuffer();
UNMANGLE
UNMANGLE void frame();
UNMANGLE void dump_state(const char* save_path);
UNMANGLE void load_state(const char* save_path);

// APU
const int SAMPLE_RATE = 44100;
const int SAMPLES_PER_FRAME = SAMPLE_RATE / 60;
UNMANGLE void apu_tick_60hz();
UNMANGLE void apu_sample_60hz(int16_t *output);
UNMANGLE long apu_sample_variable(int16_t *output, int32_t frames);
