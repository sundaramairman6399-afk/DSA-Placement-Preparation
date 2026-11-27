
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        // Count the available $5 and $10 bills
        int five = 0;
        int ten = 0;

        // Process customers one by one
        for(int i = 0; i < bills.size(); i++) {

            // CASE 1: Customer pays with $5
            // No change is required
            if(bills[i] == 5) {
                five++;
            }

            // CASE 2: Customer pays with $10
            // We must return $5 as change
            else if(bills[i] == 10) {

                if(five > 0) {
                    five--;  // Give one $5 bill
                    ten++;   // Receive one $10 bill
                }
                else {
                    return false; // Cannot provide change
                }
            }

            // CASE 3: Customer pays with $20
            // We must return $15 as change
            else {

                // Prefer giving one $10 and one $5
                // This preserves our $5 bills
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // Otherwise, give three $5 bills
                else if(five >= 3) {
                    five -= 3;
                }

                // No possible way to return $15
                else {
                    return false;
                }
            }
        }

        // Every customer received correct change
        return true;
    }
};
