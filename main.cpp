/*
  _nome: Hello World! Mario!
  _programado em allegro C++.
  _compilado no Dev_C++.
  _altor: Saulo Daniel Ferreira Pontes.
  _data: Natal/RN_12/11/2009.
 //ja que nao sei java fiz em c++
*/

#include <allegro.h>
#include <alpng.h>
#include <alfont.h>
#include <stdio.h>


void init();
void deinit();
 
volatile int contador = 0;
volatile int cmore = 0;
volatile int cci = 0;
volatile int cmoeda = 0;

void vIncrementa()
{
 contador++;
}END_OF_FUNCTION( vIncrementa );
 LOCK_FUNCTION( vIncrementa );
 LOCK_VARIABLE( vIncrementa ); 

void mIncrementa()
{
 cmore++;
}END_OF_FUNCTION( vIncrementa );
 LOCK_FUNCTION( vIncrementa );
 LOCK_VARIABLE( vIncrementa );
 
void cIncrementa()
{
 cci++;
}END_OF_FUNCTION( vIncrementa );
 LOCK_FUNCTION( vIncrementa );
 LOCK_VARIABLE( vIncrementa );
 
void cmoIncrementa()
{
 cmoeda++;
}END_OF_FUNCTION( vIncrementa );
 LOCK_FUNCTION( vIncrementa );
 LOCK_VARIABLE( vIncrementa );  
 
 
