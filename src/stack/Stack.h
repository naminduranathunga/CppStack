#include <exception>
#include <string>

using namespace std;

class StackUnderFlowException:exception{
    string msg;

    public:
        StackUnderFlowException(string message = "Stack underflow exception"){
            msg = message;
        }

        const char* what() const noexcept {
            return msg.c_str();
        }
};

class StackOverFlowException:exception{
    string msg;
    
    public:
        StackOverFlowException(string message = "Stack overflow exception"){
            msg = message;
        }

        const char* what() const noexcept {
            return msg.c_str();
        }
};

/**
 * @class Stack
 * @brief Stack class allows simple access to a functional stack of any datatype.
 * 
 * usage: Stack s(length);
*/
template <typename T>
class Stack{
    private:
        int top = -1;
        int max = 0;
        T* StackArray;
        bool deleteondelete = true;
        
    public:
        /**
         * @fn Stack
         * @param int max
         *
         * @brief This constructior fro simply use Stack as a new stack object
         * 
        */
        Stack(int max){
            this->max = max;
            StackArray = new T[max];
        }

        /**
         * @fn Stack
         * @param T arr 
         * @param int max
         * 
         * @brief This function overload allows to use an external array of any data type as a stack. 
         * 
         * This function overload allows to use an external array of any data type as a stack. 
         * This is usefull in some operations like reversing an array.
        */
        Stack(T* arr, int max, int top=-2){
            this->max = max;
            StackArray = arr;
            deleteondelete = false;
            if (top == -2){
                this->top = max-1;
            }else{
                this->top = top;
            }
        }

        ~Stack(){
            if (deleteondelete) delete StackArray;
        }

        /**
         * @fn push
         * @param T item 
         * 
         * @brief This function pushes an object to the stack.
         * @throws StackOverFlowException
         * 
        */
        void push(T itm){
            if (top >= max - 1){
                throw new StackOverFlowException();
            }
            top++;
            StackArray[top] = itm;
        }
        
        /**
         * @fn pop
         * 
         * @return T the object at the top.
         * 
         * @brief This function pop (Or return and delete) an object from the stack.
         * @throws StackUnderFlowException
         * 
        */
        T pop(){
            if (top < 0) throw new StackUnderFlowException();
            
            const T tmp = StackArray[top];
            top--;
            return tmp;
        }
        
        /**
         * @fn peek
         * 
         * @return T the object at the top.
         * 
         * @brief This function returns the object from the stack. The value will remaining untill changed.
         * @throws StackUnderFlowException
         * 
        */
        T peek(){
            if (top < 0) throw StackUnderFlowException();
            
            return StackArray[top];
        }

        /**
         * @fn getArray
         * 
         * @return T* of the internal array
         * 
         * @brief This function returns the internal array used by the stack.
         * @throws StackUnderFlowException
         * 
        */
        T* getArray() const {
            return StackArray;
        }


        /**
         * @fn getMax
         * 
         * @return int length of the internal array
         * 
         * @brief If you want to use the internal array in any case, the getMax function will give the length of the array.
         * @throws StackUnderFlowException
         * 
        */
        int getMax() const{
            return max;
        }


        /**
         * @fn getTopIndex
         * 
         * @return const int current index of array
         * 
         * @brief If you want to use the internal array in any case, this function returns the index of the top element
         * 
        */
        int getTopIndex() const{
            return max;
        }
        
};