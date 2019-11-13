#include "screen.h"

#include "system.h"
#include "keypad.h"



int main(void){
    uint8_t key;
    set_color(WHITE,BLACK);
    clear_screen();
    
    keypad_init();
    while(true){//cambiar condicion para que evalue si el juego ya termino
        
        key=keypad_getkey();
        moveplayer(key);
        draw();
        delay_ms(50);
        
    }
    
    return 0;
}
