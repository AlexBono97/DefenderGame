#include "defender.h"


bool islive(int n){
    if (n==1)
        return true;
    else
        return false;
}

void enemy1(){

    set_color(RED, BLACK);
    
    while(loopenemigo1<5){
        if(islive(enemigo1[loopenemigo1])){
            set_cursor(enemigo1_posv[loopenemigo1],enemigo1_posh[loopenemigo1]);
            putchar('\x3');
            
            if(isalien1disparo==0){
                isalien1disparo=1;
                disparoenemigo1_posh = enemigo1_posh[loopenemigo1];
                disparoenemigo1_posv = enemigo1_posv[loopenemigo1];
            }
            //moviendose en un patron determinado
            //primero a la izquierda
            
            
            if(enemigo1_posh[loopenemigo1]-1<0){
                enemigo1_posh[loopenemigo1]=79;
            }else{
                enemigo1_posh[loopenemigo1]=enemigo1_posh[loopenemigo1]-1;
            }
            //luego hacia abajo
            if(enemigo1_posv[loopenemigo1]+1>30-1){
                enemigo1_posv[loopenemigo1]=2;
            }else{
                enemigo1_posv[loopenemigo1]=enemigo1_posv[loopenemigo1]+1;
            }  
        }
        else{
            enemigo1_posv[loopenemigo1]=0;
            enemigo1_posh[loopenemigo1]=79; 
        }
        loopenemigo1+=1;
    }
    loopenemigo1=0;
    

}

void enemy2(){
    set_color(CYAN,BLACK);

    
    if(islive(enemigo2[loopenemigo2]) && loopenemigo2<5){
            set_cursor(enemy2_posv[loopenemigo2],enemy2_posh[loopenemigo2]);
            puts("\x4");
            
            if(isalien2disparo==0){
                isalien2disparo=1;
                disparoenemigo2_posh=enemy2_posh[loopenemigo2];
                disparoenemigo2_posv=enemy2_posv[loopenemigo2];
            }
        //se mueve en un patron de zig zag
        //primero hacia arriba y luego a la izquierda
        //arriba
            if(sub==0){
                enemy2_posv[loopenemigo2]=enemy2_posv[loopenemigo2]+1;
                if(enemy2_posv[loopenemigo2]>=29){
                    sub=1;
                }
            }
            else if(sub==1){
                enemy2_posv[loopenemigo2]=enemy2_posv[loopenemigo2]-1;
                if(enemy2_posv[loopenemigo2]-1<2){
                    sub=0;
                }
            }

        //izquierda
        if(enemy2_posh[loopenemigo2]-1<0){
            enemy2_posh[loopenemigo2]=79;
        }else{
            enemy2_posh[loopenemigo2]=enemy2_posh[loopenemigo2]-1;
        }
        
    }else{
        loopenemigo2+=1;
    }
 
}


//mueve al jugador segun el input
void moveplayer(uint8_t key){
    switch(key){
        
        case 0:
                break;
        //izquierda
        case 1:
                if(player_posh-1<0){
                    return;
                }else{
                    player_posh=player_posh-1;
                }
                break;
        //derecha
        case 2:
                if(player_posh+1>79){
                    return;
                }else{
                    player_posh=player_posh+1;
                }
                break;
        //abajo
        case 3:
                if(player_posv+1>29){
                    return;
                }else{
                    player_posv=player_posv+1;
                }
                break;
        //arriba
        case 4:
                if(player_posv-1<2){
                    return;if(isdisparo==1){
                    return;
                }
                else{
                    disparo_posh=player_posh;
                    disparo_posv=player_posv;
                }
                }else{
                    player_posv=player_posv-1;
                }
                break;
        //Q --> dispara
        case 5:
                if(isdisparo==0){
                    isdisparo=1;
                    disparo_posv=player_posv;
                    disparo_posh=player_posh;
                }
                
                //implementar disparo
                break;
        //Espacio --> reset
        case 8:
                resetgame();
                break;
        default:
                return;

    }
    
}
//mueve disparos del jugador
void playershoot(){
   
    if(disparo_posh+1>79){
        disparo_posh=0;
        isdisparo=0;
    }else{
        disparo_posh=disparo_posh+1;
    }
 
}
//colision disparos jugador contra aliens
void colision(){
    int c=0;
    while(c<5){
        if((disparo_posh==enemigo1_posh[c]-1 && disparo_posv==enemigo1_posv[c]) || (disparo_posh==enemigo1_posh[c] && disparo_posv==enemigo1_posv[c])){
            
            enemigo1[c]=0;
            enemigo1_posh[c]=0;
            enemigo1_posv[c]=0;
            isdisparo=0;
            win=win+1; 
            break;           
        }
        else if((disparo_posh==enemy2_posh[c]-1 && disparo_posv==enemy2_posv[c]) || (disparo_posh==enemy2_posh[c] && disparo_posv==enemy2_posv[c])){
            enemigo2[c]=0;
            enemy2_posh[c]=0;
            enemy2_posv[c]=0;
            isdisparo=0;
            win=win+1; 
            break;
        }
        c+=1;
    }
    
}

