#include <stdio.h>
void dekod(char *de) {
	if (de[0]=='.')
		if (de[1]=='.')
			if (de[2]=='.')
				if (de[3]=='.')
						printf("h");
				else if (de[3]=='-')
						printf("v");
				else
					printf("s");
			else if (de[2]=='-')
				if (de[3]=='.')
						printf("f");
				else
					printf("u");
			else
				printf("i");
		else if (de[1]=='-')
			if (de[2]=='.')
				if (de[3]=='.')
						printf("l");
				else
					printf("r");
			else if (de[2]=='-')
				if (de[3]=='.')
						printf("p");
				else if (de[3]=='-')
						printf("j");
				else
					printf("w");
			else
				printf("a");
		else
			printf("e");
	else if (de[0]=='-')
		if (de[1]=='.')
			if (de[2]=='.')
				if (de[3]=='.')
						printf("b");
				else if (de[3]=='-')
						printf("x");
				else
					printf("d");
			else if (de[2]=='-')
				if (de[3]=='.')
						printf("c");
				else if (de[3]=='-')
						printf("y");
				else
					printf("k");
			else
				printf("n");
		else if (de[1]=='-')
			if (de[2]=='.')
				if (de[3]=='.')
						printf("z");
				else if (de[3]=='-')
						printf("q");
				else
					printf("g");
			else if (de[2]=='-')
					printf("o");
			else
				printf("m");
		else
			printf("t");
	else
		printf("érvénytelen");
}
//A Main függvény, amiben meg lesz hívva a dekod függvény:
int main(){
	dekod(".-");
	dekod(".-..");
	dekod("--");
	dekod(".-");
	return 0;
}
