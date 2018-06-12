#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct fd
{
    int health;
    int attack;
    fd(int h, int a) : health(h), attack(a) {}
};

vector<fd> player[2];

int main() 
{
    int N;
    cin >> N;
    int pid = 0;
    player[0].push_back(fd(30, 0));
    player[1].push_back(fd(30, 0));
    for(int n=0; n<N; n++) 
	{
        string type;
        cin >> type;
        if(type == "summon") 
		{
            int pos, h, a;
            cin >> pos >> a >> h;
            player[pid].insert(player[pid].begin()+pos, fd(h, a));
        }
        else if(type == "attack") 
		{
            int att, deff;
            cin >> att >> deff;
            player[pid][att].health -= player[!pid][deff].attack;
            player[!pid][deff].health -= player[pid][att].attack;
            if(player[pid][att].health <= 0 && att!=0) 
			{
                player[pid].erase(player[pid].begin()+att);
            }
            if(player[!pid][deff].health <= 0 && deff!=0) 
			{
                player[!pid].erase(player[!pid].begin()+deff);
            }
        }
        else if(type == "end") 
		{
            pid = !pid;
        }
    }
    if(player[0][0].health>0 && player[1][0].health>0) cout << 0 << endl;
    else if(player[0][0].health>0) cout << 1 << endl;
    else cout << -1 << endl;
    for(int i=0; i<2; i++) 
	{
        cout << player[i][0].health << endl;
        cout << player[i].size()-1 << " ";
        for(int j=1; j<player[i].size(); j++) 
		{
            cout << player[i][j].health << " ";
        }
        cout << endl;
    }
}
