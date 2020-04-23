#include <gb/gb.h>
#include <stdio.h>
#include "carinha.c"

void init();

void main() {
    //armazena o sprite atual: 0 ou 1
    UINT8 indexSprite = 0;
    //inicialização básica do GB
	init();

    //inicialização do sprite
    set_sprite_data(0,2,carinha);
    set_sprite_tile(0,indexSprite);
    move_sprite(0,88,78);
    SHOW_SPRITES;

	while(1) {
        //movimento do sprite
        switch (joypad()){
            case J_LEFT:
                scroll_sprite(0,-10,0);
                break;
            case J_RIGHT:
                scroll_sprite(0,10,0);
                break;
            case J_UP:
                scroll_sprite(0,0,-10);
                break;
            case J_DOWN:
                scroll_sprite(0,0,10);
                break;
            case J_A:
                //troca de sprite
                if (indexSprite==0) {
                    indexSprite=1;
                } else {
                    indexSprite=0;
                }

                set_sprite_tile(0,indexSprite);
                break;
        }
    delay(100);
    }
}

void init() {
	DISPLAY_ON;		    // Liga Display
	NR52_REG = 0x8F;	// Liga Som
	NR51_REG = 0x11;	// Ativa canal de audio
	NR50_REG = 0x77;	// Volume no maximo
}