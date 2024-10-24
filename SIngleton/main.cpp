#include <iostream>

using namespace std;

class htb{
    private:
        htb() = default;
        static htb limit;
    public:
        static htb & Limit();

        int sum(int a , int b){
            return a + b;
        }
};

htb htb::limit;
htb & htb::Limit(){
    return limit;
}

int main(){
    
    htb &test = htb::Limit();
    cout << test.sum(3, 4);
}