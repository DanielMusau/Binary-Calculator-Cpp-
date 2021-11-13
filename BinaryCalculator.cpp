// A Binary Number Calculator
// Daniel Musau

#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

using namespace std;

void menu();

int grade();

bool is_binary(string b);

bool test_binary_to_decimal();

bool test_decimal_to_binary();

bool test_add_binaries();

int binary_to_decimal(string s) {
    int decimal_value = 0, i;

    //initial value of base
    int base_value = 1;
    int length_of_s = s.length();
    for (i = length_of_s - 1; i >= 0; i--) {
        if (s[i] == '1') {
            decimal_value = decimal_value + base_value;
        }
        base_value *= 2;
    }
    return decimal_value;
}


string decimal_to_binary(int n) {
    string binary_num = "";
    int binary_number[40], i = 0, j;

    //The updated
    if (n == 0)
        return"0";

    while (n > 0) {
        //we store the remainder in array
        binary_number[i] = n%2;
        //we divide the number
        n = n/2;
        i++;
    }
    //in order to get the binary number, the array has to be reversed
    for (j = (i-1); j >= 0; j--) {
        //concating to form a string 
        std::string string_data;

        //declaration of string stream
        std::stringstream ss;

        ss << binary_number[j];
        
        //This converts the data to string
        string_data = ss.str();

        //concating to form a string of binary
        binary_num += string_data;
    }
    return binary_num;
}


string add_binaries(string b1, string b2) {
    //implementing this to store result of addition
    string add_result = "";

    //Storing the sum of digits
    int sum_of_digits = 0, len_of_b1, len_of_b2;
    len_of_b1 = b1.size() - 1;
    len_of_b2 = b2.size() - 1;
    while (len_of_b1 >= 0 || len_of_b2 >= 0 || sum_of_digits == 1) {
        //finding the sum of two digits
        if (len_of_b1 >= 0) {
            sum_of_digits += b1[len_of_b1] - '0';
        }
        else {
            sum_of_digits += 0;
        }

        if (len_of_b2 >= 0) {
            sum_of_digits += b2[len_of_b2] - '0';
        }
        else {
            sum_of_digits += 0;
        }

        //calculated sum is 3 or 1,so concatenation of the result is
        add_result = char(sum_of_digits % 2 + '0') + add_result;

        //Find the carry
        sum_of_digits = sum_of_digits / 2;

        //decrement len_of_b1 and len_of_b2 to go to next digits
        len_of_b1--;
        len_of_b2--;
    }
    return add_result;
}



int main()
{
    int choice;
    string b1, b2;
    int x, score;
    do {
        // display menu
        menu();
        cout << "Enter you choice: ";
        cin >> choice;
        // based on choice to perform tasks
        switch (choice) {
        case 1:
            cout << "Enter a binary string: ";
            cin >> b1;
            if (!is_binary(b1))
                cout << "It is not a binary number\n";
            else
                cout << "Its decimal value is: " << binary_to_decimal(b1) << endl;
            break;

        case 2:
            cout << "Enter a positive integer: ";
            cin >> x;
            if (x <= 0)
                cout << "It is not a positive integer" << endl;
            else
                cout << "Its binary representation is: " << decimal_to_binary(x) << endl;
            break;

        case 3:
            cout << "Enter two binary numbers, separated by white space: ";
            cin >> b1 >> b2;
            if (!is_binary(b1) || !is_binary(b2))
                cout << "At least one number is not a binary" << endl;
            else
                cout << "The sum is: " << add_binaries(b1, b2) << endl;
            break;
            
        case 4:
        	score=grade();
			break;


        case 5:
            cout << "Thanks for using binary calculator program. Good-bye" << endl;
            break;
        default:
            cout << "Wrong choice. Please choose 1-5 from menu" << endl;
            break;
        }

    } while (choice != 5);
    return 0;
}


void menu()
{
    cout << "******************************\n";
    cout << "*          Menu              *\n";
    cout << "* 1. Binary to Decimal       *\n";
    cout << "* 2. Decimal to Binary       *\n";
    cout << "* 3. Add two Binaries        *\n";
    cout << "* 4. Grade                   *\n";
    cout << "* 5. Quit                    *\n";
    cout << "******************************\n";
}


int grade() {
    int result = 0;
    // binary_to_decimal function worth 3 points
    if (test_binary_to_decimal()) {
        cout << "binary_to_decimal function passed the test" << endl;
        result += 3;
    }
    else
        cout << "binary_to_decimal function failed" << endl;

    // decinal_to_binary function worth 2 points
    if (test_decimal_to_binary()) {
        cout << "decimal_to_binary function passed the test" << endl;
        result += 2;
    }
    else
        cout << "decimal_to_binary function failed" << endl;
    // add_binaries function worth 3 points
    if (test_add_binaries()) {
        cout << "add_binaries function passed the test" << endl;
        result += 3;
    }
    else
        cout << "add_binaries function passed failed" << endl;
    return result;
}

bool is_binary(string s) {
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '0' && s[i] != '1') // one element in s is not '0' or '1'
            return false;  // then it is not a binary nunber representation
    return true;
}

bool test_binary_to_decimal() {
    if (binary_to_decimal("0") != 0 || binary_to_decimal("1") != 1)
        return false;
    if (binary_to_decimal("010") != 2 || binary_to_decimal("10") != 2)
        return false;
    if (binary_to_decimal("01101") != 13 || binary_to_decimal("1101") != 13)
        return false;
    return true;
}

bool test_decimal_to_binary() {
    if (decimal_to_binary(0) != "0" || decimal_to_binary(1) != "1")
        return false;
    if (decimal_to_binary(2) != "10" || decimal_to_binary(13) != "1101")
        return false;
    return true;
}

bool test_add_binaries() {
    if (add_binaries("0", "0") != "0") return false;
    if (add_binaries("0", "110101") != "110101") return false;
    if (add_binaries("1", "110111") != "111000") return false;
    if (add_binaries("101", "111011") != "1000000") return false;
    return true;
}