//test
void * myitoa(uint32_t n){
    char texto[20];
    uint32_t len=0;
    uint32_t temp=0;
    uint32_t coc=0;
    uint32_t rest=0;

    do{
        temp=n;
        divide(n,10,&coc,&rest);
        n=coc;
        texto[len]="0123456789abcdefghijklmnopqrstuvwxyz"[temp-(n*10)];
        len+=1;
    }while(n!=0);
    //haciendo un reverso a los datos

    while(len>0){
        putchar(texto[len-1]);
        len-=1;
    }

}
//colision de las naves
void colisionnaves(){
    int c=0;
    while(c<5){
        if((player_posh==enemigo1_posh[c]-1 && player_posv==enemigo1_posv[c])
        || (player_posh==enemigo1_posh[c] && player_posv==enemigo1_posv[c])){
            
            enemigo1[c]=0;
            enemigo1_posh[c]=0;
            enemigo1_posv[c]=0;
            win=win+1; 
            vidas=vidas-1;
            player_posv=2;
            player_posh=0;
            break;           
        }
        else if((player_posh==enemy2_posh[c]-1 && player_posv==enemy2_posv[c])
             || (player_posh==enemy2_posh[c] && player_posv==enemy2_posv[c])){
            enemigo2[c]=0;
            enemy2_posh[c]=0;
            enemy2_posv[c]=0;
            win=win+1; 
            vidas=vidas-1;
            player_posv=2;
            player_posh=0;
            break;
        }
        c+=1;
    }
}
//mueve disparos de los aliens
void alienshoot(){
    if(disparoenemigo1_posh-1<0){
        disparoenemigo1_posh=0;
        isalien1disparo=0;
    }else{
        disparoenemigo1_posh=disparoenemigo1_posh-1;
    }
    
    if(disparoenemigo2_posh-1<0){
        disparoenemigo2_posh=0;
        isalien2disparo=0;
    }else{
        disparoenemigo2_posh=disparoenemigo2_posh-1;
    }
}

void colisionDisparoAlien(){
    if((disparoenemigo1_posh==player_posh-1 && disparoenemigo1_posv==player_posv)
    || (disparoenemigo1_posh==player_posh && disparoenemigo1_posv==player_posv)){
        vidas=vidas-1;
        player_posv=2;
        player_posh=0;
        isalien1disparo=0;
    }

    if((disparoenemigo2_posh==player_posh-1 && disparoenemigo2_posv==player_posv)
    || (disparoenemigo2_posh==player_posh && disparoenemigo2_posv==player_posv)){
        vidas=vidas-1;
        player_posv=2;
        player_posh=0;
        isalien2disparo=0;
    }
}

void resetgame(){
    win=0;
    vidas=3;
    player_posv=15;
    player_posh=15;
    disparo_posh=0;
    disparo_posv=0;
    isdisparo=0;
    //enemigo2
    int temp=0;
    while(temp<5){
        enemigo2[temp]=1;
        enemy2_posv[temp]=25;
        enemy2_posh[temp]=79;
        enemigo1[temp]=1;
        enemigo1_posh[temp]=78;
        enemigo1_posv[temp]=temp+2;
        temp++;
    }
    sub=0;
    loopenemigo2=0;
    loopenemigo1=0;
    disparoenemigo1_posh=0;
    disparoenemigo1_posv=0;
    disparoenemigo2_posh=0;
    disparoenemigo2_posv=0;
    isalien1disparo=0;
    isalien2disparo=0;
    
}

void draw(){
    set_color(WHITE,BLACK);
    clear_screen();
    set_color(WHITE,BLACK);
    set_cursor(1,2);
    puts("Vidas: ");
    set_color(RED,BLACK);
    putchar('\x5');
    set_color(WHITE,BLACK);
    myitoa(vidas);
    set_cursor(1,55);
    set_color(GREEN,BLACK);
    puts("   Aliens restantes ");
    set_color(WHITE,BLACK);
    putchar('x');
    myitoa(10-win);
    set_cursor(0,30);
    set_color(LIGHT_CYAN,BLACK);
    puts("D E F E N D E R");
    //evalua estado del juego
    if(vidas==0){
        set_cursor(15,17);
        puts("HAS PERDIDO!!! EL JUEGO SE REINICIARA EN BREVE");
        delay_ms(5000);
        resetgame();
    }else if(win==10){
        set_cursor(15,17);
        puts("HAS GANADO!!! EL JUEGO SE REINICIARA EN BREVE");
       delay_ms(5000);
        resetgame();
    }

    
    //inicializa al jugador y los enemigos
    set_color(WHITE,BLACK);
    set_cursor(player_posv,player_posh);
    putchar('\x6');
    //renderiza los disparos del jugador
    //inicializa los enemigos
    enemy1();
    enemy2();    
    
      //evalua colisiones entre jugador y aliens
    colisionnaves();
    if(isdisparo==1){
        set_cursor(disparo_posv,disparo_posh);
        putchar('\x8');
        playershoot();
        colision();
    }

    if(isalien1disparo==1){
        set_cursor(disparoenemigo1_posv,disparoenemigo1_posh);
        putchar('\x9');
        alienshoot();
        colisionDisparoAlien();
    }

    if(isalien2disparo==1){
        set_cursor(disparoenemigo2_posv,disparoenemigo2_posh);
        putchar('\x9');
        alienshoot();
        colisionDisparoAlien();
    }
    
  
   
    
  
}



