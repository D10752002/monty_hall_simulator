#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    
    int num_doors=3;
    int num_doors_opened_by_host=1;
    int num_simulations=1000;
    
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--num_doors" && i + 1 < argc) {
            num_doors = atoi(argv[++i]);
        } else if (arg == "--num_doors_opened_by_host" && i + 1 < argc) {
            num_doors_opened_by_host = atoi(argv[++i]);
        } else if (arg == "--num_simulations" && i + 1 < argc) {
            num_simulations = atoi(argv[++i]);
        } else {
            cerr << "Wrong arguments: " << arg << endl;
            return 1;
        }
    }
    
    srand(time(0)); 
    
    float total_win_stay=0;
    float total_win_switch=0;
    float lose=0;
    
    for(int j=0;j<num_simulations;j++){
        
        //booleans to represent if current simulation was won or lost
        int win_lose_stay=0;
        int win_lose_switch=0;
        
        vector<int>doors(num_doors, 0);
        // D0 D1 D2 D3 ................ Dn-1
        
        
        int prize_door=rand()%num_doors;
        int initial_contestant_choice=rand()%num_doors;
        
        //set the boolean vector to 1's according to the chosen door and the door behind which we have the prize 
        doors[prize_door]=1;
        doors[initial_contestant_choice]=1;
        
        //randomly choose k doors to open by the host other than the above two doors
        for(int i=0;i<num_doors_opened_by_host; i++){
            int cur_door=rand()%num_doors;
            if(doors[cur_door]) i--;
            else doors[cur_door]=1;
        }
        
        //reset the door behind which the prize is present back to 0
        doors[prize_door]=0;
        doors[initial_contestant_choice]=1
        //randomly switch your choice
        int modified_contestant_choice=rand()%num_doors;
        while(doors[modified_contestant_choice]){
            modified_contestant_choice=rand()%num_doors;
        }
        
        if(prize_door==initial_contestant_choice) win_lose_stay=1;              //whether we won by staying
        else if(prize_door==modified_contestant_choice) win_lose_switch=1;      //whether we won by switching
        
        //if the current simulation was won, increment count
        if(win_lose_stay+win_lose_switch!=0){
            if(win_lose_stay) total_win_stay++;
            else total_win_switch++;
        }else lose++;
        
    }
    
    //output the probabilities
    cout<<"Probability of winning by staying: "<< total_win_stay/num_simulations<<"\t Theoretical probability of winning by staying: 1/N=1"<<"/"<<num_doors<< "=" << 1/(float)num_doors <<endl;
    cout<<"Probability of winning by switching: "<< total_win_switch/num_simulations<<"\t Theoretical probability of winning by switching: N-1/(N*(N-k-1))="<<num_doors-1<<"/"<<(num_doors*(num_doors-num_doors_opened_by_host-1))<<"="<<((float)(num_doors-1))/((float)(num_doors*(num_doors-num_doors_opened_by_host-1)))<<endl;
    return 0;
    
}
