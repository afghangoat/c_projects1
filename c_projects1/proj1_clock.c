#include <stdio.h>
#include <string.h>
#include <math.h>

double PI=3.1415926536;

int main(){
    FILE *fptr;
    fptr = fopen("ora.svg", "w");
    char svg_content[]="<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"><circle cx=\"100\" cy=\"100\" r=\"100\" stroke=\"black\" fill=\"#cccccc\"/><circle cx=\"100\" cy=\"100\" r=\"70\" stroke=\"black\" fill=\"#eeeeee\"/><circle cx=\"100\" cy=\"100\" r=\"40\" stroke=\"black\" fill=\"#dddddd\"/>";
    fprintf(fptr, "%s", svg_content);
     for (int i = 0; i < 12; i++) {
        double p1x = 100.0 + cos(PI / 6 * i) * 50;
        double p1y = 100.0 + sin(PI / 6 * i) * 50;
        double p2x = 100.0 + cos(PI / 6 * i) * 100;
        double p2y = 100.0 + sin(PI / 6 * i) * 100;
        fprintf(fptr, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"2\" stroke-linecap=\"round\" stroke=\"blue\"/>", p1x, p1y, p2x, p2y);

        for (int j = 1; j < 5; j++) {
            double p1xp = 100.0 + cos(PI / 6 * i + PI / 30 * j) * 70;
            double p1yp = 100.0 + sin(PI / 6 * i + PI / 30 * j) * 70;
            double p2xp = 100.0 + cos(PI / 6 * i + PI / 30 * j) * 90;
            double p2yp = 100.0 + sin(PI / 6 * i + PI / 30 * j) * 90;
            fprintf(fptr, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\"/>", p1xp, p1yp, p2xp, p2yp);
        }
    }
    double ora=0;
    double perc=0;
    double masodperc=0;
    printf("Kérem adja meg azokat az adatokat, amiből elkészül az óra kép:\nÓra: ");
    scanf("%lf",&ora);
    printf("\nPerc: ");
    scanf("%lf",&perc);
    printf("\nMásodperc: ");
    scanf("%lf",&masodperc);
	// Óramutató (Piros)
    double ora_rx=100.0+cos((PI/6)*(ora-3)+PI/360*perc+PI/21600*(masodperc))*100;
    double ora_ry=100.0+sin((PI/6)*(ora-3)+PI/360*perc+PI/21600*(masodperc))*100;
	fprintf(fptr, "<line x1=\"100\" y1=\"100\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"6\" stroke-linecap=\"round\" stroke=\"red\"/>", ora_rx, ora_ry);
    // Percmutató (Zöld)
    double perc_rx = 100.0 + cos(PI / 30 * (perc - 15) + PI / 1800 * masodperc) * 70;
    double perc_ry = 100.0 + sin(PI / 30 * (perc - 15) + PI / 1800 * masodperc) * 70;
    fprintf(fptr, "<line x1=\"100\" y1=\"100\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"4\" stroke-linecap=\"round\" stroke=\"green\"/>", perc_rx, perc_ry);
    // Másodpercmutató (Fekete)
    double mp_rx = 100.0 + cos(PI / 30 * (masodperc - 15)) * 90;
    double mp_ry = 100.0 + sin(PI / 30 * (masodperc - 15)) * 90;
    fprintf(fptr, "<line x1=\"100\" y1=\"100\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"3\" stroke-linecap=\"round\" stroke=\"black\"/></svg>", mp_rx, mp_ry);
    fclose(fptr); 
    return 0;
}