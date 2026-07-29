/*

#include <cstring>
#include <iostream>
using namespace std;

// Length of expressions in characters
const int LEN = 80;

// Size of the stack
const int MAX = 40;

class Stack {
private:
    // Stack: array of characters
    char st[MAX];

    // Number at top of the stack
    int top;

public:
    Stack()
    {
        top = 0;
    }

    // Function to put a character in stack
    void push(char var)
    {
        st[++top] = var;
    }

    // Function to return a character off stack
    char pop()
    {
        return st[top--];
    }

    // Function to get the top of the stack
    int gettop()
    {
        return top;
    }
};

// Expression class
class Express {
private:
    // Stack for analysis
    Stack s;

    // Pointer to input string
    char* pStr;

    // Length of the input string
    int len;

public:
    Express(char* ptr)
    {
        pStr = ptr;
        len = strlen(pStr);
    }

    // Parse the input string
    void parse();

    // Evaluate the stack
    int solve();
};

void Express::parse()
{

    // Character from the input string
    char ch;

    // Last value
    char lastval;

    // Last operator
    char lastop;

    // For each input character
    for (int j = 0; j < len; j++) 
    {
        ch = pStr[j];

        // If it's a digit then save
        // the numerical value
        if (ch >= '0' && ch <= '9')
            s.push(ch - '0');

        // If it's an operator
        else if (ch == '+' || ch == '-'
            || ch == '*' || ch == '/') 
        {

            // If it is the first operator
            // then put it in the stack
            if (s.gettop() == 1)

                s.push(ch);

            // Not the first operator
            else 
            {
                lastval = s.pop();
                lastop = s.pop();

                // If it is either '*' or '/' and the
                // last operator was either '+' or '-'
                if ((ch == '*' || ch == '/')
                    &&(lastop == '+' || lastop == '-'))
                {

                    // Restore the last two pops
                    s.push(lastop);
                    s.push(lastval);
                }

                // In all the other cases
                else 
                {

                    // Perform the last operation
                    switch (lastop) {

                        // Push the result in the stack
                    case '+':
                        s.push(s.pop() + lastval);
                        break;
                    case '-':
                        s.push(s.pop() - lastval);
                        break;
                    case '*':
                        s.push(s.pop() * lastval);
                        break;
                    case '/':
                        s.push(s.pop() / lastval);
                        break;
                    default:
                        cout << "\nUnknown oper";
                        exit(1);
                    }
                }
                s.push(ch);
            }
        }
        else {
            cout << "\nUnknown input character";
            exit(1);
        }
    }
}

int Express::solve()
{
    // Remove the items from stack
    char lastval;
    while (s.gettop() > 1) {
        lastval = s.pop();
        switch (s.pop()) {

            // Perform operation, push answer
        case '+':
            s.push(s.pop() + lastval);
            break;
        case '-':
            s.push(s.pop() - lastval);
            break;
        case '*':
            s.push(s.pop() * lastval);
            break;
        case '/':
            s.push(s.pop() / lastval);
            break;
        default:
            cout << "\nUnknown operator";
            exit(1);
        }
    }
    return int(s.pop());
}

// Driver code
int main()
{

    char string[LEN] = "2+4*5-1";

    // Make expression
    Express* eptr = new Express(string);

    // Parse it
    eptr->parse();

    // Solve the expression
    cout << eptr->solve();

    return 0;
}


*/
// Online C++ compiler to run C++ program online
#include <iostream>
#include  <cstring>
using namespace std;

#define Max 40
#define Length 80
class stack
{
private:
    int top;
    char st[Max];
public:
    stack()
    {
        top = 0;
    }
    void push(char ch1)
    {
        st[top++] = ch1;
    }
    char pop()
    {
        return st[top--];
    }
    int gettop()
    {
        return top;
    }
};
class Express
{
private:
    stack s1;
    int length;
    char* ptr;
public:

    Express(char* ptr1)
    {
        length = strlen(ptr1);
        ptr = ptr1;
    }
    void Parse()
    {
        char ch;
        char lastvalue;
        char lasttop;
        for (int j = 0; j < length; j++)
        {
            ch = ptr[j];
            if (ch > '0' && ch < '9')
            {
                s1.push(ch - '0');
            }
            else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
            {
                if (s1.gettop() == 1)
                    s1.push(ch);

                else
                {
                    lastvalue = s1.pop();
                    lasttop = s1.pop();
                    if ((ch == '*' || ch == '/')
                        && (lasttop == '+' || lasttop == '-'))
                    {
                        s1.push(lasttop);
                        s1.push(lastvalue);
                    }
                    else
                    {
                        switch (lasttop)
                        {
                        case '+':
                            s1.push(s1.pop() + lastvalue);
                            break;
                        case '-':
                            s1.push(s1.pop() - lastvalue);
                            break;
                        case '/':
                            s1.push(s1.pop() / lastvalue);
                            break;
                        case '*':
                            s1.push(s1.pop() * lastvalue);

                        default:
                            break;

                        }

                    }
                    s1.push(ch);
                }

            }

            else
            {

                std::cout << "unrecognised charaters" << std::endl;
            }



        }


    }
    int solve()
    {

        //char ch;
        char lastvalue;
        while (s1.gettop() > 1)
        {
            lastvalue = s1.pop();
            switch (s1.pop())
            {
            case '+':
                s1.push(s1.pop() + lastvalue);
                break;
            case '-':
                s1.push(s1.pop() - lastvalue);
                break;
            case '/':
                s1.push(s1.pop() / lastvalue);
                break;
            case '*':
                s1.push(s1.pop() * lastvalue);

            default:
                break;
            }
        }
        return int(s1.pop());
    }

    void disply()
    {
        while (s1.gettop() > 1)
        {
            std::cout << s1.pop() << " ";
        }
    }
};


int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    char str[Length] = "2+4*4-1";

    Express* exptr = new Express(str);
    //exptr->disply();   
    exptr->Parse();
   // exptr->disply();
    std::cout << exptr->solve() << std::endl;

    return 0;
}