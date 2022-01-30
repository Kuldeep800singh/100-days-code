#include<iostream>

bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = x;
        int palidrom = 0;
        while(temp > 0){
            int lastdigit = temp%10;
            palidrom= (palidrom*10)+lastdigit;
            temp=temp/10;
        }
        std::cout << palidrom << std::endl;
        if(palidrom == x)
            return true;
        return false;
}
int main(){
    std::cout << isPalindrome(123) << std::endl;
    std::cout << isPalindrome(121) << std::endl;
    std::cout << isPalindrome(222) << std::endl;
    std::cout << isPalindrome(11) << std::endl;
    return 0;
}

