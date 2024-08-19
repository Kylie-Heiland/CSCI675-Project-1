#include <vector>
class Solution {
public:
    int secondHighest(string s) {
        unordered_set<char> listOfDigits;
        int largest_digit = -1, second_to_largest = -1; //Holds the second to largest and the largest digits.
        //cout << s[4] << endl << endl;

        //Loop through each of the characters in the string.
        for(int i = 0; i < s.length(); i++){
            //cout << isdigit(s.at(i));
            if( ( isdigit(s[i] ) ) 
            && !( find(listOfDigits.begin(), listOfDigits.end(), s[i]) != listOfDigits.end() ) ){ //If the character is a digit AND it is not already in the array then push the digit onto the vector.
                //cout << s[i] << endl;
                listOfDigits.emplace(s[i]);
                if(s[i] > largest_digit){
                    int temp = largest_digit;
                    largest_digit = s[i];
                    second_to_largest = temp;
                } else if(s[i] > second_to_largest){
                    second_to_largest = s[i];
                }
            }
        }

        //Now that all of the digits are in the vector, sort them in ascending order.
        //sort(listOfDigits.begin(), listOfDigits.end());

        /*for(char e : listOfDigits)
            cout << e << endl;*/
       
        //cout << endl;
        /*if(listOfDigits.size() >= 2){ //If there is at least two digits in the string.
            //cout << listOfDigits.at(listOfDigits.size() - 2);
            //cout << typeid(listOfDigits.at(listOfDigits.size() - 2)).name();
            return listOfDigits.at(listOfDigits.size() - 2) - '0';
        }*/
        if(second_to_largest != -1){
            return second_to_largest - '0';
        }
        //Otherwise, the string has no second largest digit.
        return -1;
    }
};