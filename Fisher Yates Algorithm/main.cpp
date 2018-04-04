
//  fisher_yates
//  Selects unique numbers from given range

//

#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int main()
{
    int selection_range = 100;  // Selection range is for numbers 1 - 100
    int number_selections = 5;  // Number of random selections = 5
    
    // Array full of possible selections
    int selections_remaining[selection_range];
    for (int i=0; i<selection_range; i++)
        selections_remaining[i] = i+1;
    
    // Array of selections made
    int selections_made[number_selections];
    
    // Seed rand() function with time
    srand (time(NULL));
    
    // Make selections and place in array of selection made
    
    for (int i=0; i<number_selections; i++)
    {
        int selectionLocation = rand() % selection_range;
        selections_made[i] = selections_remaining[selectionLocation];
        swap(selections_remaining[selectionLocation], selections_remaining[(selection_range-1)]);
        --selection_range;
        cout << selections_made[i] << endl;  // Output selections
    }
    
    
    
    return 0;
}
