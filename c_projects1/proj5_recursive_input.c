#include <stdio.h>
#include <stdlib.h>

//Rekurzív segédfüggvény
char* karakter_be(int i){
    
    char mostani=' ';
    int van_eof=scanf("%c",&mostani);
    
    //Ha enter jel jött akkor lehet tudni, hogy mennyi memóriára lesz szükség ezért le lehet foglalni.
    if (mostani == '\n'||van_eof==EOF) {
        
        char* karakterek = malloc( sizeof(char)*(i + 1));
        if (karakterek==NULL) { //Hibakezelés
            printf("A memória lefoglalása közbe hiba lépett fel!");
            return NULL;
        }
        
        karakterek[i] = '\0'; 
        return karakterek;
    }
    
    //Ha nem enter jel akkor rekurzívan meghívja a függvény magát eggyel nagyobb indexre, amíg az nem a végjel és nem kapja vissza a lefoglalt stringet.
    char* karakterek = karakter_be(i + 1);
    if (karakterek == NULL) return NULL;
    
    //A karakterek string feltöltése a végjeltől visszafele.
    karakterek[i] = mostani;
    return karakterek;
}

char* sort_beolvas(void){
    
    char* sor=karakter_be(0);
    
    return sor;
}

int main(){
    //A kód tesztelése
    char* sor1=sort_beolvas();
    if (sor1==NULL){
        printf("A sor beolvasása közbe hiba lépett fel!");
    } else {
        printf("%s",sor1);
    
        free(sor1); //A kapott pointer felszabadítása
    }
    

    return 0;
}