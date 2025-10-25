#include <iostream>
#include <limits>

bool isPyth(unsigned a, unsigned b, unsigned c);
int overflow_check(unsigned a, unsigned b, unsigned c);
int main(){
    using u_t = unsigned;
    size_t count = 0;
    u_t a = 0, b = 0, c = 0;
    while(std::cin >> a){
        int q = overflow_check(a, b, c);
        if(q == 0){
            count += isPyth(a, b, c);
            c = b;
            b = a;
        }else if(q == 2){
            return 2;
        }
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
        std::cerr << "Input error\n";
        return 1;
    }
}

bool isPyth(unsigned a, unsigned b, unsigned c){
    bool p = a * a == b * b + c * c;
    p = p || b * b == a * a + c * c;
    p = p || c * c == b * b + a * a;
    return p;
}

int overflow_check(unsigned a, unsigned b, unsigned c){
    unsigned max_square = std::sqrt(std::numeric_limits<unsigned>::max());
    unsigned max = std::numeric_limits<unsigned>::max();
    if(a <= max_square && b <= max_square && c <= max_square){
        if((a * a + b * b <= max) && (a * a + c * c <= max) && (c * c + b * b <= max)){
            return 0;
        }
        if(std::cin.fail()){
            std::cerr << "Overflow error";
            return 2;
        }
    }else{
        std::cerr << "Overflow error";
        return 2;
    }
    return 0;
}