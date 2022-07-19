#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <stack>
#include <sstream>
using namespace std;

//Class #1
class Evaluate {
private:
    static int counter;
    float operand1, operand2, rez;

public:
    //Default constructor
    Evaluate() : operand1(counter++)
    {
        this->operand1 = 0.0f;
        this->operand2 = 0.0f;
        this->rez = 0.0f;
    }

    //Constructor with parameters
    Evaluate(float operand1, float operand2, float rez) : operand1(counter++)
    {
        this->operand1 = operand1;
        this->operand2 = operand2;
        this->rez = rez;
        Evaluate::counter = 1;
    }

    //Getters and setters
    int getOperand1()
    {
        return this->operand1;
    }
    void setOperand1(int value) {
        if (value >= -10000000000 && value <= 10000000000000) {
            this->operand1 = value;
        }
        else {
            throw exception("Please insert a value between -10000000000 and 10000000000000");
        }
    }

    int getOperand2()
    {
        return this->operand2;
    }
    void setOperand2(int value2) {
        if (value2 >= -10000000000 && value2 <= 10000000000000) {
            this->operand2 = value2;
        }
        else {
            throw exception("Please insert a number between -10000000000 and 10000000000000");
        }
    }

    int getResult()
    {
        return this->rez;
    }
    void setResult(int value3) {
        if (value3 >= -10000000000 && value3 <= 900000000000000000) {
            this->rez = value3;
        }
        else {
            throw exception("Please insert a value between -10000000000 and 900000000000000000");
        }
    }

    //<<, >>, >=, ! operators 
    friend ostream& operator<<(ostream& out, const Evaluate ev)
    {
        out << ev.operand1 << " ";
        out << ev.operand1 << " ";
        out << ev.rez << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Evaluate& ev)
    {
        cout << "Operand 1:";
        in >> ev.operand1;
        cout << "Operand 2:";
        in >> ev.operand1;
        cout << "Result :";
        in >> ev.rez;
        return in;
    }

    bool operator>=(Evaluate ev)
    {
        return this->rez > ev.rez;
    }

    bool operator!()
    {
        bool negative = 0;
        if (this->rez > 0)
        {
            negative = 0;
        }
        else
        {
            negative = 1;
        }
        return negative;
    }

    //Methods
    float EvaluateOperator(vector <string>& v) {
        string operator1 = v[2];
        string operator2 = v[0];
        string operator3 = v[1];

        istringstream istringstr, istringstrea;
        istringstr.str(operator1); istringstrea.str(operator3);
        istringstr >> operand1;
        istringstrea >> operand2;
        if (operator2 == "+")
        {
            rez = operand1 + operand2;
            return rez;
        }
        else if (operator2 == "-")
        {
            rez = operand1 - operand2;
            return rez;
        }
        else if (operator2 == "*")
        {
            rez = operand1 * operand2;
            return rez;
        }
        else if (operator2 == "/")
        {
            rez = operand1 / operand2;
            return rez;
        }
        else if (operator2 == "^")
        {
            rez = pow(operand1, operand2);
            return rez;
        }
        else if (operator2 == "#")
        {
            rez = pow(operand1, 1.0 / operand2);
            return rez;
        }
    }

    //Virtual method #1
   virtual bool CheckIfItIsOperand(char check) {
        if (((check >= '0') && (check <= '9')) || (check == 'm') || (check == 'n') || (check == '.'))
            return true;
        else
            return false;
    }

   //Virtual method #2
   virtual bool CheckIfItIsOperator(char check) {
        if ((check == '+') || (check == '-') || (check == '*') || (check == '/') || (check == '^') || (check == '#'))
            return true;
        else
            return false;
    }


    bool CheckIfItIsNumber(char check) {
        if (((check >= '0') && (check <= '9')) || (check == '.'))
            return true;
        else
            return false;
    }

