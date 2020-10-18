#include <iostream>
#include <vector> 
using namespace std;

class TowerOfHanoi {
    private:
        vector<char> a, b, c; // rods a,b,c
        int total_num_of_disks;
    public:
        TowerOfHanoi(int n):total_num_of_disks(n){
            for (int i = 0; i < total_num_of_disks; i++){
                a.emplace_back(i+1+'0');
                b.emplace_back(' ');
                c.emplace_back(' ');
            } 
            a.emplace_back('a');
            b.emplace_back('b');
            c.emplace_back('c');
            tower_of_hanoi(total_num_of_disks, a, c, b);
        }

        void move_disk(int n, vector<char>& from, vector<char>& to){
            printf("Disk %d is moved from rod %c to %c\n",n, 
                    from[total_num_of_disks], to[total_num_of_disks]);
            char disk_number = n + '0';
            
            for (int i = total_num_of_disks - 1; i >= 0; i--)
                if (from[i] == disk_number){
                   from[i] = ' '; 
                   break;
                }

            for (int i = total_num_of_disks - 1; i >= 0; i--)
                if (to[i] == ' '){
                    to[i] = disk_number;
                    break;
                } 
        }

        void tower_of_hanoi(int n, vector<char>& start_rod, vector<char>& dest_rod,
                vector<char>& aux_rod){
            if (n == 1){
                move_disk(n, start_rod, dest_rod);
                display_disk_positions();
                return;
            }
            tower_of_hanoi(n-1, start_rod, aux_rod, dest_rod);
            move_disk(n, start_rod, dest_rod);
            display_disk_positions();
            tower_of_hanoi(n-1, aux_rod, dest_rod, start_rod);
        }

        void display_disk_positions(){
            for (int i = 0; i < total_num_of_disks; i++)
                printf("[%c]\t[%c]\t[%c]\n",a[i],b[i],c[i]);
        }
};

void towerVisualized(int total_num_of_disks, vector<char>& start_rod, vector<char>& dest_rod, 
        vector<char>& aux_rod){
    if (total_num_of_disks == 1){
        start_rod[0] = ' ';
        dest_rod[0] = total_num_of_disks + '0'; 
    }
}

int main(){
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    TowerOfHanoi toh(n);
}
