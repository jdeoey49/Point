#include<iostream>
using namespace std;
class Point
{
    friend ostream& operator<<(ostream& oref, const Point& pref);
    friend istream& operator>>(istream& iref, Point& pref);
    private:
    int x_;
    int y_;
};
ostream& operator<<(ostream& oref, const Point& pref)
{
    oref<<"("<<pref.x_<<", "<<pref.y_<<")\n";
    return oref;
}
istream& operator>>(istream& iref, Point& pref)
{
    if(iref.peek()!='(')
    {
        iref.clear(ios::failbit);
    }
    else
    {
        iref.ignore();//skip (
        iref>>pref.x_;
        if(iref.peek()!=',')
        {
            iref.clear(ios::failbit);
        }
        else
        {
            iref.ignore();//skip ','   
            if(iref.peek()!=' ')
            {
                iref.clear(ios::failbit);
            }
            else
            {
                iref.ignore();//skip whitespace
                iref>>pref.y_;
                if(iref.peek()!=')')
                {
                    iref.clear(ios::failbit);
                }
                else
                {
                    iref.clear();//skip )
                }
            }
        }
    }
    return iref;
}
int main()
{
    Point pt;
    cout<<"Enter a point in the form (x, y):\n";
    cin>>pt;//store user entered point
    if(!cin.fail())
    {
        cout<<"Point enter was: "<<pt<<endl;
    }
    else
    {
        cout<<"\nInvalid data\n";//tell user invalid data was entered
    }//end main
}