    bool CheckPriority(char FirstOperator, char SecondOperator) {
        if (FirstOperator == '(')
            return false;
        else if (SecondOperator == '(')
            return false;
        else if (SecondOperator == ')')
            return true;
        else if (FirstOperator == '[')
            return false;
        else if (SecondOperator == '[')
            return false;
        else if (SecondOperator == ']')
            return true;
        else if ((FirstOperator == '[') && (SecondOperator == '('))
            return true;
        else if ((FirstOperator == ')') && (SecondOperator == ']'))
            return true;
        else if ((SecondOperator == ']') && (SecondOperator == '^'))
            return true;
        else if ((SecondOperator == ']') && (SecondOperator == '#'))
            return true;
        else if ((FirstOperator == '^') && (SecondOperator == '^'))
            return false;
        else if (FirstOperator == '^')
            return true;
        else if (SecondOperator == '^')
            return false;
        else if ((FirstOperator == '#') && (SecondOperator == '#'))
            return false;
        else if (FirstOperator == '#')
            return true;
        else if (SecondOperator == '#')
            return false;
        else if ((FirstOperator == '*') || (FirstOperator == '/'))
            return true;
        else if ((SecondOperator == '*') || (SecondOperator == '/'))
            return false;
        else
            return true;
    }

};
int Evaluate::counter = 1;


//Class #2
class ExceptionandVerification
{
private:
    string error_message = "";
    string values = "0123456789+-*/^#()[].";
    int no = 0;

public:
    //Default constructor
    ExceptionandVerification()
    {
        this->error_message = "";
        this->values = "0123456789+-*/^#()[].";
        this->no = 0;
    }

    //Constructor with parameters
    ExceptionandVerification(const string& message) : error_message(message) {
        this->error_message = error_message;
        this->values = values;
        this->no = no;
    }

    //Getters and setters
    string getErrorMessage() {
        return this->error_message;
    }

