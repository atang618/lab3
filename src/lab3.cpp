#include "eecs230.h"
// Converts feet to centimeters,
// allows for multiple numbers to be input in one line.
void convert() {
    vector<double> a,v;
    double x;
    cout << "Enter lengths in inches (stop with '0'): \n";
    while ((cin >> x) && x !=0) {
        a.push_back(x);
        x = x * 2.54;
        v.push_back(x);
    }
    unsigned long length=v.size();
    for (int i=0; i<length; ++i) {
        cout << a[i] << " inches is " << v[i] << " cm. \n";
    }
}

// Detects whether or not the inputted word is a word
// you don't like, and if it is, it will censor it out
void censor() {
    vector<string> a;
    string input,censor;
    cout << "Enter a sentence (end with a 0): \n";
    while ((cin >> input) && input !="0") {
        a.push_back(input);
    }
    cout << "Which word would you like to censor? \n";
    cin >> censor;
    unsigned long length=a.size();
    for (int i=0; i<length; ++i) {
        if (a[i] == censor)
            a[i] = "[censored]";
        cout << a[i] << " ";
    }
    cout <<".";
}

// Quadratic equation solver program that will output the roots if they are real.
vector<double> quadform(double a, double b, double c) {
    if (pow(b,2)-4*a*c < 0)
        error("Roots will be imaginary");
    vector<double> answer(2);
    double root1, root2;
    root1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    root2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    answer[0] = root1;
    answer[1] = root2;
    return answer;
}

/* The main function, or the "entry function" of the lab3 program, simply calls the other
 * functions to run.
 */
int main() {
    convert();
    censor();
    cout << "Enter the coefficients: \n";
    double a, b, c;
    cin >> a >> b >> c;
    vector<double> answer = quadform(a, b ,c);
    cout << "The roots are " << answer[0] << " and " << answer[1];

    return 0; // Lets the operating system know everything ran successfully.
}

