#include "quantum.h"
#include "matrix.h"
#include "debounce.h"

#ifdef SPLIT_KEYBOARD
#    define PINNUM_ROW (MATRIX_ROWS / 2)
#    define ROWS_PER_HAND (MATRIX_ROWS / 2)
#else
#    define PINNUM_ROW (MATRIX_ROWS)
#    define ROWS_PER_HAND (MATRIX_ROWS)
#endif
#define PINNUM_COL (MATRIX_COLS / 2)

#define MATRIXSIZE_PER_HAND (ROWS_PER_HAND * sizeof(matrix_row_t))

static pin_t row_pins[PINNUM_ROW] = MATRIX_ROW_PINS;
static pin_t col_pins[PINNUM_COL] = MATRIX_COL_PINS;

static void set_pins_input(pin_t* pins, uint8_t n) {
    for (uint8_t i = 0; i < n; i++) {
        gpio_set_pin_input_high(pins[i]);
    }
}

static inline void set_pin_output(pin_t pin) {
    gpio_set_pin_output(pin);
    gpio_write_pin_low(pin);
}

static inline bool get_pin(pin_t pin) {
    return gpio_read_pin(pin);
}

void duplex_scan_raw_post_kb(matrix_row_t out_matrix[]) {}

static void duplex_scan_raw(matrix_row_t out_matrix[]) {
    for (uint8_t row = 0; row < PINNUM_ROW; row++) {
        set_pin_output(row_pins[row]);
        matrix_output_select_delay();
        for (uint8_t col = 0; col < PINNUM_COL; col++) {
            if (!get_pin(col_pins[col])) {
                out_matrix[row] |= 1 << col;
            }
        }
        gpio_set_pin_input_high(row_pins[row]);
        matrix_output_unselect_delay(row, false);
    }

    for (uint8_t col = 0; col < PINNUM_COL; col++) {
        set_pin_output(col_pins[col]);
        matrix_output_select_delay();
        matrix_row_t shifter = ((matrix_row_t)1) << (col + PINNUM_COL);
        for (uint8_t row = 0; row < PINNUM_ROW; row++) {
            if (!get_pin(row_pins[row])) {
                out_matrix[row] |= shifter;
            }
        }
        gpio_set_pin_input_high(col_pins[col]);
        matrix_output_unselect_delay(col, false);
    }

    duplex_scan_raw_post_kb(out_matrix);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool         changed          = false;
    matrix_row_t tmp[MATRIX_ROWS] = {0};

    duplex_scan_raw(tmp);
    for (uint8_t row = 0; row < PINNUM_ROW; row++) {
        if (tmp[row] != current_matrix[row]) {
            changed             = true;
            current_matrix[row] = tmp[row];
        }
    }
    return changed;
}

void matrix_init_custom(void) {
    set_pins_input(col_pins, PINNUM_COL);
    set_pins_input(row_pins, PINNUM_ROW);
}
