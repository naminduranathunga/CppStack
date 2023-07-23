#include<iostream>
#include "stack/Stack.h"

using namespace std;

void printArray(const int* arr, int length){
    cout<<"arr = ["; 
    for (int i = 0; i < length; i++)
    {
        /* code */
        if (i == length - 1){
            cout<<arr[i];
        }else{
            cout<<arr[i]<<", ";
        }
    }
    
    cout<<"]"<<endl;
}


/**
 * @example reversing a list
 * 
 * Stack can be used to revers an array
*/
void ReverseList(){
    //the list
    int list[] = {1, 2, 3, 4, 5};
    int len = 5;
    Stack<int> st(list, len);
    
    //Let's print the array
    printArray(list, len);

    //Now use another stack to store the reverse ordered list
    Stack<int> rlist(len);
    for (int i = 0; i < len; i++){
        rlist.push(st.pop());
    }

    cout<<"Reverse ordered array"<<endl;
    printArray(rlist.getArray(), rlist.getMax());
    cout<<endl<<endl;

}



/**
 * @example Paranthisis checker
*/
bool ValidateParanthisis(string s){
    //stack to store paranthisis
    Stack<char> pr((int)s.size()); //size is defined to the worst case sceario
    
    char tmp;
    //iterating through the string
    for (int i = 0; i < s.size(); i++){
        tmp = s[i];
        //if the tmp is opening of a paranthisis, it is pushed to the stack 
        if (tmp == '[' || tmp == '(' || tmp == '{'){
            pr.push(tmp);
        }else if (tmp == ']' || tmp == ')' || tmp == '}'){
            //if it is a closing paranthesis, 
            try
            {
                /* check for each */
                if ((tmp == ']' && pr.peek() == '[') ||
                        (tmp == ')' && pr.peek() == '(') ||
                        (tmp == '}' && pr.peek() == '{')){
                    pr.pop();
                }else{
                    //missing or incorrect closing paranthesis.
                    return false;
                }

            }
            catch(const StackUnderFlowException& ex)
            {
                //if stack goes unterflow it means an extra closing paranthesis
                //std::cerr << ex.what() << '\n';
                return false;
            }
            
        }
    }

    //if the expression had no error, the top should be -1 which means, pop shoud throw an exception
    try
    {
        /* code */
        pr.peek();
        return false;
    }
    catch(const StackUnderFlowException& ex)
    {
        //this exception means stack is empty
        return true;
    }
}




int main()
{
    ReverseList();
    
    string s = "{(8876(a})}";
    if (ValidateParanthisis(s)){
        cout<<"valid"<<endl;
    }else{
        cout<<"not valid"<<endl;
    }
    return 0;
}