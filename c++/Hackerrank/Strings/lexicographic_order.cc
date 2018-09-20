// Jack and Daniel are friends. Both of them like letters, especially upper-case ones. 
// They are cutting upper-case letters from newspapers, and each one of them has his collection of letters stored in a stack.

// One beautiful day, Morgan visited Jack and Daniel. He saw their collections. He wondered what is the lexicographically minimal string made of those two collections. He can take a letter from a collection only when it is on the top of the stack. Morgan wants to use all of the letters in their collections.

// As an example, assume Jack has collected  and Daniel has . Assembling the string would go as follows:

// Jack	Daniel	Result
// ACA	BCF
// CA	BCF	A
// CA	CF	AB
// A	CF	ABC
// A	CF	ABCA
//     	F	ABCAC
//     		ABCACF
// Note the choice when there was a tie at CA and CF.

// Input Format

// The first line contains the an integer , the number of test cases.

// The next  pairs of lines are as follows: 
// - The first line contains string  
// - The second line contains string .

// Constraints

//  and  contain upper-case letters only, ascii[A-Z].
// Output Format

// Output the lexicographically minimal string  for each test case in new line.

// Sample Input

// 2
// JACK
// DANIEL
// ABACABA
// ABACABA
// Sample Output

// DAJACKNIEL
// AABABACABACABA
// Explanation

// The first letters to choose from were J and D since they were at the top of the stack. D was chosen, the options then were J and A. A chosen. Then the two stacks have J and N, so J is chosen. (Current string is DAJ) Continuing this way till the end gives us the resulting string.


#include <iostream>
#include <iterator>
#include <string>

// Complete the morganAndString function below.
std::string morganAndString(const std::string& a, const std::string& b) {
    std::string combined_string;
    std::string::const_iterator si_a;
    std::string::const_iterator si_b = b.begin();
    for (si_a = a.begin(); si_a < a.end(); si_a++) {
        while (si_b < b.end() && *si_b < *si_a) {
            combined_string += *si_b;
            si_b++;
        }
        combined_string += *si_a;
    }
    while (si_b < b.end()) {
        combined_string += *si_b;
        si_b++;
    }
    return combined_string;
}

int main()
{
	std::string test_lh = "MIKESMELLSFUNNY";
	std::string test_rh = "LMAOYEAHRIGHT";
	std::cout << morganAndString(test_lh, test_rh);
    return 0;
}
