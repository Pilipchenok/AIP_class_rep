#include <iostream>

bool isPyth(unsigned a, unsigned b, unsigned c);
int main(){
    using u_t = unsigned;
    size_t count = 0;
    u_t a = 0, b = 0, c = 0;
    while(std::cin >> a){
        count += isPyth(a, b, c);
        c = b;
        b = a;
    }
    if(std::cin.eof()){
        if(count == 0){
            std::cout << 0;
            return 0;
        }
        std::cout << count;
        return 0;
    }
    if(std::cin.fail()){
        std::cerr << "Input error";
        return 1;
    }
}

bool isPyth(unsigned a, unsigned b, unsigned c){
    bool p = a * a == b * b + c * c;
    p = p || b * b == a * a + c * c;
    p = p || c * c == b * b + a * a;
    return p;
}