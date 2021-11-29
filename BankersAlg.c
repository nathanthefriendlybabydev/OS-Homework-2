#include <stdio.h>
#include <stdbool.h>

struct process_info{
    int max[10];
    int allocated[10];
    int need[10];
};

int no_of_process,no_of_resources;
char buffer[100];
char toInt[3];

//tabular form
void showTheInfo(struct process_info process[no_of_process]){
    printf("PID\tMaximum\t\tAllocated\tNeed\n");
    for(int i=0;i<no_of_process;++i){
        printf("P[%d]\t",i);
        for(int j=0;j<no_of_resources;++j)
            printf("%d ",process[i].max[j]);
        printf("\t\t");
        for(int j=0;j<no_of_resources;++j)
            printf("%d ",process[i].allocated[j]);
        printf("\t\t");
        for(int j=0;j<no_of_resources;++j)
            printf("%d ",process[i].need[j]);
        printf("\n");
    }
}

bool applySafteyAlgo(struct process_info process[no_of_process],int available[no_of_resources],int safeSequence[no_of_process]){
    bool finish[no_of_process];
    int work[no_of_resources];
    for(int i=0;i<no_of_resources;++i){
        work[i]=available[i];
    }
    for(int i=0;i<no_of_process;++i)
        finish[i]=false;
    bool proceed=true;
    int k=0;
    while(proceed){
        proceed=false;
        for(int i=0;i<no_of_process;++i){
            bool flag=true;
            //find index i

            if(finish[i]==false){
                for(int j=0;j<no_of_resources;++j){
                    //if need <= work
                    if(process[i].need[j] <= work[j]){
                        continue;
                    }    
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==false)
                    continue;
                for(int j=0;j<no_of_resources;++j)
                    work[j]=work[j] + process[i].allocated[j];
                finish[i]=true;
                safeSequence[k++]=i;
                proceed=true; 
            }
        }
    }
    int i;
    for(i=0;i<no_of_process&&finish[i]==true;++i){
        continue;
    }
    if(i==no_of_process)
        return true;
    else 
        return false;
}

bool isSafeState(struct process_info process[no_of_process],int available[no_of_resources],int safeSequence[no_of_process]){
    if(applySafteyAlgo(process,available,safeSequence)==true)
        return true;
    return false;
}

int main()
{

    FILE *file;
    file = fopen("input.txt", "r");
    fscanf(file,"%d",&no_of_process);

    fscanf(file,"%d",&no_of_resources);

    int available[no_of_resources];
    int safeSequence[no_of_process];
    struct process_info process[no_of_process];
    for(int i =0;i<no_of_process;++i){
        for(int j=0;j<no_of_resources;++j){
            fscanf(file,"%d",&process[i].max[j]);
        }
        for(int j=0;j<no_of_resources;++j){
            fscanf(file,"%d",&process[i].allocated[j]);
            process[i].need[j] = process[i].max[j] - process[i].allocated[j];
        }
    }
    for(int i=0;i<no_of_resources;++i){
        fscanf(file,"%d",&available[i]);
    }
    fclose(file);

    showTheInfo(process);
    if(isSafeState(process,available,safeSequence)){
        printf("System is in SAFE State\n");
        printf("Safe Sequence is: ");
        for(int i=0;i<no_of_process;++i)
            printf("P[%d] ",safeSequence[i]);
    }
    else
        printf("System is in UNSAFE State\n");
    return 0;
}
