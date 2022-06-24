#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    bool next_seq = true; //显示下一组数列
    bool go_for_it = true; //用户想再猜一次
    bool got_it = false;
    int num_tries = 0;
    int num_right = 0;
    char user_rsp;

    while( next_seq == true )
    {
        //为用户显示数列
        while((got_it == false) && (go_for_it == true))
        {
            int user_guess;
            cin >> user_guess;
            num_tries++;
            if( user_guess == 1)
            {
                got_it = true;
                num_right++;
            }
            else
            {
                switch (num_tries)
                {
                case 1:
                    std::cout << "Oops, Nice guess but not quite it." << endl;
                    break;
                case 2:
                    std::cout << "Sorry, Wrong a second time!" << endl;
                    break;
                case 3:
                    std::cout << "Ah, this is harder than it looks, isn't it?" << endl;
                    break;
                default:
                    std::cout << "It must be getting pretty frustrating by now!!!" << endl;
                    break;
                }
                cout << "Want to try again the answer ? " << endl;
                cin >> user_rsp;
                if( user_rsp == 'N' || user_rsp =='n')
                    go_for_it = false; 
            }
        }

        cout << "Want to try another sequence ? (Y/N)" << endl;
    }
}