int main() {
    init();
    int novo=1;
 do{
    int vidas=5,moedas=0,pontuacao=0;
    int x=286,y=214;
    int l=0;
    int aa=280,bb=400,cc=494,ii;
    int cvt=1;
    int movimento=0,andar=0;
    int ry=70,ryc=100,rr=0;
    int more=0;
    int pu=0,pl=0;
    
    //--------------------------------------------------------------------------

    //----------imagens---------------------------------------
    BITMAP *Buffer = create_bitmap(640, 480 ); // Buffer //
    BITMAP *fundo = load_bitmap("arquivos//fundo.bmp", NULL);
    //plataformas------------
    BITMAP *pl1 = load_bitmap("arquivos//pl1.bmp", NULL);
    BITMAP *pl2 = load_bitmap("arquivos//pl2.bmp", NULL);
    //canos------------------
    BITMAP *cano = load_bitmap("arquivos//cano.bmp", NULL);
    BITMAP *cano1 = load_bitmap("arquivos//cano1.bmp", NULL);
    //bara de stats----------
    BITMAP *status = load_bitmap("arquivos//status.bmp", NULL);
    //game over--------------
    BITMAP *gameover = load_png("arquivos//gameover.png", NULL);
    //bloco nao quebavel-----
    BITMAP *bloco = load_bitmap("arquivos//br.bmp", NULL);
    //bloco quebravel--------
    BITMAP *bloco1 = load_bitmap("arquivos//br1.bmp", NULL);
    //bloco de interogacao---
    BITMAP *i1 = load_bitmap("arquivos//i1.bmp", NULL);
    BITMAP *i2 = load_bitmap("arquivos//i2.bmp", NULL);
    BITMAP *i3 = load_bitmap("arquivos//i3.bmp", NULL);
    BITMAP *i4 = load_bitmap("arquivos//i4.bmp", NULL);
    //cogumelo da vida-------
    BITMAP *cv = load_bitmap("arquivos//cv.bmp", NULL);
    //moeda------------------
    BITMAP *m1 = load_bitmap("arquivos//m1.bmp", NULL);
    BITMAP *m2 = load_bitmap("arquivos//m2.bmp", NULL);
    BITMAP *m3 = load_bitmap("arquivos//m3.bmp", NULL);
    BITMAP *m4 = load_bitmap("arquivos//m4.bmp", NULL);
    //inimigo bala-----------
    BITMAP *canhao = load_bitmap("arquivos//canhao.bmp", NULL);
    BITMAP *bala = load_bitmap("arquivos//bala.bmp", NULL);
    //inimigo rocha----------
    BITMAP *r1 = load_bitmap("arquivos//r1.bmp", NULL);
    BITMAP *r2 = load_bitmap("arquivos//r2.bmp", NULL);
    BITMAP *r3 = load_bitmap("arquivos//r3.bmp", NULL);
    BITMAP *r4 = load_bitmap("arquivos//r4.bmp", NULL);
    BITMAP *r5 = load_bitmap("arquivos//r5.bmp", NULL);
    BITMAP *r6 = load_bitmap("arquivos//r6.bmp", NULL);
    BITMAP *r7 = load_bitmap("arquivos//r7.bmp", NULL);
    //inimigo ef-------------
    BITMAP *ef1 = load_bitmap("arquivos//ef1.bmp", NULL);
    BITMAP *ef2 = load_bitmap("arquivos//ef2.bmp", NULL);
    
    
    
    //--mario-------------------------------
     BITMAP *moreu = load_bitmap("arquivos//moreu.bmp", NULL);//mario moreu
     BITMAP *bmd = load_bitmap("arquivos//bmd.bmp", NULL);//mario abaixado para a direita
     BITMAP *mpd = load_bitmap("arquivos//mpd.bmp", NULL);//mario parado para a direita
     BITMAP *md1 = load_bitmap("arquivos//md1.bmp", NULL);//mario andando para a direita 1
     BITMAP *md2 = load_bitmap("arquivos//md2.bmp", NULL);//mario andando para a direita 2
     BITMAP *mupd = load_bitmap("arquivos//mupd.bmp", NULL);//mario pulando para a direita
    
     
    //BITMAP *png = load_png("img.png", NULL);
    //clear(bmp); //apaga a imagem da memoria
    //draw_trans_sprite(Buffer, png, 0, 0); 
    //--------------------------------------------------------

    //--------fontes------------------------------------------
    ALFONT_FONT *a = alfont_load_font("arquivos//a.ttf");
    alfont_set_font_size(a, 20);
    ALFONT_FONT *A = alfont_load_font("arquivos//a.ttf");
    alfont_set_font_size(A, 60);
    //--------------------------------------------------------

    //---musicas----------------------------------------------
    MIDI *musica;//Carega a música inicio.mid e começa a tocá-la (com loop de repetição)
    musica = load_midi("arquivos//mario.mid");
    play_midi( musica, true );
    set_volume( 100, 100 );
    //--------------------------------------------------------
    
    //--------------------------------------------------------------------------
 
    while(!key[KEY_ESC]) /* Enquanto tecla diferente de ESC */
     {//========================================================================
     if(!key[KEY_ESC])
      clear_to_color(Buffer, makecol(30,30,100));//cor do fundo da tela// 
      set_alpha_blender(); 
      
      more=0;//sinalisa quando mario more
      novo=0;//finalisa o jogo sem iniciar um novo
      
      //----- relogio ----------------------------------------------------------
       time_t tempo;
       struct tm *tm;
       tempo = time(NULL);
       tm = localtime( &tempo);
       alfont_textprintf_aa_ex(Buffer, a, 10, 300, 0x00FF00, -1, "\n %d:%d:%d", tm->tm_hour, tm->tm_min, tm->tm_sec); 
       //-----------------------------------------------------------------------  
       //install_int_ex( cIncrementa, SECS_TO_TIMER( 5 ) );// ativando temporisador
       // Mostrando o valor da variável global que está sendo incrementada //
       //textprintf_ex( Buffer, font, 10, 40, makecol(0, 0, 0), -1, "%d ",  contador);
       /*SECS_TO_TIMER você passa quantos segundos você quer entre cada tick (chamada da função).
         MSEC_TO_TIMER você passa quantos milisegundos você quer entre cada tick (chamada da função).
         BPS_TO_TIMER você passa quantos ticks você quer por segundo.
         BPM_TO_TIMER você passa quantos ticks você quer por minuto.*/

       //---------delimitacao de tela-------- 
       if(x<=0)                           //---
          x=5;                               //
       if(x>=615)                            //
          x=610;                             //
       if(y<=0)                              //
          y=5;                            //---
       //------------------------------------
       
        
        //gravidade--------------------------
        y=y+2;//gravidade afetando mario <<--------------------
        //-----------------------------------

        //===cenario============================================================
        draw_sprite(Buffer, fundo, 0, 0);                                  //---
        draw_sprite(Buffer, status, 0, 2);                                    //
        draw_sprite(Buffer, pl2, 0, 180);                                     //
        draw_sprite(Buffer, pl1, -40, 320);                                   //
        draw_sprite(Buffer, pl1, 0, 380);                                     //
        draw_sprite(Buffer, pl1, 500, 400);                                   //
                                                                              //
        //---------------calculos de colisao-----------------                 //
          if((x>=0 && x<=390) && y>=348)//pl1-1--------------                 //
             y=348;                                                           //
          if(y>=360 && x<=400)                                                //
            x=400;//-----------------------------------------                 //
                                                                              //
          if(x>=0 && x<=230 && y>=148 && y<=150)//pl1-2------                 //
             y=148;//----------------------------------------                 //
                                                                              //
          if(x>=0 && x<=350 && y>=288 && y<=290)//pl1-3------                 //
             y=288;//----------------------------------------                 //
                                                                              //
          if((x>=490 && x<=900) && y>=368)//pl1-4------------                 //
             y=368;                                                           //
          if(y>=370 && x>=474)                                                //
            x=474;//-----------------------------------------              //---
        //======================================================================
        
        
        //--status-----------------------------------------------------------------
        alfont_textprintf_aa_ex(Buffer, a, 30, 0, 0xFFFFFF, -1, "%d",vidas);
        alfont_textprintf_aa_ex(Buffer, a, 80, 0, 0xFFFFFF, -1, "%d",moedas);
        alfont_textprintf_aa_ex(Buffer, a, 520, 0, 0xFFFFFF, -1, "p: %d",pontuacao);
        alfont_textprintf_aa_ex(Buffer, a, 260, 10, 0xFFFFFF, -1, "Hello World!");
        alfont_textprintf_aa_ex(Buffer, a, 300, 30, 0xFFFFFF, -1, "Mario!");
        
        if(vidas<=100) 
           if(moedas==100)//se moedas igual a 100 + 1 vida
              {vidas++;
               moedas=0;
              }  
                  
        if(y>480 )//mario more e volta aposicao inicial quando cai no buraco
           {      
            vidas--; 
            x=286;
            y=214;
            movimento=0;
           }
        //-------------------------------------------------------------------------
     
        //cogumelo da vida  esposto------------------------
        if(cvt==1)
          {
           draw_sprite(Buffer, cv, 512, 244);
           if(y>=224 && x>=500 && x<=528 && y<=244){
           vidas++;
           cvt=0;}
          } 
        //-------------------------------------------------
      
      
      
        //=========inimigos=========================================
        //----canhao e bala-------------------------------------
         draw_sprite(Buffer, bala, 110, 153);

         draw_sprite(Buffer, canhao, 140, 149);
         
        //------------------------------------------------------
       
        //--rocha zangada---------------------------------------
        if(y>=ry && x>=480 && x<=530)                           //---
          {install_int_ex( vIncrementa, MSEC_TO_TIMER( 60 ) );     //
           if(contador==0)                                         //
              draw_sprite(Buffer, r1, 496, ry);                    //
           if(contador==1)                                         //
              draw_sprite(Buffer, r2, 496, ry);                    //
           if(contador==2)                                         //
              draw_sprite(Buffer, r3, 496, ry);                    //
           if(contador==3)                                         //
              draw_sprite(Buffer, r4, 496, ry);                    //
           if(ry<210)                                              //
             if(contador>4)                                        //
               {ry=ry+12;                                          //
                ryc=ryc+12;                                        //
                draw_sprite(Buffer, r5, 496, ry);                  //
               }                                                   //
             if(ry>=208 && ry<209)                                 //
                 draw_sprite(Buffer, r6, 495, ry);                 //
             else                                                  //
              if(ry>=210)                                          //
                 draw_sprite(Buffer, r7, 495, 217);                //
            }                                                      //
           else{                                                   //
                draw_sprite(Buffer, r1, 496, ry);                  //
                if(ry>70){                                         //
                    ry--;                                          //
                    ryc--;}                                        //
                if(contador>0)                                     //
                    contador=0;                                    //
               }                                                   //
           rr=ry-18;                                               //                                                     //
           if(x>=480 && x<=530 && y>rr && y<=ryc)                  //
             {                                                     //
              more=1;                                              //
              movimento=0;                                         //
             }                                                     //
           else                                                    //
              more=0;                                           //---
        //------------------------------------------------------
       
       //--ef 1-------------------------------------------------
       draw_sprite(Buffer, ef1, 160, 290); 
       //-------------------------------------------------------
       
       //--ef 2-------------------------------------------------
       draw_sprite(Buffer, ef1, 80, 350); 
       //-------------------------------------------------------
       //==========================================================
       
       
       //======blocos=============================================
        //--------blocos-quebraves--------
         draw_sprite(Buffer, bloco, 26, 100);
         draw_sprite(Buffer, bloco, 68, 100);
         
        //-----blocos-de-interogacao------                           //---
          install_int_ex( cIncrementa, MSEC_TO_TIMER( 140 ) );          //
          if(cci==0)                                                    //
             draw_sprite(Buffer, i1, 600, 330);                         //
          else                                                          //
          if(cci==1)                                                    //
             draw_sprite(Buffer, i2, 600, 330);                         //
          else                                                          //
          if(cci==2)                                                    //
             draw_sprite(Buffer, i3, 600, 330);                         //
          else                                                          //
          if(cci>=3){                                                   //
             draw_sprite(Buffer, i4, 600, 330);                         //
             cci=0;}                                                 //---
          //calculo de colizao-------------------------------------
          if((x>=580 && x<=604) && y>=298 && y<=332)//bloco 1 ------- //---
             y=298;                                                      //
          if(y>=300 && x>=576 && x<=606 && y<=336)                       //
             x=576;                                                      //
          if(y>=300 && x>=580 && x<=610 && y<=336)                       //
             x=610;                                                      //   
          if((x>=580 && x<=604) && y>=305 && y<=346)                     //
             y=346; //----------------------------------------------- //--- 
          //-------------------------------------------------------
          
          if((x>=580 && x<=602) && y>=305 && y<=346)//moedas do bloco  //---
              {                                                           //
               install_int_ex( cmoIncrementa, MSEC_TO_TIMER( 100 ));      //
                if(cmoeda==0)                                             //
                   draw_sprite(Buffer, m1, 600, 310);                     //
                else                                                      //
                if(cmoeda==1)                                             //
                   draw_sprite(Buffer, m2, 600, 310);                     //
                else                                                      //
                if(cmoeda==2)                                             //
                   draw_sprite(Buffer, m3, 600, 310);                     //
                else                                                      //
                if(cmoeda>=3){                                            //
                   draw_sprite(Buffer, m4, 600, 310);                     //
                   cmoeda=0;                                              //
                   moedas++;}                                             //
               }//---------------------------------------------------- //---        
         
        //-----blocos-nao-quebraveis------
        draw_sprite(Buffer, bloco1, 494, 68);//base da pedra-- //---
        ii=0;                                                     //
        do{                                                       //
           cc=cc+16;                                              //
           draw_sprite(Buffer, bloco1, cc, 68);                   //
           ii++;                                                  //
          }while(ii<=5);                                          //
          cc=494;//------------------------------------------- //---
  
        draw_sprite(Buffer, bloco1, aa, 200);//---1--- //---
        ii=0;                                             //
        do{                                               //
           aa=aa+16;                                      //
           draw_sprite(Buffer, bloco1, aa, 200);          //
           ii++;                                          //
          }while(ii<=5);                                  //
          aa=280;//----------------------------------- //---
        
        draw_sprite(Buffer, bloco1, bb, 260);//---2---- //---   
        ii=0;                                              //
        do{                                                //
           bb=bb+16;                                       //
           draw_sprite(Buffer, bloco1, bb, 260);           //
           ii++;                                           //
          }while(ii<=7);                                   //
          bb=400;//------------------------------------ //---
          //--calculos de colisao--
          if((x>=262 && x<=382) && y>=167 && y<=169)//plataforma 1----- //---
             y=167;                                                        //
          if(y>=169 && x>=256 && x<=300 && y<=204)                         //
            x=256;                                                         //
          if(y>=169 && x>=290 && x<=390 && y<=204)                         //
            x=390;                                                         //
          if((x>=262 && x<=382) && y>=185 && y<=216)                       //
             y=216;//-------------------------------------------------- //---  

          if((x>=380 && x<=540) && y>=228 && y<=235)//plataforma 2----- //---
             y=228;                                                        //
          if(y>=240 && x>=376 && x<=480 && y<=260)                         //
            x=376;                                                         //
          if(y>=240 && x>=460 && x<=540 && y<=260)                         //
            x=540;                                                         //
          if((x>=380 && x<=536) && y>=245 && y<=276)                       //
             y=276;//-------------------------------------------------- //---
 
          if((x>=474 && x<=600) && y>=35 && y<=48)//plataforma 3----- //---
             y=35;                                                       //
          if(y>=48 && x>=470 && x<=520 && y<=78)                         //
             x=470;                                                      //
          if(y>=48 && x>=500 && x<=603 && y<=72)                         //
             x=603;                                                      //
          if((x>=474 && x<=600) && y>=45 && y<=84)                       //
             y=84;//------------------------------------------------- //---   
        //=========================================================
       
        if(key[KEY_Q])//vidas test
            vidas=-1;//se vidas==-1 game over
        //test-das-posicao-x-y-de-mario-    
        alfont_textprintf_aa_ex(Buffer, a, 4, 460, 0x000000, -1, "x: %d  y: %d,  ry: %d ryc: %d, more: %d, cci: %d",x,y,ry,ryc,more,cci);    
        //test do contador da rocha
        textprintf_ex( Buffer, font, 10, 450, makecol(0, 0, 0), -1, "r_anim: %d ",  contador);
      
       //========= mario == controles ==========================================
       if(more==1)                                                 //---
              {install_int_ex( mIncrementa, MSEC_TO_TIMER( 30 ) );    //
               do{                                                    //
                  draw_sprite(Buffer, moreu,x,y);                     // 
                 }while(cmore<10);                                    //
                   vidas--;                                           //
                   x=286;                                             //
                   y=214;                                             //
                   cmore=0;                                        //--- 
               }else
         if(y<450)//mario a cima do buraco
           {//controle---------------------
            if(key[KEY_X])//plulo para cima               //---
              {if(movimento==0){                             //  
                  draw_sprite(Buffer, mupd,x,y);             //
                  y=y-10;                                    //
                  x=x+6;}                                    //
               else                                          //
                  if(movimento==1){                          //   
                  draw_sprite_h_flip(Buffer, mupd,x,y);      //
                  y=y-10;                                    //
                  x=x-6;}                                 //---
              }else   
            if(key[KEY_LEFT])//esqueda                        //---
              {                                                  //
               movimento=1;                                      //
               if(andar==0)                                      //
                 {                                               //
                  draw_sprite_h_flip( Buffer, md1, x, y );       //
                  andar++;                                       //
                 }                                               //
               else                                              //
                  if(andar==1)                                   //
                    {                                            //
                     draw_sprite_h_flip( Buffer, md2, x, y );    //
                     andar--;                                    //
                    }                                            //
               x=x-3;//imagem esqueda                         //---
               }else    
            if(key[KEY_RIGHT])//direita            //---...falta pulo para frente
              {                                       //    
               movimento=0;                           //
               if(andar==0)                           //
                 {                                    //
                  draw_sprite(Buffer, md1,x,y);       //
                  andar++;                            //
                 }                                    //
               else                                   //
                  if(andar==1)                        //
                    {                                 //
                     draw_sprite(Buffer, md2,x,y);    //
                     andar--;                         //
                    }                                 //
               x=x+3;//imagem direita              //---
               }else 
            if(key[KEY_Z])//pulo para frente               //---
              {if(movimento==0)                               //
                  draw_sprite(Buffer, mupd,x,y);              //
                else                                          //
                if(movimento==1)                              //
                  draw_sprite_h_flip( Buffer, mupd, x, y );   //           
               y=y-10;//imagem pulando                     //---  
              }else                
            if(key[KEY_DOWN])                              //---
              {if(movimento==0)                               //
                  draw_sprite(Buffer, bmd,x,y);               //
               else                                           //
                 if(movimento==1)                             //
                   draw_sprite_h_flip(Buffer, bmd,x,y);    //---
              }else
              if(movimento==0)                             //---
                 draw_sprite( Buffer, mpd, x, y );            //
              else                                            //
                if(movimento==1)                              //
                   draw_sprite_h_flip(Buffer, mpd,x,y);   //----  
            }
         else
            if(y>450)                                               //---
               draw_sprite(Buffer, moreu,x,y);//mario caiu no buraco   //   
                                                                    //---
        //======================================================================
       
        
     
         //-canos--------------------------------------------------
        draw_sprite(Buffer, cano, 540, 367);                     //---
        if((x>=522 && x<=562) && y>=333)//colisao com o cano----    //
             y=333;                                                 //
          if(y>=335 && x>=515 && x<=520)                            //
            x=515;                                                  //
          if(y>=335 && x>=564 && x<=569)                            // 
            x=569;//--------------------------------------------    //
                                                                    //
        draw_sprite(Buffer, cano1, 282, 216);//cano de saida---     //
          if(y>=200 && x>=258 && x<=264 && y<=240)                  //
            x=258;                                                  //
          if(y>=200 && x>=262 && x<=284 && y<=240)                  //
            x=284;                                                  //
          if(y>=200 && x>=304 && x<=311 && y<=240)                  //
            x=311;                                                  //
          if(y>=200 && x>=286 && x<=310 && y<=240)                  //
            x=286;//-------------------------------------------- //---
        //---------------------------------------------------------
        
 
        
         
         //-game-over---------------------------------------------------------------------
         if(vidas<0)                                                                    //---
         {draw_sprite(Buffer, gameover, 0, 0);                                             //
          stop_midi();                                                                     //
          alfont_textprintf_aa_ex(Buffer, A, 150, 30, 0xFFFFFF, -1, "pontuacao:");         //
          alfont_textprintf_aa_ex(Buffer, A, 120, 80, 0xFFFFFF, -1, "- %d -",pontuacao);   //
          novo=0;                                                                          //
          alfont_textprintf_aa_ex(Buffer, A, 10, 400, 0xFFFFFF, -1, "novo jogo (s/n):");   //
          if(key[ KEY_S ])                                                                 //
            {novo=1;                                                                       //
             break;}                                                                       //
          else                                                                             //
             if(key[ KEY_N ])                                                              //
             {break;                                                                       //
              }                                                                            //
          contador=0;//contador e zerado                                                //---
         }//------------------------------------------------------------------------------
      
      //show_mouse(Buffer);
      //textprintf_ex( Buffer, font, 10, 30, makecol(200, 200, 20), -1, "X= %d , Y= %d ",mouse_x, mouse_y );
     
      blit( Buffer, screen, 0, 0, 0, 0, 640, 480 ); //Copiando o Buffer para a screen //    
      clear( Buffer ); // Limpando o Buffer //
     }//========================================================================
   
	 //---------destruindo-a-musica---------------
      destroy_midi( musica ); //descarrega da memória 
     //---------destruindo-as-imagens-------------
     destroy_bitmap( Buffer );  // Destruindo o Buffer //
     destroy_bitmap( fundo );
     destroy_bitmap( pl1 );
     destroy_bitmap( pl2 );
     destroy_bitmap( status );
     //---------destruindo-as-fonts---------------
     alfont_destroy_font(a);
     //-------------------------------------------
 }while(novo == 1);
    
    readkey();
    deinit();
    return 0;
}
END_OF_MAIN()
 
void init() {
    int depth, res;
    allegro_init();
    alfont_init();
    depth = desktop_color_depth();
    if (depth == 0) depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    if (res != 0) {
        allegro_message(allegro_error);
        exit(-1);
    }
 
    /* set the window title */
    set_window_title("Hello World! Mario!   -- SAULO DANIEL F. PONTES --");
 
    install_timer();
    install_keyboard();
    install_mouse();
    if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL)){
		allegro_message(allegro_error);
		exit(-1);
	}
    /* add other initializations here */
}
 
void deinit() {
    clear_keybuf();
    alfont_exit(); 
    /* add other deinitializations here */
}
