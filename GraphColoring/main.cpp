#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 int i,k,N,M,aCount,aColor_Count, T, ColorNumer ;


      cin >> N >> M;
     cout<<"N, M is "<<N <<" "<< M<< endl ;


        int *S = new int [N];
        int *UL = new int [M];
        int *UR = new int [M];
        for(i = 0; i < N; i++ )
        {
            S[i] = -1;//default coloring
        }

        for(i = 0; i < M; i++ )
        {
            cin >> UL[i] >> UR[i];//input rebra
        }

               for(int i = 0; i < M; i++ )
        {
            cout << UL[i] << UR[i] << endl;//input rebra
        }

        ColorNumer=0;
        S[0] = ColorNumer;
        cout<<"UZEL_"<<0<<" Color:" <<S[0]<< endl;

        aCount = 1;

     while (aCount<N)
    {
        for(i = 1; i < N; i++)
        if(S[i] == -1 )
          {   T=0;
              for (k= 0; k<M; k++)
               if (((UL[k] ==i) && (S[UR[k]]== ColorNumer)) ||
                   ((UR[k] ==i) && (S[UL[k]]== ColorNumer)))
                   {
                       T=1;
                    }
             if (T==0)
             {
                S[i]=ColorNumer;
                cout<<"UZEL_"<<i<<" Color:" <<S[i]<< endl;
                aCount++;
             }
          }
        ColorNumer++;
         cout<<"Color:" <<ColorNumer<< endl;
   }
        cout<<"Answer "<<ColorNumer<<endl<<"to exit type int !=0";
        int exit = 0;
        while(exit!=0){
        cin>>exit;}


}

