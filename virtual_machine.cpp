#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>

using namespace std;

enum Instructions
{
    MOV,
    ADD,
    MUL,
    PRN,
    HLT
};
class vm
{
private:
    int ins_ptr = 0;
    std::array<int, 10> reg = {};
    bool running_status = true;
    vector<int> Program{
        MOV, 4, 5,
        MOV, 0, 7,
        ADD, 0, 1, 2,
        PRN, 2,
        HLT};
    int fetch()
    {
        return Program[ins_ptr];
    }
    void eval(int instr)
    {
        if (instr == HLT)
        {
            running_status = false;
            cout << "Exit!!" << endl;
        }
        else if (instr == MOV)
        {
            int dest = Program.at(++ins_ptr);
            int val = Program.at(++ins_ptr);
            reg.at(dest) = val;
        }
        else if (instr == ADD)
        {
            int r1 = Program[++ins_ptr];
            int r2 = Program[++ins_ptr];
            int r3 = Program.at(++ins_ptr);
            reg.at(r3) = r1 + r2;
        }
        else if (instr == PRN)
        {
            cout << reg.at(Program[++ins_ptr]) << endl;
        }
        else
        {
            throw runtime_error("Unknown error on " + to_string(instr));
        }
        // cout << "done" << " ";
    }

public:
    void run()
    {
        while (running_status)
        {
            int instruction = fetch();
            eval(instruction);
            ins_ptr++;
        }
    }
};
int main()
{
    try
    {
        vm virtual_machine;
        virtual_machine.run();
    }
    catch (const out_of_range &e)
    {
        cerr << "Register Error " << e.what() << endl;
    }
    return 0;
}