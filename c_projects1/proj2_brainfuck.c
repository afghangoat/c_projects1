#include <stdio.h>
#include <stdbool.h>
int main(){
    char szalag[32768]={0};
    int irofej_index=0;
    /*
    Más kódok, amikkel ki lett próbálva a program:
    ,+[-.,+]
    [ThisprogramprintsSierpinskitriangleon80-columndisplay.]>++++[<++++++++>-]>++++++++[>++++<-]>>++>>>+>>>+<<<<<<<<<<[-[->+<]>[-<+>>>.<<]>>>[[->++++++++[>++++<-]>.<<[->+<]+>[->++++++++++<<+>]>.[-]>]]+<<<[-[->+<]+>[-<+>>>-[->+<]++>[-<->]<<<]<<<<]++++++++++.+++.[-]<]+++++*****Made*By:*NYYRIKKI*2002*****
    ][
	//Goodbye world! kiírása:
	
    +++++++++[>++++++++>++++++++++++>+++++++++++>++++<<<<-]>-. //Feltölti 2. 3. 4. 5. cellát 47 108 63 24, és kiírja a G-t, ami a 47 asciiba
	>+++.. //108-hoz hozzáad 3-at és kiiírja 2-szer az o betűt
	>+. //4. cella tartalma 64 lesz, és kiírja a d-t
	--. //64-2=62, kiiírja a b
	<++++++++++. //kiírja az y-t
	>+++. //kiírja az e-t
	>----. //kiírja a szóközt.
	<<--. //w kiírása
	--------. //o kiírása
	+++. //r kiírása
	------. //l kiírása
	>-. //d kiírása
	>+. //Végül a ! kiírása
	
    */
    char programkod[]="+++++++++[>++++++++>++++++++++++>+++++++++++>++++<<<<-]>-.>+++..>+.--.<++++++++++.>+++.>----.<<--.--------.+++.------.>-.>+."; //Goodbye world! kiírása
    int parancs_index=0;
    while(programkod[parancs_index]!='\0'){
        if(irofej_index<0||irofej_index >= 32768){
            printf("Hiba! Az írófej kiment a szalagról.");
            return 0;
        }
        char temp_char=' ';
        switch(programkod[parancs_index]){
            case '>':
                irofej_index+=1;
                break;
            case '<':
                irofej_index-=1;
                break;
            case '+':
                szalag[irofej_index]+=1;
                break;
            case '-':
                szalag[irofej_index]-=1;
                break; 
            case '.':
                printf("%c",(char)szalag[irofej_index]);
                break;
            case ',':
                if(scanf("%c",&temp_char)==EOF){
                    szalag[irofej_index]=-1;
                } else {
                    szalag[irofej_index]=(int)temp_char;
                }
                break;
            case '[':
                if (szalag[irofej_index] == 0) {
                    int zarojelek = 1;
                    while (zarojelek > 0) {
                        parancs_index += 1;
                        if(parancs_index>32768){
                            printf("\nHiba! Nem jól formált ciklus!");
                            return 1;
                        }
                        if (programkod[parancs_index] == '[')
                            zarojelek++;
                        else if (programkod[parancs_index] == ']')
                            zarojelek--;
                    }
                }
                break;
            case ']':
                if (szalag[irofej_index] != 0) {
                    int zarojelek = 1;
                    while (zarojelek > 0) {
                        parancs_index--;
                        if(parancs_index<0){
                            printf("\nHiba! Nem jól formált ciklus!");
                            return 1;
                        }
                        if (programkod[parancs_index] == ']') zarojelek++;
                        else if (programkod[parancs_index] == '[') zarojelek--;
                    }
                }
                break;
            default:
                
                break;
        }
        parancs_index++;
    }
    return 0;
}
