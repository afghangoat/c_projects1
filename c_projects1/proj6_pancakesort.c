#include <stdio.h>
#include <stdlib.h>


//Kettősen láncolt listát használva egyszerűbb lesz a palacsintarendezés megvalósítása:
typedef struct Elem {
    int adat;
    int rendezett; //Ez indikálja, hogy jó helyen van-e az elem, ha rendezett akkor már nem kell fordítgatni és nem kell a maximum keresésnél figyelembe venni. Ha nem 0 akkor renezett és jó helyen van.
    struct Elem* kov;
    struct Elem* elozo;
} Elem;

//Kiírja a listát
void kiir_lista(Elem* lista){
    Elem* jelen=lista;
    while(jelen!=NULL){
        printf("%d ",jelen->adat);
        jelen=jelen->kov;
    }
    printf("\n---\n");
}

//Megkeresi a lista végét, ami nincs még renezve
Elem* keres_vege(Elem* lista) {
    Elem* vege = lista;
    while (vege->kov != NULL && vege->kov->rendezett == 0) {
        vege = vege->kov;
    }
    return vege;
}

//Megfordítja a láncolt lista elemeit ez elejétől egy elemig.
void megfordit_amig(Elem** lista, Elem *fej, Elem *meddig) {
    Elem *jelen = fej;
    Elem *t_elozo = NULL;
    Elem* t_kov = NULL;
    Elem* nem_rendezett_start=NULL;

    // Addíg végig kell menni a listán amíg el nem ér a függvény a meddig elemig, csak eddig kell megfordítani a listát.
    while (jelen != NULL && jelen != meddig) {
        t_kov = jelen->kov;
        jelen->kov = t_elozo;
        jelen->elozo = t_kov;
        t_elozo = jelen;
        jelen = t_kov;
    }
    
    // Ha meg lett találva az az elem ameddig meg kell fordítani a listát akkor az lesz az új feje (első eleme) a listának.
    if (jelen == meddig) {
        nem_rendezett_start=meddig->kov;
        meddig->kov = t_elozo;
        if (t_elozo) {
            t_elozo->elozo = meddig;
            
        }
        meddig->elozo = NULL;
    }

    // A lista előző feje lesz a megfordított szegmens vége, és a neki következő elem az annak a listarésznek az első eleme ami nem lett megfordítva.
    if (fej != meddig) {
        fej->kov = nem_rendezett_start;
        
    }
    if(t_kov){
        t_kov->elozo = fej;
    }

    *lista=meddig;
}

//Megkeresi a maximumot a nem rendezett elemrészből
Elem* max_keres(Elem* lista) {
    Elem* max_pointer = lista;
    int max_ertek = lista->adat;

    for (Elem* jelen = lista; jelen != NULL && jelen->rendezett == 0; jelen = jelen->kov) {
        if (jelen->adat > max_ertek) {
            max_ertek = jelen->adat;
            max_pointer = jelen;
        }
    }
    return max_pointer;
}

//Ez maga a rendezés, lépésenként 2 fordítést csinál.
void palacsinta_rendezes(Elem* lista) {
    Elem* lista_vege = keres_vege(lista);
    
    while (lista != lista_vege) {
       
        Elem* max_elem = max_keres(lista);
        if (max_elem != lista) {
            megfordit_amig(&lista,lista,max_elem);
            printf("Az maxtól megfordítva: ");
            kiir_lista(lista);
        }
        
        Elem* t_veg=keres_vege(lista);
        megfordit_amig(&lista,lista,t_veg);
        printf("Az egész megfordítva: ");
        kiir_lista(lista);
        
        lista_vege=max_elem;
        lista_vege->rendezett=1; //Indikálja a rendezés, hogy ezt az elemet már rendezte.
        lista_vege = lista_vege->elozo; //Azt az elemet már biztos nem kell sehova se fordítgatni, amit most befordított az algoritus alulra hiszen az alatt az elemek már rendezve vannak.
        
    }
}

Elem* lista_feltoltes(int* adatok, int n) {
    Elem* lista = malloc(sizeof(Elem));
    lista->elozo = NULL;
    Elem* mozgo = lista;

    for (int i = 0; i < n; i++) {
        mozgo->adat = adatok[i];
        mozgo->rendezett = 0;

        if (i < n - 1) {
            mozgo->kov = malloc(sizeof(Elem));
            mozgo->kov->elozo = mozgo;
            mozgo = mozgo->kov;
        } else {
            mozgo->kov = NULL;
        }
    }
    return lista;
}

//Ez a függvény felszabadítja a paraméterként kapott listát.
void felszabadit_lista(Elem* lista) {
    while (lista != NULL) {
        Elem* temp = lista;
        lista = lista->kov;
        free(temp);
    }
}

int main() {
    //Példák még adatokra.
    //int adatok[]={1,6,5,12,9,10,3,4,5,2};
    //int adatok[]={4,6,2,5,7,9,3,4,6,2};
    int adatok[] = {2, 1, 2, 4, 5, 7, 6, 9, 10, 2};
    int adatok_szama = 10;

    Elem* lista = lista_feltoltes(adatok, adatok_szama);

    printf("---\nA kezdő lista: ");
    kiir_lista(lista);

    palacsinta_rendezes(lista);

    felszabadit_lista(lista);
    return 0;
}