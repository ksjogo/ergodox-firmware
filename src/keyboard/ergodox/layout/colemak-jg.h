/* ----------------------------------------------------------------------------
 * ergoDOX layout : COLEMAK-JG
 * 
 * Copyright (c) 2014 Johannes Goslar
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#ifndef KEYBOARD__ERGODOX__LAYOUT__COLEMAK_h
	#define KEYBOARD__ERGODOX__LAYOUT__COLEMAK_h

	#include "../controller.h"

	// --------------------------------------------------------------------

	#define kb_led_num_on()      _kb_led_1_on()
	#define kb_led_num_off()     _kb_led_1_off()
	#define kb_led_caps_on()     _kb_led_2_on()
	#define kb_led_caps_off()    _kb_led_2_off()
	#define kb_led_scroll_on()   _kb_led_3_on()
	#define kb_led_scroll_off()  _kb_led_3_off()

	// --------------------------------------------------------------------


    #include "./default--led-control.h"
	
    #define kb_layout_release_get(layer,row,column) \
      ( (void_funptr_t) \
        pgm_read_word(&( \
          _kb_layout_press[layer][row][column] )) )

    #include "./default--matrix-control.h"

#endif

