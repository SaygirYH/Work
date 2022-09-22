#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;             //number of pairs
    int pw = 2;        //because of pow() func
    int minimum=999999999,calc,hold,buf,flag,last,g
        ,sum=0;
    int mas[85905][2]; //pairs of X and Y
    int ban[85905];    //Banned pair, volume should be similar as mas[]
    cin >> N;

   // int x1,x2,y1,y2;
    //cin >> x1 >> y1 >> x2 >> y2;
   // cout<< sqrt(pow(x1-x2,pw)+pow(y1-y2,pw)); // distance calculation

    for(int i=0; i<N; i++)
        {
            ban[i]=0;
        };

    for(int i=0; i<N; i++)
        {
            cin >> mas[i][1] >> mas[i][2];
        };

    for(int j=0; j<N; j++)
    {

            flag = 0;
            hold = minimum;
            for(int i=0; i<N; i++)
            {
                if((i!=j)&&(ban[i]!=1))
                {
                    calc = sqrt( pow(mas[j][1]-mas[i][1], pw) + pow(mas[j][2]-mas[i][2], pw) );
                    if (flag == 0){buf = calc; flag++;last = i;}
                   // cout<<"calculated to"<<calc<<endl;
                    if(calc < hold)
                        {
                            hold = calc;cout<<"minimum changed to "<<hold<<endl;
                            last = i; cout<<"LAST = "<<last<<endl;
                           // flag++;
                        }
                }

            }
            if(ban[last]!=1)
                {
                sum=sum+hold; cout<<"sum ++ =  "<< sum<<endl;
                }
                ban[last]=1; cout<<"Last banned is "<<last<<endl;
    }
    calc = sqrt( pow(mas[0][1]-mas[N-1][1], pw) + pow(mas[0][2]-mas[N-1][2], pw) );

    cout<<"= = = = = = = = = = =  main result = "<< sum+calc<<endl;
    while(g!=0){cin>> g;}
    cout << "done";
    return 0;
}

//ending = sqrt( pow(mas[0][1]-mas[N-1][1], pw) + pow(mas[0][2]-mas[N-1][2], pw) ); //first and last

/*
input example
5
0 0
0 1
1 0
1 1
0.5 0
*/
