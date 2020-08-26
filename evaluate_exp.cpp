//Evaluate the value of an arithmetic expression in Reverse Polish Notation.

//Valid operators are +, -, *, /. Each operand may be an integer or another expression.

/*Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9

Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6*/

    int Solution::evalRPN(vector<string> &A) {
        stack<string>k;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]=="+"||A[i]=="-"||A[i]=="*"||A[i]=="/"){
                int x = stoi(k.top());
                k.pop();
                int y = stoi(k.top());
                k.pop();
                switch(A[i][0])
                {
                    case '+':  k.push(to_string(x + y));break;
                    case '-':  k.push(to_string(y - x));break;
                    case '*':  k.push(to_string(x * y));break;
                    case '/':  k.push(to_string(y / x));break;
                }
            }
            else
                k.push(A[i]);
        }
        return stoi(k.top());
    }
