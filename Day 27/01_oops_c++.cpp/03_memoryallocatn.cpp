#include <iostream>
using namespace std;

class agency
{
    int noplate[20];
    int plateprice[20];
    int count;

public:
    void docount(void) { count = 0; }
    void setprice(void);
    void displayprice(void);
};
void agency ::setprice(void)
{
    cout << "THe plate number of " << count + 1 << " is : ";
    cin >> noplate[count];
    cout << "The price of plate number is : ";
    cin >> plateprice[count];
    count++;
}
void agency ::displayprice(void)
{
    for (int i = 0; i < count; i++)
    {
        cout << "The price of number plate " << noplate[i] << " is : " << plateprice[i] << endl;
    }
}

int main()
{
    agency hardik;
    hardik.docount();
    hardik.setprice();
    hardik.setprice();
    hardik.setprice();
    hardik.displayprice();

    return 0;
}