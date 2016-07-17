#include <stdio.h>


int jolly(int * array, int length, int order){
	int aux = length - 1;
	for(i = 1; i < length; ++i){
		if(array[i] != aux) return 0;
		(order) ? aux-- : aux++;
	}
	return 1;
}

int main(){
	int length, i, pre, in;
	while(scanf("%d", &length) != EOF){
		int dif[length] = {0};
		for(i = 0; i < length; ++i){
			scanf("%d", &in);
			if(i > 0) dif[i] = abs(pre - in);
			pre = in;
		}
		if(jolly(dif, length, (dif[1] < dif[2]) ))
			printf("Jolly\n");
		else printf("Not jolly\n");
		
	}
}