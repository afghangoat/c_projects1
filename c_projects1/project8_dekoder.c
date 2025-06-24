#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
       0
      / \
     0.   0-
bal(.) jobb(-)
*/
typedef struct Elem{
    char token;
    char betu;
    struct Elem* jobb;
    struct Elem* bal;
} Elem;

char* keres_morse(Elem* jelen, char betu, char* kod, int depth) {
    if (jelen == NULL) {
        return NULL; // Nem találtuk meg a betűt.
    }

    if (jelen->betu == betu) {
        kod[depth] = '\0'; // A kód vége
        return strdup(kod);
    }

    //.
    kod[depth] = '.';
    char* bal_kod = keres_morse(jelen->bal, betu, kod, depth + 1);
    if (bal_kod != NULL) {
        return bal_kod;
    }

    //-
    kod[depth] = '-';
    char* jobb_kod = keres_morse(jelen->jobb, betu, kod, depth + 1);
    if (jobb_kod != NULL) {
        return jobb_kod;
    }

    return NULL; //A betű nem lett megtalálva.
}

char* morse_kod(Elem* fa, char betu) {
    char* kod=(char*)malloc(100 * sizeof(char));
    return keres_morse(fa, betu, kod, 0);
}

void beszur_fa(Elem* fej,char betu,const char* kod){
    int len=strlen(kod);
    Elem* jelen=fej;
    for(int i=0;i<len;i++){
        if(kod[i]=='-'){
            if(jelen->jobb==NULL){
                Elem* uj=(Elem*)malloc(sizeof(Elem));
                uj->token='-';
                uj->betu=' ';
                uj->jobb=NULL;
                uj->bal=NULL;
                jelen->jobb=uj;
            }
            jelen=jelen->jobb;
        } else {
            if(jelen->bal==NULL){
                Elem* uj=(Elem*)malloc(sizeof(Elem));
                uj->token='.';
                uj->betu=' ';
                uj->jobb=NULL;
                uj->bal=NULL;
                jelen->bal=uj;
            }
            jelen=jelen->bal;
        }
    }
    jelen->betu=betu;
}
Elem* morse_fa(char betuk[],const char* morse[]){
    Elem* fa=(Elem*)malloc(sizeof(Elem));
    fa->token='0';
    fa->betu=' '; //A bináris fa feje
    fa->jobb=NULL;
    fa->bal=NULL;
    int betuk_szama=strlen(betuk);
    //A fa feltöltése
    for(int i=0;i<betuk_szama;i++){
        beszur_fa(fa,betuk[i],morse[i]);
    }
    
    return fa;
}
void print_elem(FILE* f,Elem* el,int tabulacio){
    if(el==NULL){
        return;
    }
    char* tab_string=(char*) malloc(sizeof(char)*(tabulacio+1));
    for(int i=0;i<tabulacio;i++){
        tab_string[i]='\t';
    }
    tab_string[tabulacio]='\0';
    
    int van_jobb=0;
    int van_bal=0;
    if(el->jobb!=NULL){
        van_jobb=1;
    }
    if(el->bal!=NULL){
        van_bal=1;
    }
    if(van_bal==1){
        fprintf(f,"%sif (de[%d]=='.')\n",tab_string,(tabulacio-1));
        print_elem(f,el->bal,tabulacio+1);
        if(van_jobb==1){
            fprintf(f,"%selse if (de[%d]=='-')\n",tab_string,(tabulacio-1));
            print_elem(f,el->jobb,tabulacio+1);
        }
    } else if(van_jobb==1){
        //if -
        fprintf(f,"%sif (de[%d]=='-')\n",tab_string,(tabulacio-1));
        print_elem(f,el->jobb,tabulacio+1);
    }
    if(van_jobb==1||van_bal==1){
        fprintf(f,"%selse\n",tab_string);
    }
    if(el->betu==' '){ //Érvénytelen
        fprintf(f,"%s\tprintf(\"érvénytelen\");\n",tab_string);
    } else {
        fprintf(f,"%s\tprintf(\"%c\");\n",tab_string,el->betu);
    }
   
    /*
    if (de[1]=='-')
            printf("M");
        else if (de[1]=='.')
            printf("N");
        else
            printf("T");
    */
}

//
void csinal_dekoder_file(Elem* fa,char* mit_kell_dekod){
    FILE* f = fopen("morzedekoder.c","w");
    
    fprintf(f,"#include <stdio.h>\n");
    fprintf(f,"void dekod(char *de) {\n");
    print_elem(f,fa,1);
    fprintf(f,"}\n");
    fprintf(f,"//A Main függvény, amiben meg lesz hívva a dekod függvény:\n");
    fprintf(f,"int main(){\n");
    //A függvény, ami megkeresi a betű kódját a fába
    int szo_hossz=strlen(mit_kell_dekod);
    for(int i=0;i<szo_hossz;i++){
        char* temp_betu_kod=morse_kod(fa,mit_kell_dekod[i]);
        fprintf(f,"\tdekod(\"%s\");\n",temp_betu_kod);
    }
    fprintf(f,"\treturn 0;\n");
    fprintf(f,"}\n");
    fclose(f);
}
int main() {
    char betuk[] = "abcdefghijklmnopqrstuvwxyz";
    
    const char* morse[] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",  "...",  "-", "..-",  "...-", ".--",  "-..-", "-.--", "--.."};
    Elem* fa=morse_fa(betuk,morse);
    csinal_dekoder_file(fa,"alma");

    return 0;
}