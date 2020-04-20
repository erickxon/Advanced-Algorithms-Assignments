
#include <bits/stdc++.h> 
using namespace std; 
  
  //modified code from:
  //Source: https://www.geeksforgeeks.org/find-k-bookings-possible-given-arrival-departure-times/


int areBookingsPossible(int arrival[], 
                         int departure[], int n) 
{ 
    vector<pair<int, int> > vect; 
  
 
    for (int i = 0; i < sizeof(arrival[0]); i++) { 
        vect.push_back(make_pair(arrival[i], 1)); 
        vect.push_back(make_pair(departure[i], 0)); 
    } 
  
    sort(vect.begin(), vect.end()); 
  
    int curr_active = 0, max_active = 0; 
  
    for (int i = 0; i < vect.size(); i++) { 
        if (vect[i].second == 1) { 
            curr_active++; 
            max_active = max(max_active, 
                             curr_active); 
        } 
        else
            curr_active--; 
    } 
    return (n >= max_active)?1:0; 
} 
  
int main() 
{ 
    int arrival[] = { 1, 3, 5,6,6}; 
    int departure[] = { 2, 6, 8,7,8}; 
    int n = 3; 
    cout << (areBookingsPossible(arrival, departure, n)) << "\n";
    return 0; 
} 
