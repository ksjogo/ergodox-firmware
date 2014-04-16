/* ----------------------------------------------------------------------------
 * ergoDOX layout : COLEMAK-JG
 * 
 * Copyright (c) 2014 Johannes Goslar
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
    // LAYOUT L0: COLEMAK
    [0] = KB_MATRIX_LAYER(
        0,
        // left hand
        0,          _1,         _2,         _3,         _4,         _5,         0,
        0,          _Q,         _W,         _F,         _P,         _G,         0,
        0,          _A,         _R,         _S,         _T,         _D,
        _shiftL,    _Z,         _X,         _C,         _V,         _B,         0,
        _Z,         _Z,         _X,         _C,         _V,
    
                    _tab,       _esc,
        0,          0,          _ctrlL,
        2,          3,          _guiL,

        // right hand
        // 9 0 and 7 8 to get () on better fingers
        0,          _6,         _7,         _8,         _9,         _0,         _dash,
        _F3,        _J,         _L,         _U,         _Y,         _semicolon, _backslash,
                    _H,         _N,         _E,         _I,         _O,         _quote,
        _F4,        _K,         _M,         _comma,     _period,    _slash,     _shiftR,
                                _bs,        _bracketL,  _bracketR,  _equal,      _grave,

        _esc,       0,
        _ctrlR,     0,          0,
        _guiR,      3,          1 ),

    [1] = KB_MATRIX_LAYER(
        0,
        // left hand
        0,          _1,         _2,         _3,         _4,         _5,         0,
        0,          _Q,         _W,         _F,         _P,         _G,         0,
        0,          _A,         _R,         _S,         _T,         _D,
        _shiftL,    _Z,         _X,         _C,         _V,         _B,         0,
        0,          0,          0,          0,          0,
    
                    0,          0,
        0,          0,          2,
        0,          0,          1,

        // right hand
        0,          _6,         _7,         _8,         _9,         _0,         _dash,
        0,          _J,         _L,         _U,         _Y,         _semicolon, _backslash,
                    _H,         _N,         _E,         _I,         _O,         _quote,
        0,          _K,         _M,         _comma,     _period,    _slash,     _shiftR,
                                _del,        _bracketL,  _bracketR,  _equal,     _grave,

        0,          0,
        2,          0,          0,
        1,          0,          0 ),

    [2] = KB_MATRIX_LAYER(
        0,
        // left hand
        0,          _1,         _2,         _3,         _4,         _5,         0,
        0,          _Q,         _W,         _F,         _P,         _G,         0,
        0,          _A,         _R,         _S,         _T,         _D,
        _shiftL,    _Z,         _X,         _C,         _V,         _B,         0,
        0,          0,          0,          0,          0,
    
                    0,          0,
        0,          0,          2,
        0,          0,          1,

        // right hand
        0,          _6,         _7,         _8,         _9,         _0,         _dash,
        0,          _J,         _L,         _U,         _Y,         _semicolon, _backslash,
                    _H,         _N,         _E,         _I,         _O,         _quote,
        0,          _K,         _M,         _comma,     _period,    _slash,     _shiftR,
                                _del,        _bracketL,  _bracketR,  _equal,     _grave,

        0,          0,
        2,          0,          0,
        1,          0,          0 ),

    // LAYOUT L2: special more to come
    [3] = KB_MATRIX_LAYER(
        0,
        // left hand
        0,          _1,         _2,         _3,         _4,         _5,         0,
        0,          0,          0,          _F,         _P,          0,          0,
        _tab,       0,          0,          _bs,        _del,          0,
        _tab,       0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,

                    0,          0,
        0,          0,          2,
        0,          0,          0,
        // right hand
        0,          0,          0,          0,          0,          0,          0,
        0,          0,          _L,         _arrowU,    _Y,         0,          0,
                    _home,      _arrowL,    _arrowD,    _arrowR,    _end,       0,
        0,          0,          0,          0,          0,          0,          0,
                                0,          0,          0,          0,          0,

        0,          0,
        2,          0,          0,
        0,          0,          0 ),
    
    // LAYOUT L10: mod_or_tap
    [KB_LAYERS-1] = KB_MATRIX_LAYER(
        0,
        // left hand
        0,          0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,

                    0,          0,
        0,          0,          _F1,
        _space,     _enter,     _F18,
        // right hand
        0,          0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,          0,          0,
                    0,          0,          0,          0,          0,          0,
        0,          0,          0,          0,          0,          0,          0,
                                0,          0,          0,          0,          0,

        0,          0,
        _F2,        0,          0,
        _F18,       _enter,     _space ),
};

// basic
#define  kprrel  &kbfun_press_release
#define  ktoggl  &kbfun_toggle
#define  ktrans  &kbfun_transparent

// layer push/pop functions
#define  lpupot  &kbfun_layer_push_pop_read_or_tap

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  shift2  &kbfun_2_keys_capslock_press_release
#define  sprrel  &kbfun_shift_press_release
#define  modtap  &kbfun_mod_or_tap
#define  hypprl  &kbfun_rctrl_press_release
#define  ctlprl  &kbfun_lctrl_press_release
#define  cmdprl  &kbfun_lgui_press_release
#define  cmdspr  &kbfun_lgui_shift_press_release
#define  NULLLL  NULL

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

    // PRESS L0: COLEMAK
    [0] = KB_MATRIX_LAYER(
        NULL,
        // left hand
        kprrel,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     kprrel,
        kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,
        kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     
        shift2,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,
        cmdspr,     cmdprl,     cmdprl,     cmdprl,     cmdprl,
    
                    kprrel,     kprrel,
        NULLLL,     NULLLL,     modtap,
        lpupot,     lpupot,     modtap,
        // right hand
        kprrel,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     kprrel,
        kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,
                    kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,
        kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     shift2,
                                kprrel,     kprrel,     kprrel,     kprrel,     kprrel,

        kprrel,     dbtldr,
        modtap,     NULLLL,     NULLLL,
        modtap,     lpupot,     lpupot ),
  
    // PRESS L1: Shifted
    [1] = KB_MATRIX_LAYER(
        NULL,
        // left hand
        ktrans,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     ktrans,
        ktrans,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     ktrans,
        ktrans,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     
        ktrans,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     ktrans,
        ktrans,     ktrans,     ktrans,     ktrans,     ktrans,
    
                    ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        // right hand
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
                    NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
                                NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,

        ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans ),
    
    // PRESS L1: Shifted
    [2] = KB_MATRIX_LAYER(
        NULL,
        // left hand
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
        NULLLL,     NULLLL,     NULLLL,     NULLLL,     NULLLL,
    
                    ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        // right hand
        ktrans,     kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     sprrel,
        ktrans,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,
                    sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,
        ktrans,     sprrel,     sprrel,     sprrel,     sprrel,     sprrel,     ktrans,
                                kprrel,     sprrel,     sprrel,     sprrel,     sprrel,

        ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans ),
    
    [3] = KB_MATRIX_LAYER(
        NULL,
        // left hand
        ktrans,     hypprl,     hypprl,     hypprl,     hypprl,     hypprl,     ktrans,
        ktrans,     ktrans,     ktrans,     hypprl,     hypprl,     ktrans,     ktrans,
        cmdprl,     ktrans,     ktrans,     kprrel,     kprrel,     ktrans,     
        cmdspr,     ktrans,     ktrans,     ktrans,     ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,     ktrans,     ktrans,
    
                    ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        // right hand
        ktrans,     ktrans,     ktrans,     ktrans,     ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     hypprl,     kprrel,     hypprl,     ktrans,     ktrans,
                    kprrel,     kprrel,     kprrel,     kprrel,     kprrel,     ktrans,
        ktrans,     ktrans,     ktrans,     ktrans,     ktrans,     ktrans,     ktrans,
                                ktrans,     ktrans,     ktrans,     ktrans,     ktrans,

        ktrans,     ktrans,
        ktrans,     ktrans,     ktrans,
        ktrans,     ktrans,     ktrans ),

};
