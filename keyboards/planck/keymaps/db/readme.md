# callum’s planck layout

This is a layout for the grid planck, built with a few ideals in mind:

- Consistent and minimal response times should be maintained. Keys that react differently depending on whether they are tapped or held, keys that react differently if they are double tapped, etc. should be avoided – they inevitably send their keycode later than a normal key – interrupting the immediate feedback from the screen. Therefore we restrict ourselves to chording as our only means of getting more than one symbol out of a single physical key.
- The hands should never need to leave the home position. The usual culprit for this is the arrow cluster, so the arrow cluster should be as close to home as possible.
- There should be two of every modifier (one on each side), otherwise certain long key combinations become hard to make.

We have five layers.
A `BASE` layer, in dvorak;
a `MOVE` layer, with an arrow cluster, other movement keys, and hotkeys;
a `SYMB` layer, with numbers and symbols;
a `FUNC` layer, with a numpad;
a `MOUSE` layer, with mouse emulation. The `MOUSE` layer is activated by holding the Move and Symb keys simultaniously.

```
/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Ä  |   Ö  |   .  |   ,  |   Y  |   F  |   G  |   C  |   R  |   L  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Å  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Cmd  |  Alt |  Ctrl| Bksp | Move | Symb | Space|  Cmd |  Alt | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  | Pg Up| Home |  Up  | End  | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 | Pg Dn| Left | Down | Right| Vol- | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F11 |  F12 |  F13 | F14  |  F15 |      | THome| BEnd | Del  |      | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   €  |   ?  |   ´  |   `  |   <  |   >  |   {  |   }  |   %  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   £  |   !  |   "  |   '  |   @  |   &  |   (  |   )  |   =  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   ~  |   /  |   \  |   #  |   |  |   [  |   ]  |   $  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |   7  |   8  |   9  |   -  |   €  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   (  |   )  |      |   =  |   4  |   5  |   6  |   +  |   $  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   /  |   £  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      | A+S  | ACC-2| ACC-1| ACC-0|      |      | SW-L |  M-U | SW-R | SW-U |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LALt | C+A  | MB-3 | MB-2 | MB-1 |      |      |  M-L |  M-D |  M-R | SW-D |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| C+S  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
```
