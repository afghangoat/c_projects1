#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
const double eps=1.0;
double tavolsag(int x1, int y1, int x2, int y2){
    double tav=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return tav;
}
/*Azért nem a sima abs függvényt kell használni, mert a sima abs függvény csak int tipusú változókra ad vissza helyes értéket, a double tipusú értékekre hibát ad ki. Az fabs függvényt kell használni ha lebeőpontos számok abszolút értéke kell*/
int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Az SDL nem indult el: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow("SDL peldaprogram", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (window == NULL) {
        SDL_Log("Az SDL ablak nem lett létrehozva: %s", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Az SDL renderer nem lett létrehozva: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);
    int piros_x=320, piros_y=240;
    int zoldp1x=240, zoldp1y=200;
    int zoldp2x=400, zoldp2y=280;
    int kekp1x=240, kekp1y=240;
    int kekp2x=400, kekp2y=240;


    for(int x=0;x<640;x++){
        for (int y = 0; y < 480; y++)
        {
            double piros_tavol=tavolsag(piros_x,piros_y,x,y);
            double zold_tavosszeg=tavolsag(zoldp1x,zoldp1y,x,y)+tavolsag(zoldp2x,zoldp2y,x,y);
            double kek_tavkulomb=fabs(tavolsag(kekp1x,kekp1y,x,y)-tavolsag(kekp2x,kekp2y,x,y));
            double feher_tav_pont=tavolsag(320,240,x,y);
            double feher_tav_egyenes=fabs(400-x);
            if(fabs(piros_tavol-200.0)<eps){
                pixelRGBA(renderer,x,y,255,0,0,255);
            } else if(fabs(zold_tavosszeg-250.0)<eps){
                pixelRGBA(renderer,x,y,0,255,0,255);
            } else if(fabs(kek_tavkulomb-100.0)<eps){
                pixelRGBA(renderer,x,y,0,0,255,255);
            } else if(fabs(feher_tav_egyenes-feher_tav_pont)<eps){
                pixelRGBA(renderer,x,y,255,255,255,255);
            }
        }
        
    }

    //Az alakzatok nevének kiírása
    stringRGBA(renderer, 10, 3, "A kapott alakzatok: Piros:Kör, Zöld:Ellipszis, Fehér:Parabola, Kék:Hiperbola", 255, 255, 255, 255);
 
    SDL_RenderPresent(renderer);
 
    //Addíg jelenik meg az ablak, amíg a felhasználó ki nem lép
    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
        /* SDL_RenderPresent(renderer); - MacOS Mojave esetén */
    }
 
    SDL_Quit();
 
    return 0;
}