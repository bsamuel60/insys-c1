#include "model.h"
#include "view.h"

int main()
{
    Model model;
    View view;
    char c;
    pair<string,string> data;
    string s, val;
    bool result;

    do
    {
        view.present("\n\n\tMenu:\n\n");
        view.present("\t1.\tAdd to database\n");
        view.present("\t2.\tLookup\n");
        view.present("\t3.\tReverse lookup\n");
        view.present("\t4.\tDump database\n");
        view.present("\t5.\tDelete entry\n");
        view.present("\tq.\tQuit\n\n\t");

        do
        {
            c = view.getchar();
        }
        while (c == '\n');
        view.getchar();
        view.present("\n");

        switch (c)
        {
        case '1':
            while(true)
            {
                view.present("\tAdd: ");
                data=view.getdata();
                if (data.first == "")
                    break;
                model.write(data);
            } ;
            break;

        case '2':
            view.present("\tKey: ");
            s=view.getstring();
            result=model.get(s,val);
            if (result)
                view.present("\tValue: " + val + "\n");
            else
                view.present("\tNot found!");
            break;

        case '3':
            view.present("\tValue: ");
            val=view.getstring();
            result=model.search(val);
            if (result)
            {
                do
                {
                    result=model.next(data,val);
                    view.present("\tKey:\t" + data.first + " \tValue:\t" + data.second + "\n");
                }
                while (result);
            }
            else
                view.present("\tNot found!");
            break;

        case '4':
            result=model.dump();
            if (result)
                do
                {
                    result=model.next(data);
                    view.present("\tKey:\t" + data.first + " \tValue:\t" + data.second + "\n");
                }
                while (result);
            else
                view.present("\tNo data!");

            break;
        case '5':
            view.present("\tKey: ");
            s=view.getstring();
            result=model.erase(s);
            if (result)
                view.present("\tOK\n");
            else
                view.present("\tNot found!");
            break;
        }
    }
    while (!((c == 'q') || (c == 'Q')));

    return 0;
}
