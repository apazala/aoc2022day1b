#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[64];
    int mostCalories[3] = {0};

    FILE *fp = fopen("input.txt", "r");
    if(!fp){
        fprintf(stderr, "Can't open input\n");
        return 1;
    }

    int currCalories = 0;
    char *endptr;
    while (fgets(line, sizeof(line), fp))
    {   
        if(line[0]<'0'){
            if(currCalories > mostCalories[0]){
                mostCalories[2] = mostCalories[1];
                mostCalories[1] = mostCalories[0];
                mostCalories[0] = currCalories;
            } else if(currCalories > mostCalories[1]){
                mostCalories[2] = mostCalories[1];
                mostCalories[1] = currCalories;
            } else if(currCalories > mostCalories[2]){
                mostCalories[2] = currCalories;
            }
            currCalories = 0;
        } else {
            currCalories += strtol(line, &endptr, 10);
        }
    }
    //last elf processing
    if(currCalories > mostCalories[0]){
        mostCalories[2] = mostCalories[1];
        mostCalories[1] = mostCalories[0];
        mostCalories[0] = currCalories;
    } else if(currCalories > mostCalories[1]){
        mostCalories[2] = mostCalories[1];
        mostCalories[1] = currCalories;
    } else if(currCalories > mostCalories[2]){
        mostCalories[2] = currCalories;
    }

    fclose(fp);

    int ans = mostCalories[0]+ mostCalories[1] + mostCalories[2];

    printf("%d\n", ans);
}