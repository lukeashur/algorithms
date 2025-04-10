#include <iostream>
using namespace std;

int moves = 0;

void hanoi(int n, char source, char auxiliary, char destination) {   
    
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        moves++;
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    moves++;
    
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    
    int n;
    
    cout << "Enter the number of disks: ";
    cin >> n;

    hanoi(n, 'A', 'B', 'C');
    cout << "Number of moves: " << moves << endl;
    return 0;
}
