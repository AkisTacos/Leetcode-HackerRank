// Aki Saito
// HackerRank - Easy
// Electronics Shop
// July 19, 2018
// Language: C++
// 
/* Description:

	Monica wants to buy a keyboard and a USB drive from her favorite electronics store. 
	The store has several models of each. 
	Monica wants to spend as much as possible for the 2 items, given her budget.
	
	Given the price lists for the store's keyboards and USB drives, and Monica's budget, 
	find and print the amount of money Monica will spend. 
	If she doesn't have enough money to both a keyboard and a USB drive, print -1 instead. 
	She will buy only the two required items.
	
	For example, suppose she has s = 60 to spend. Three types of keyboards cost keyboards = [40, 50, 60].
	Two USB drives cost drives = [5, 8, 12]. She could purchase a 40 keyboard + 12 USB drive = 52, or a 50 keyboard + 8 USB drive. 
	She chooses the latter. She can't buy more than 2 items so she can't spend exactly 60.

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the getMoneySpent function below.
 */
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    // b is her budget
    // keyboards is the array that contains her prices of keyboards
    // drives is same except for USB drives
    
    int keyCount = keyboards.size();
    int driveCount = drives.size();

    int max = 0;
    int subMax = 0;
    
    for(int i = 0; i < keyCount; i++){
        for(int j = 0; j < driveCount; j++){
            subMax = keyboards[i] + drives[j];
            if(subMax > b) {
                continue;
            }
            if(subMax > max){
                max = subMax;
            }
        }
    }
    (max == 0) ? (max = -1) : (max = max);
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string bnm_temp;
    getline(cin, bnm_temp);

    vector<string> bnm = split_string(bnm_temp);

    int b = stoi(bnm[0]);

    int n = stoi(bnm[1]);

    int m = stoi(bnm[2]);

    string keyboards_temp_temp;
    getline(cin, keyboards_temp_temp);

    vector<string> keyboards_temp = split_string(keyboards_temp_temp);

    vector<int> keyboards(n);

    for (int keyboards_itr = 0; keyboards_itr < n; keyboards_itr++) {
        int keyboards_item = stoi(keyboards_temp[keyboards_itr]);

        keyboards[keyboards_itr] = keyboards_item;
    }

    string drives_temp_temp;
    getline(cin, drives_temp_temp);

    vector<string> drives_temp = split_string(drives_temp_temp);

    vector<int> drives(m);

    for (int drives_itr = 0; drives_itr < m; drives_itr++) {
        int drives_item = stoi(drives_temp[drives_itr]);

        drives[drives_itr] = drives_item;
    }

    /*
     * The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
     */

    int moneySpent = getMoneySpent(keyboards, drives, b);

    fout << moneySpent << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

