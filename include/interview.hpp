#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
/* -----------  腾讯六道编程 */
using namespace std;
int inverse_seq(){

    long long unsigned int n,m;
    long long unsigned int res;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        res = n/2 * m;
        cout << res << endl;
    }
    
    return 0;
}

int card_game(){

    long long unsigned int n;
    while(scanf("%d",&n)!=EOF){
        vector<int> card(n);
        for(int i=0;i<n;i++){
            scanf("%d",&card[i]);
        }
        sort(card.begin(),card.end());
        bool niuniu_turn=true;

        int niu_score=0,yang_score=0;

        for(int i=card.size()-1;i>=0;i--){
            if(niuniu_turn){
                niu_score += card[i];
                niuniu_turn = !niuniu_turn;
            }
            else{
                yang_score += card[i];
                niuniu_turn = !niuniu_turn;
            }
        }

        cout << niu_score - yang_score << endl;
    }

    return 0;
}

int max_chocolate(){

    unsigned long long int n,m;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        cout << (m+1-pow(2,n-1)) <<endl;
    }

    

    return 0;
}