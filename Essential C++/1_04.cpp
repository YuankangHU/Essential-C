#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
    string user_name;
    bool next_seq = true; //显示下一组数列
    bool go_for_it = true; //用户想再猜一次
    bool got_it = false; //用户是否猜对
    int num_tries = 0; //用户猜过的总次数
    int num_right = 0; //用户答对的总次数
    double user_score = 0.0; //用户得到的分数
    
    const int max_tries = 3;
    
    const int seq_size = 18;
    int elem_seq[seq_size] = {
        1, 2, 3,
        3, 4, 7,
        2, 5, 12,
        3, 6, 18,
        4, 9, 16,
        5, 12, 22
    };
    vector<int> Fibonacci(elem_seq, elem_seq+3); //利用数组创建vector容器，首地址到末地址-1
    vector<int> Lucas(elem_seq+3, elem_seq+6);
    vector<int> Pell(elem_seq+6, elem_seq+9);
    vector<int> Triangular(elem_seq+9, elem_seq+12);
    vector<int> Square(elem_seq+12, elem_seq+15);
    vector<int> Pentagonal(elem_seq+15, elem_seq+18);

    const int max_seq = 6;
    string seq_name[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    
    vector<int> *seq_addrs[max_seq] = {
        &Fibonacci, &Lucas, &Pell, &Triangular, &Square, &Pentagonal
    };
    vector<int> *currrent_vec = 0;
    int seq_index;

    srand(time(NULL)); //以时间作为参数产生随机数种子

    while( next_seq == true )
    {
        seq_index = rand() % max_seq; //随机生成的下标0～5
        currrent_vec = seq_addrs[seq_index]; //将下标传给指针数组
        //为用户显示数列
        cout << "The first 2 elements of the sequence are: " << (*currrent_vec)[0] << ", "<<(*currrent_vec)[1]
        <<endl;
        cout << "What is the next element ?" << '\n'<<"The answer is : ";
        
        int tries_cnt = 0; //猜错的次数
        go_for_it = true;
        got_it = false;
        
        while((got_it == false) && (go_for_it == true) && tries_cnt<max_tries)
        {
            int user_guess;
            std::cin >> user_guess;
            num_tries++;
            tries_cnt++;
            if( user_guess == (*currrent_vec)[2])
            {
                cout << "Very good, yes, " << (*currrent_vec)[2]
                     << " is the next element in the "
                     << seq_name[seq_index] << " sequence." << endl;
                got_it = true;
                num_right++;
            }
            else
            {
                switch (tries_cnt)
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
                cout << "Do you want to try again ? (Y/N) " << '\n' << "The response is: ";
                char user_rsp;
                std::cin >> user_rsp;
                if( user_rsp == 'N' || user_rsp =='n')
                    go_for_it = false; 
                
                else if(tries_cnt == max_tries)
                    cout <<"Sorry, you do not have a chance"<<endl;
                
                else
                    cout<<"The answer is: ";
            }
        }

        cout << "Want to try another sequence ? (Y/N)" << endl;
        char try_again;
        std::cin >> try_again;
        if( try_again == 'N' || try_again =='n')
            next_seq = false;
    }
}