    void setErrorMessage(string error_message) {
        if (error_message != "") {
            this->error_message = error_message;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }

    string getValues() {
        return this->values;
    }
    void setValues(string values) {
        if (values != "0123456789+-*/^#()[].") {
            this->values = values;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }

    int getNo()
    {
        return this->no;
    }
    void setNo(int value) {
        if (value >= 0) {
            this->no = value;
        }
        else {
            throw exception("Please insert a valid value");
        }
    }

    //<<, >>, <, ++ operators 
    friend ostream& operator<<(ostream& out, const ExceptionandVerification ex)
    {
        out << ex.error_message << " ";
        out << ex.values << " ";
        out << ex.no << " ";
        return out;
    }

    friend istream& operator>>(istream& in, ExceptionandVerification& ex)
    {
        cout << "Error message:";
        in >> ex.error_message;
        cout << "Values:";
        in >> ex.values;
        cout << "Length :";
        in >> ex.no;
        return in;
    }

    bool operator<(ExceptionandVerification ex)
    {
        return this->no < ex.no;
    }

    ExceptionandVerification& operator ++()
    {
        if (this->no > 0)
        {
            this->no++;
        }
        return *this;
    }

    //Methods
    static void throwException() {
        throw(ExceptionandVerification("Please write a valid equation"));
    }

    bool isValid(string comp) {
        for (int i = 0; i < comp.length(); i++)
        {
            if ((comp[i] == '+') || (comp[i] == '-'))
            {
                if ((comp[i + 1] == '+') || (comp[i + 1] == '-'))
                {
                    return false;
                }
            }
        }
        for (int i = 0; i < comp.length(); i++)
        {
            for (int j = 0; j < values.length(); j++)
            {
                if (comp[i] == values[j])
                {
                    no++;
                }
            }
        }
        if (no == comp.length())
        {
            return true;
        }
        else {
            return false;
        }
    }
};


//Class #3, abstract interface with pure virtual method
 class Menu {
public:

    //pure virtual method
    virtual void getOptions() = 0;	
};


//Class #4
class Stack : public Evaluate {

private:
    int noSpaces = 0;
    string str = "";
    string s = "";
    string token = "";
    float d = 0.0f;
    int l = 0;
    char TopComponent;
    char Component;
    vector <string> values;
    vector <string> temp;
    stack <char> Stack1;
    stack <string> Stack2;

public:
    //Default constructor
    Stack()
    {
        this->noSpaces = 0;
        this->str = "";
        this->s = "";
        this->token = "";
        this->d = 0.0f;
        this->l = 0;
        this->TopComponent = NULL;
        this->Component = NULL;
    }

    //Constructor with parameters
    Stack(int noSpaces, string str, string s, string token, float d, int l, char TopComponent, char Component,
        vector <string> values, vector <string> temp, stack <char> Stack1, stack <string> Stack2) : noSpaces(noSpaces)
    {
        this->noSpaces = noSpaces;
        this->str = str;
        this->s = s;
        this->token = token;
        this->d = d;
        this->l = l;
        this->TopComponent = TopComponent;
        this->Component = Component;
        this->values = values;
        this->temp = temp;
        this->Stack1 = Stack1;
        this->Stack2 = Stack2;
    }

    //Getters and setters
    int getNoSpaces()
    {
        return this->noSpaces;
    }
    void setNoSpaces(int value) {
        if (value > 0) {
            this->noSpaces = value;
        }
        else {
            throw exception("Please insert a valud value");
        }
    }
    string getStr() {
        return this->str;
    }
    void setStr(string str) {
        if (str != "") {
            this->str = str;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }
    string getS() {
        return this->s;
    }
    void setS(string s) {
        if (s != "") {
            this->s = s;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }
    string getToken() {
        return this->token;
    }
    void setToken(string token) {
        if (token != "") {
            this->token = token;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }
    float getD()
    {
        return this->d;
    }
    void setD(float value) {
        if (value > 0) {
            this->d = value;
        }
        else {
            throw exception("Please insert a valud value");
        }
    }
    int getL()
    {
        return this->l;
    }
    void setL(int value) {
        if (value > 0) {
            this->l = value;
        }
        else {
            throw exception("Please insert a valud value");
        }
    }
    char getTopComponent() {
        return this->TopComponent;
    }
    void setTopComponent(char* TopComponent) {
        if (strlen(TopComponent) > 3) {
            this->str = TopComponent;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }
    char getComponent() {
        return this->Component;
    }
    void setComponent(char* Component) {
        if (strlen(Component) > 3) {
            this->str = Component;
        }
        else {
            cout << "Invalid! Please write a value" << endl;
        }
    }

    //<<, >> operator
    friend ostream& operator<<(ostream& out, const Stack st)
    {
        out << st.noSpaces << " ";
        out << st.str << " ";
        out << st.s << " ";
        out << st.token << " ";
        out << st.d << " ";
        out << st.l << " ";
        out << st.TopComponent << " ";
        out << st.Component << " ";
        out << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Stack& st)
    {
        cout << "No Spaces:";
        in >> st.noSpaces;
        cout << "Token:";
        in >> st.token;
        return in;
    }

    //Methods
    void ConvertingfromInfix(const string& Infix, string& Postfix) {
        for (l = 0; l < Infix.size(); l++)
        {
            Component = Infix[l];
            if (CheckIfItIsOperand(Component))
                Postfix = Postfix + Component;
            else
            {
                while ((!Stack1.empty()) &&
                    (CheckPriority(Stack1.top(), Component)))
                {
                    TopComponent = Stack1.top();
                    Stack1.pop();
                    Postfix = Postfix + TopComponent;
                }
                if ((!Stack1.empty()) && (Component == ')'))
                    Stack1.pop();
                else
                    Stack1.push(Component);
            }
        }
        while (!Stack1.empty())
        {
            TopComponent = Stack1.top();
            Stack1.pop();
            Postfix = Postfix + TopComponent;
        }
    }

    void Find(string comp) {
        for (int j = 0; j < comp.length(); j++)
        {
            if (comp[j] == ' ')
            {
                noSpaces++;
            }
        }
        istringstream iss(comp);
        while (getline(iss, token, ' '))
        {
            values.push_back(token);
        }
        for (int i = 0; i < noSpaces; i++)
        {
            str = values[i];
            if ((str != "+") && (str != "*") && (str != "-") && (str != "^") && (str != "/") && (str != "#"))
            {
                Stack2.push(str);
            }
            else
            {
                Stack2.push(str);
                for (int i = 0; i < 3; i++)
                {
                    temp.push_back(Stack2.top());
                    Stack2.pop();
                }
                d = EvaluateOperator(temp);
                ostringstream outs;
                outs << d;
                s = outs.str();
                Stack2.push(s);
                temp.clear();
            }
        }
        cout << s;
    }
};


//Class #6
class Input : public Evaluate, public ExceptionandVerification, public Stack, public Menu {

private:
    const int id;
    char* infixExpression = NULL;

public:
    string z;
    //Default constructor
    Input() : id(1)
    {
        this->infixExpression = new char[strlen("Unknown") + 1];
        strcpy(this->infixExpression, "Unknown");
    }

    //Constructor with parameters
    Input(const char* infixExpression) : id(id)
    {
        if (strlen(infixExpression) > 3) {
            this->infixExpression = new char[strlen(infixExpression) + 1];
            strcpy(this->infixExpression, infixExpression);
        }
    }

    //Getters and setters
    const int getId()
    {
        return this->id;
    }

    char* get()
    {
        return this->infixExpression;
    }

    void set(const char* infixExpression) {
        {
            if (strlen(infixExpression) > 3)
            {
                if (this->infixExpression != NULL)
                {
                    delete[] this->infixExpression;
                }
                this->infixExpression = new char[strlen(infixExpression) + 1];
                strcpy(this->infixExpression, infixExpression);
            }
        }
    }

    virtual void getOptions() {
        cout << "options" << endl;
    }

    //Copy constructor
    Input(const Input& cp) : id(cp.id)
    {
        this->infixExpression = new char[strlen(cp.infixExpression) + 1];
        strcpy(this->infixExpression, cp.infixExpression);
    }

    //Destructor
    ~Input() {
        if (this->infixExpression != NULL)
        {
            delete[] this->infixExpression;
        }
    };

    //Equals operator
    Input& operator=(const Input& inp)
    {
        if (this != &inp)
        {
            if (this->infixExpression != NULL)
            {
                delete[]this->infixExpression;
            }
            this->infixExpression = new char[strlen(inp.infixExpression) + 1];
            strcpy(this->infixExpression, inp.infixExpression);
            return *this;
        }
    }



    //<<, >>, ==, explicit cast  operators
    friend ostream& operator<<(ostream& out, const Input inp)
    {
        out << inp.infixExpression << " ";
        out << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Input& inp)
    {
        if (inp.infixExpression != NULL)
        {
            delete[]inp.infixExpression;
        }
        cout << "Add the imput of the equation:";
        in >> ws;
        char aux[250];
        in.getline(aux, 249);
        inp.infixExpression = new char[strlen(aux) + 1];
        strcpy(inp.infixExpression, aux);
        return in;
    }


    bool operator==(Input in)
    {
        return this->infixExpression == in.infixExpression;
    }

    explicit operator string()
    {
        return this->infixExpression;
    }


    //Methods
    string Change(string comp) {
        for (int i = 0; i < comp.length(); i++)
        {
            if (Evaluate::CheckIfItIsNumber(comp[i]) == true)
            {
                if (Evaluate::CheckIfItIsNumber(comp[i + 1]) == false)
                {
                    comp.insert(i + 1, "m");
                }
            }
        }
        for (int i = 0; i < comp.length(); i++)
        {
            if (comp[i] == '-')
            {
                if ((comp[i - 1] != 'm') && (comp[i - 1] != ')'))
                {
                    comp.replace(i, 1, "n");
                }
            }
        }
        return comp;
    }

    string InsertSpaceAfterOperator(string comp) {
        for (int i = 0; i < comp.length(); i++)
        {
            if (Evaluate::CheckIfItIsOperator(comp[i]) == true)
            {
                comp.insert(i + 1, " ");
            }
            else if (comp[i] == 'm')
            {
                comp.replace(i, 1, " ");
            }
        }
        for (int i = 0; i < comp.length(); i++)
        {
            if (comp[i] == 'n')
            {
                comp.replace(i, 1, "-");
            }
        }
        return comp;
    }

    void Result() {
        string postfixExpression;
        string temp;
        string z;

        if (isValid(infixExpression) == true)
        {
            temp = Change(infixExpression);
            ConvertingfromInfix(temp, postfixExpression);
            z = InsertSpaceAfterOperator(postfixExpression);
            cout << "\nThe result of the equation is\n";
            Find(z);
        }
        else
        {
            try {
                throwException();
            }
            catch (ExceptionandVerification& e) {
                cout << "" << e.getErrorMessage() << endl;
            }
        }
    }


    void serializare(string fileName)
    {
        ofstream binaryFile(fileName, ios::out, ios::binary);
        int infixExpressionLength = strlen(this->infixExpression);
        binaryFile.write((char*)&infixExpressionLength, sizeof(infixExpressionLength));
        binaryFile.write(this->infixExpression, infixExpressionLength + 1);
        binaryFile.close();
    }

    void deserializare(string fileName)
    {
        ifstream binaryFile(fileName, ios::in, ios::binary);
        if (binaryFile.is_open())
        {
            if (this->infixExpression != NULL)
            {
                delete[] this->infixExpression;
            }
            int infixExpressionLength = 0;
            binaryFile.read((char*)&infixExpressionLength, sizeof(infixExpressionLength));
            this->infixExpression = new char[infixExpressionLength + 1];
            binaryFile.read(this->infixExpression, infixExpressionLength + 1);
            binaryFile.close();
        }
        else
        {
            cout << "The file was not found!";
        }

    }

};
