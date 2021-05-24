#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int forwardSteps, backwardSteps, forwardDitch, backwardDitch, time;
    scanf("%d%d%d%d%d",&forwardSteps, &backwardSteps, &forwardDitch, &backwardDitch, &time);
    if(forwardSteps>0 && backwardSteps>0 && forwardDitch>0 && backwardDitch>0 && time>0)
    {
        backwardDitch = -backwardDitch;
        if(forwardSteps == backwardSteps)       printf("NO");
        else if(forwardSteps >= forwardDitch)    printf("F %d",forwardDitch * time);
        else
        {
            int totalStepCount = 0, position = 0;
            while(1)
            {
                if(position + forwardSteps >= forwardDitch)
                {
                    printf("F %d",(totalStepCount + forwardDitch - position) * time);
                    break;
                }
                else
                {
                    position = position + forwardSteps;
                    totalStepCount = totalStepCount + forwardSteps;
                }
                if(position - backwardSteps <= backwardDitch)
                {
                    printf("B %d",(totalStepCount - backwardDitch + position) * time);
                    break;
                }
                else
                {
                    position = position - backwardSteps;
                    totalStepCount = totalStepCount + backwardSteps;
                }
            }
        }
    }
    return 0;
}
