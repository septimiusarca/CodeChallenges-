/*
 * 
 * Sam's house has an apple tree and an orange tree that yield an abundance of fruit. 
 * Let's say that the S is the start point, and T is the endpoint. The apple tree is to the left of his house, 
 * and the orange tree is to its right. You can assume the trees are located on a single point, where the apple tree 
 * is at point A, and the orange tree is at point B.
 
 * When a fruit falls from its tree, it lands D units of distance from its tree of origin along the X-axis. 
 * A negative value of  means the fruit fell D units to the tree's left, and a positive value of D means it falls D units 
 * to the tree's right.

 * Given the value of D for M apples and N oranges, determine how many apples and oranges will fall on Sam's house 
 * (i.e., in the inclusive range [S, T])?

 * Function description:

 *   Complete the countApplesAndOranges function in the editor below. It should print the number of apples and 
 *   oranges that land on Sam's house, each on a separate line.

 *   countApplesAndOranges has the following parameter(s):

	s: integer, starting point of Sam's house location.
	t: integer, ending location of Sam's house location.
	a: integer, location of the Apple tree.
	b: integer, location of the Orange tree.
	apples: integer array, distances at which each apple falls from the tree.
	oranges: integer array, distances at which each orange falls from the tree.

 * Input Format

	The first line contains two space-separated integers denoting the respective values of S and T.
	The second line contains two space-separated integers denoting the respective values of A and B.
	The third line contains two space-separated integers denoting the respective values of M and N.
	The fourth line contains M space-separated integers denoting the respective distances that each apple falls from point A.
	The fifth line contains N space-separated integers denoting the respective distances that each orange falls from point B.

 * Output Format

 *  Print two integers on two different lines:

	The first integer: the number of apples that fall on Sam's house.
	The second integer: the number of oranges that fall on Sam's house.

*/


#include <bits/stdc++.h>
#include <ostream>

using namespace std;

vector<string> split_string(string);

// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    // compute where apples are falling;
    int aAppleCount = 0;
    for (auto& aApple : apples) {
        aApple += a;
        if (aApple >= s && aApple <= t) {
            ++aAppleCount;
        }
    }
    cout << aAppleCount<< endl;
    // compute where oranges are falling
    int aOrangeCount = 0;
    for (auto& aOrange : oranges) {
        aOrange += b;
        if (aOrange >= s && aOrange <= t) {
            ++aOrangeCount;
        }
    }
    cout << aOrangeCount << endl;
}

int main()
{
    string st_temp;
    getline(cin, st_temp);

    vector<string> st = split_string(st_temp);

    int s = stoi(st[0]);

    int t = stoi(st[1]);

    string ab_temp;
    getline(cin, ab_temp);

    vector<string> ab = split_string(ab_temp);

    int a = stoi(ab[0]);

    int b = stoi(ab[1]);

    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string apples_temp_temp;
    getline(cin, apples_temp_temp);

    vector<string> apples_temp = split_string(apples_temp_temp);

    vector<int> apples(m);

    for (int i = 0; i < m; i++) {
        int apples_item = stoi(apples_temp[i]);

        apples[i] = apples_item;
    }

    string oranges_temp_temp;
    getline(cin, oranges_temp_temp);

    vector<string> oranges_temp = split_string(oranges_temp_temp);

    vector<int> oranges(n);

    for (int i = 0; i < n; i++) {
        int oranges_item = stoi(oranges_temp[i]);

        oranges[i] = oranges_item;
    }

    countApplesAndOranges(s, t, a, b, apples, oranges);

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
