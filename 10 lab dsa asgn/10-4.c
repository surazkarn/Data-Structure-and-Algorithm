//4.In a party of N people, only one person is known to everyone. Such a
//person may be present in the party, if yes, (s)he doesn’t know anyone in
//the party. We can only ask questions like “does A know B? “. WAP to
//find the stranger (celebrity) in minimum number of questions.


#include <stdio.h>

int main(){
    int N;    
    scanf("%d",&N);
    int ans;    
    int l = 1, r = N;
    int frnds;
    while(l < r){                
        printf("Does %d know %d ? (1 - Yes, 0 - No) : ",l,r);
        scanf("%d",&frnds);
        if(frnds){
            l++;            
        }
        else{
            r--;
        }        
    }
    ans = l;
    for(int i =1 ; i<= N ; i++){
        if(i != l){
            printf("Does %d know %d ? (1 - Yes, 0 - No) : ",l,i);
            scanf("%d",&frnds);
            int bk = frnds;
            printf("Does %d know %d ? (1 - Yes, 0 - No) : ",i,l);
            scanf("%d",&frnds);
            if(bk && !frnds){
                ans = -1;
                break;
            }
        }
    }
    printf("Stranger : %d\n",ans);

    return 0;
}